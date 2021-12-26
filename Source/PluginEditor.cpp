#include "PluginProcessor.h"
#include "PluginEditor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sliders LookAndFeel
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BigRotaryLookAndFeel::drawRotarySlider(juce::Graphics& g,
	int x, int y, int width, int height,
	float sliderPosProportional, 
	float rotaryStartAngle,
	float rotaryEndAngle,
	juce::Slider& slider)
{
	using namespace juce;
	auto bounds = Rectangle<float>(x, y, width, height);
	auto sliderAngleRadian = jmap(sliderPosProportional, 0.0f, 1.0f, rotaryStartAngle, rotaryEndAngle);
	auto offset = 4;
	auto circleBounds = Rectangle<float>(bounds.getX() + offset,
		bounds.getY() + offset,
		bounds.getWidth() - 2 * offset,
		bounds.getHeight() - 2 * offset);
	
	//Get Sine / Cosine
	float s, c;
	c = cos(-sliderAngleRadian);
	s = sin(-sliderAngleRadian);

	//Calculate Indicator
	float x0, x1, x2, y0, y1, y2;
	x0 = circleBounds.getCentreX();
	y0 = circleBounds.getCentreY();
	x1 = 0;
	y1 = 0;
	
	float r = 25;
	x2 = -r * s;
	y2 = -r * c;

	x1 = x1 + x0;
	y1 = y1 + y0;
	x2 = x2 + x0;
	y2 = y2 + y0;
	
	//Draw
	g.setColour(Colours::white);
	g.drawLine(x1,y1,x2,y2, 4);
	g.drawEllipse(circleBounds, 4);
}

void CustomRotary::paint(juce::Graphics& g)
{
	using namespace juce;
	auto startAngleRadian = degreesToRadians(180.0f + 45.0f);
	auto endAngleRadian = degreesToRadians(180.0f - 45.0f) + MathConstants<float>::twoPi;
	auto range = getRange();
	auto sliderBounds = getSliderBounds();

	

	g.setColour(Colours::yellow);
	//g.drawRect(sliderBounds);

	getLookAndFeel().drawRotarySlider(g,
								      sliderBounds.getX(), 
								      sliderBounds.getY(),
								      sliderBounds.getWidth(),
								      sliderBounds.getHeight(),
								      jmap(getValue(), range.getStart(), range.getEnd(), 0.0, 1.0),
								      startAngleRadian,
								      endAngleRadian,
								      *this);
}
juce::Rectangle<int> CustomRotary::getSliderBounds() const
{
	return getLocalBounds();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Response Curve
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ResponseCurveComponent::ResponseCurveComponent(PlasmaAudioProcessor& p) : audioProcessor(p)
{
	//Listen to parameter changes
	const auto& params = audioProcessor.getParameters();
	for (auto param : params)
	{
		param->addListener(this);
	}
	startTimer(60);
}

ResponseCurveComponent::~ResponseCurveComponent()
{
	const auto& params = audioProcessor.getParameters();
	for (auto param : params)
	{
		param->removeListener(this);
	}
}

void ResponseCurveComponent::parameterValueChanged(int parameterIndex, float newValue)
{
	parametersChanged.set(true);
}

void ResponseCurveComponent::timerCallback()
{
	if (parametersChanged.compareAndSetBool(false, true))
	{
		update();
	}
}

void ResponseCurveComponent::update()
{
	//Update Monochain
	auto chainSettings = getChainSettings(audioProcessor.apvts);

	//Coefficients
	auto highPassCoefficients = makeHighPassFilter(chainSettings, audioProcessor.getSampleRate());
	auto highPassResonanceCoefficients = makeHighPassResonance(chainSettings, audioProcessor.getSampleRate());
	auto peakCoefficients = makePeakFilter(chainSettings, audioProcessor.getSampleRate(), 0.0);
	auto lowPassResonanceCoefficients = makeLowPassResonance(chainSettings, audioProcessor.getSampleRate());
	auto lowPassCoefficients = makeLowPassFilter(chainSettings, audioProcessor.getSampleRate());

	//Updates
	updatePassFilter(monoChain.get<ChainPositions::HighPass>(), highPassCoefficients, chainSettings.highPassSlope);
	updateCoefficients(monoChain.get<ChainPositions::HighPassResonance>().coefficients, highPassResonanceCoefficients);
	updateCoefficients(monoChain.get<ChainPositions::Peak>().coefficients, peakCoefficients);
	updateCoefficients(monoChain.get<ChainPositions::LowPassResonance>().coefficients, lowPassResonanceCoefficients);
	updatePassFilter(monoChain.get<ChainPositions::LowPass>(), lowPassCoefficients, chainSettings.lowPassSlope);

	//Repaint
	repaint();
}

void ResponseCurveComponent::paint(juce::Graphics& g)
{
	using namespace juce;

	//Screen
	auto x = sl(10);
	auto y = sl(10);
	auto w = sl(600);
	auto h = sl(300);

	//g.setColour(Colours::black);
	//g.fillRect(x, y, w, h);
	auto& highpass = monoChain.get<ChainPositions::HighPass>();
	auto& highpassResonance = monoChain.get<ChainPositions::HighPassResonance>();
	auto& peak = monoChain.get<ChainPositions::Peak>();
	auto& lowpass = monoChain.get<ChainPositions::LowPass>();
	auto& lowpassResonance = monoChain.get<ChainPositions::LowPassResonance>();

	auto sampleRate = audioProcessor.getSampleRate();

	std::vector<double> mags;
	mags.resize(w);
	for (int i = 0; i < w; ++i)
	{
		//Magnitude
		double mag = 1.f;
		auto freq = mapToLog10(double(i) / double(w), 20.0, 20000.0);

		//Highpass
		if (!highpass.isBypassed<0>())
			mag *= highpass.get<0>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!highpass.isBypassed<1>())
			mag *= highpass.get<1>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!highpass.isBypassed<2>())
			mag *= highpass.get<2>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!highpass.isBypassed<3>())
			mag *= highpass.get<3>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!highpass.isBypassed<4>())
			mag *= highpass.get<4>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!highpass.isBypassed<5>())
			mag *= highpass.get<5>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!highpass.isBypassed<6>())
			mag *= highpass.get<6>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!highpass.isBypassed<7>())
			mag *= highpass.get<7>().coefficients->getMagnitudeForFrequency(freq, sampleRate);

		//Highpass Resonance
		if (!monoChain.isBypassed<ChainPositions::HighPassResonance>())
			mag *= highpassResonance.coefficients->getMagnitudeForFrequency(freq, sampleRate);

		//Peak
		if (!monoChain.isBypassed<ChainPositions::Peak>())
			mag *= peak.coefficients->getMagnitudeForFrequency(freq, sampleRate);

		//Lowpass
		if (!lowpass.isBypassed<0>())
			mag *= lowpass.get<0>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!lowpass.isBypassed<1>())
			mag *= lowpass.get<1>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!lowpass.isBypassed<2>())
			mag *= lowpass.get<2>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!lowpass.isBypassed<3>())
			mag *= lowpass.get<3>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!lowpass.isBypassed<4>())
			mag *= lowpass.get<4>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!lowpass.isBypassed<5>())
			mag *= lowpass.get<5>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!lowpass.isBypassed<6>())
			mag *= lowpass.get<6>().coefficients->getMagnitudeForFrequency(freq, sampleRate);
		if (!lowpass.isBypassed<7>())
			mag *= lowpass.get<7>().coefficients->getMagnitudeForFrequency(freq, sampleRate);

		//Lowpass Resonance
		if (!monoChain.isBypassed<ChainPositions::LowPassResonance>())
			mag *= lowpassResonance.coefficients->getMagnitudeForFrequency(freq, sampleRate);

		//Write
		mags[i] = Decibels::gainToDecibels(mag);
	}

	Path responseCurve;
	const double outputMin = y + h;
	const double outputMax = y;
	auto map = [outputMin, outputMax](double input)
	{
		return jmap(input, -48.0, 48.0, outputMin, outputMax);
	};

	responseCurve.startNewSubPath(x, map(mags.front()));
	for (size_t i = 1; i < mags.size(); ++i)
	{
		responseCurve.lineTo(x + i, map(mags[i]));
	}
	g.setColour(Colours::white);
	g.strokePath(responseCurve, PathStrokeType(3));

}

//preGainSlider(*audioProcessor.apvts.getParameter("Pre Gain"), "db"),
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Editor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PlasmaAudioProcessorEditor::PlasmaAudioProcessorEditor(PlasmaAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p),
	//Pregain
	preGainSlider(*audioProcessor.apvts.getParameter("Pre Gain"), "dB", "Gain"),
	driveSlider(*audioProcessor.apvts.getParameter("Drive"), "x", "Drive"),
	girthSlider(*audioProcessor.apvts.getParameter("Girth"), "%", "Girth"),
	biasSlider(*audioProcessor.apvts.getParameter("Bias"), "", "Symmetry"),
	driveTypeSlider(*audioProcessor.apvts.getParameter("Distortion Type"), "", "Distortion"),
	//Highpass
	highPassFreqSlider(*audioProcessor.apvts.getParameter("Highpass Freq"), "Hz", "Highpass"),
	highPassResonanceSlider(*audioProcessor.apvts.getParameter("Highpass Resonance"), "dB", "Resonance"),
	highPassResonanceQualitySlider(*audioProcessor.apvts.getParameter("Highpass Resonance Q"), "", "Q"),
	highPassSlopeSlider(*audioProcessor.apvts.getParameter("Highpass Slope"), "dB/oct", "Slope"),
	//Peak
	peakStereoSlider(*audioProcessor.apvts.getParameter("Peak Stereo"), "Hz", "Stereo"),
	peakFreqSlider(*audioProcessor.apvts.getParameter("Peak Freq"), "Hz", "Peak"),
	peakGainSlider(*audioProcessor.apvts.getParameter("Peak Gain"), "dB", "Resonance"),
	peakQualitySlider(*audioProcessor.apvts.getParameter("Peak Quality"), "", "Q"),
	//Lowpass
	lowPassFreqSlider(*audioProcessor.apvts.getParameter("Lowpass Freq"), "Hz", "Lowpass"),
	lowPassResonanceSlider(*audioProcessor.apvts.getParameter("Lowpass Resonance"), "dB", "Resonance"),
	lowPassResonanceQualitySlider(*audioProcessor.apvts.getParameter("Lowpass Resonance Q"), "", "Q"),
	lowPassSlopeSlider(*audioProcessor.apvts.getParameter("Lowpass Slope"), "dB/oct", "Slope"),
	//Lategain
	gainSlider(*audioProcessor.apvts.getParameter("Gain"), "dB", "Gain"),
	lateDriveSlider(*audioProcessor.apvts.getParameter("Late Drive"), "x", "Drive"),
	lateGirthSlider(*audioProcessor.apvts.getParameter("Girth"), "%", "Girth"),
	lateBiasSlider(*audioProcessor.apvts.getParameter("Late Bias"), "", "Symmetry"),
	lateDriveTypeSlider(*audioProcessor.apvts.getParameter("Late Distortion Type"), "", "Distortion"),
	mixSlider(*audioProcessor.apvts.getParameter("Mix"), "%", "Mix"),
	analyserSlider(*audioProcessor.apvts.getParameter("Analyser Type"), "%", "Analyser Type"),
	//ResponseCurve
	responseCurveComponent(audioProcessor),
	//Attachments
	preGainSliderAttachment(audioProcessor.apvts, "Pre Gain", preGainSlider),
    driveTypeSliderAttachment(audioProcessor.apvts, "Distortion Type", driveTypeSlider),
    girthSliderAttachment(audioProcessor.apvts, "Girth", girthSlider),
    driveSliderAttachment(audioProcessor.apvts, "Drive", driveSlider),
    biasSliderAttachment(audioProcessor.apvts, "Bias", biasSlider),
    highPassResonanceSliderAttachment(audioProcessor.apvts, "Highpass Resonance", highPassResonanceSlider),
    highPassResonanceQualitySliderAttachment(audioProcessor.apvts, "Highpass Resonance Q", highPassResonanceQualitySlider),
    highPassFreqSliderAttachment(audioProcessor.apvts, "Highpass Freq", highPassFreqSlider),
	highPassSlopeSliderAttachment(audioProcessor.apvts, "Highpass Slope", highPassSlopeSlider),
    //Peak
	peakStereoSliderAttachment(audioProcessor.apvts, "Peak Stereo", peakStereoSlider),
	peakFreqSliderAttachment(audioProcessor.apvts, "Peak Freq", peakFreqSlider),
    peakGainSliderAttachment(audioProcessor.apvts, "Peak Gain", peakGainSlider),
    peakQualitySliderAttachment(audioProcessor.apvts, "Peak Q", peakQualitySlider),
    lowPassFreqSliderAttachment(audioProcessor.apvts, "Lowpass Freq", lowPassFreqSlider),
    lowPassSlopeSliderAttachment(audioProcessor.apvts, "Lowpass Slope", lowPassSlopeSlider),
    lowPassResonanceQualitySliderAttachment(audioProcessor.apvts, "Lowpass Resonance Q", lowPassResonanceQualitySlider),
    lowPassResonanceSliderAttachment(audioProcessor.apvts, "Lowpass Resonance", lowPassResonanceSlider),
    lateBiasSliderAttachment(audioProcessor.apvts, "Late Bias", lateBiasSlider),
    lateDriveTypeSliderAttachment(audioProcessor.apvts, "Late Distortion Type", lateDriveTypeSlider),
	lateGirthSliderAttachment(audioProcessor.apvts, "Late Girth", lateGirthSlider),
	lateDriveSliderAttachment(audioProcessor.apvts, "Late Drive", lateDriveSlider),
	gainSliderAttachment(audioProcessor.apvts, "Gain", gainSlider),
	mixSliderAttachment(audioProcessor.apvts, "Mix", mixSlider),
	analyserSliderAttachment(audioProcessor.apvts, "Analyser Type", analyserSlider)

{
    //Loading Resources
    Image screenImage = ImageCache::getFromMemory(BinaryData::Screen_png, BinaryData::Screen_pngSize);
	
    if (!screenImage.isNull())
    {
        screenImageComponent.setImage(screenImage, RectanglePlacement::doNotResize);
    } 


	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
	}
	tooltipLabel.setText("Tooltip", juce::dontSendNotification);
	addAndMakeVisible(tooltipLabel);
    addAndMakeVisible(screenImageComponent);

	setResizable(false, false);
    setSize(1060, 940);
  }

PlasmaAudioProcessorEditor::~PlasmaAudioProcessorEditor()
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Draw
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlasmaAudioProcessorEditor::paint (juce::Graphics& g)
{
    using namespace juce;
    //Background 2e2f31
    //g.fillAll(Colour(46, 47, 49));
	g.fillAll(Colour(20, 20, 20));
	g.drawImageAt(backgroundImage, 0, 0);
       
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Layout
/////////////////////////////////////////////////W///////////////////////////////////////////////////////////////////

void PlasmaAudioProcessorEditor::resized()
{
	//Analyzers
	responseCurveComponent.setBounds(220, 60, 620, 300);
	responseCurveComponent.update();

    //Early
    preGainSlider.setBounds(80, 140, 60, 60);
	driveTypeSlider.setBounds(80, 460, 60, 60);
	biasSlider.setBounds(80, 580, 60, 60);
    girthSlider.setBounds(80, 700, 60, 60);
	driveSlider.setBounds(80, 820, 60, 60);
	

    //Highpass
	highPassSlopeSlider.setBounds(290, 460, 60, 60);
	highPassResonanceQualitySlider.setBounds(290, 580, 60, 60);
	highPassResonanceSlider.setBounds(290, 700, 60, 60);
	highPassFreqSlider.setBounds(290, 820, 60, 60);

    //Peak
	peakStereoSlider.setBounds(500, 460, 60, 60);
	peakQualitySlider.setBounds(500, 580, 60, 60);
	peakGainSlider.setBounds(500, 700, 60, 60);
	peakFreqSlider.setBounds(500, 820, 60, 60);
	

    //Lowpass
	lowPassSlopeSlider.setBounds(710, 460, 60, 60);
	lowPassResonanceQualitySlider.setBounds(710, 580, 60, 60);
	lowPassResonanceSlider.setBounds(710, 700, 60, 60);
	lowPassFreqSlider.setBounds(710, 820, 60, 60);
   
	//Latedrive
	gainSlider.setBounds(920, 140, 60, 60);
	lateDriveTypeSlider.setBounds(920, 460, 60, 60);
	lateBiasSlider.setBounds(920, 580, 60, 60);
	lateGirthSlider.setBounds(920, 700, 60, 60);
	lateDriveSlider.setBounds(920, 820, 60, 60);

	//ToolTip
	tooltipLabel.setBounds(30, 0, 200, 60);

	//Mix
	mixSlider.setBounds(920, 260, 60, 60);
	analyserSlider.setBounds(80, 260, 60, 60);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Misc
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<juce::Component*> PlasmaAudioProcessorEditor::getComps()
{
    return
    {
        &gainSlider,
        &driveSlider,
        &girthSlider,
        &biasSlider,
        &lateBiasSlider,
        &highPassSlopeSlider,
        &highPassFreqSlider,
        &highPassResonanceSlider,
        &highPassResonanceQualitySlider,
		&peakStereoSlider,
        &peakFreqSlider,
        &peakGainSlider,
        &peakQualitySlider,
        &lowPassSlopeSlider,
        &lowPassFreqSlider,
		&lowPassResonanceSlider,
		&lowPassResonanceQualitySlider,
		&lateGirthSlider,
		&lateDriveSlider,
		&preGainSlider,
		&driveTypeSlider,
		&lateDriveTypeSlider,
		&responseCurveComponent,
		&mixSlider,
		&analyserSlider
    };
}

