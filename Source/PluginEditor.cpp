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
	
	int imgIndex = 0;

	if(slider.getSkewFactor() == 1.0)
	{
		imgIndex = jmap(sliderPosProportional, 0.0f, 94.0f);
	}
	else
	{
		NormalisableRange<float> targetRange{ 0, 94.0f };
		targetRange.setSkewForCentre(65);
		imgIndex = ceil(targetRange.convertFrom0to1(sliderPosProportional));
	}

	g.drawImage(rotaryBaseImage, bounds, RectanglePlacement::onlyReduceInSize, false);
	g.drawImage(indicatorImage[imgIndex], bounds, RectanglePlacement::onlyReduceInSize, false);
	g.setColour(Colours::white);
	
	if(slider.getTextValueSuffix() == "Hz")
	{
		g.setFont(20.0f);
		g.drawText(slider.getName(), bounds, juce::Justification::centredBottom, true);
		bounds.setBottom(bounds.getBottom() - 20);
		bounds.setX(bounds.getX() + 20);
		bounds.setWidth(bounds.getWidth() - 40);
		g.setFont(10.0f);
		g.drawText("20 " + slider.getTextValueSuffix(), bounds, juce::Justification::bottomLeft, true);
		g.drawText("20k " + slider.getTextValueSuffix(), bounds, juce::Justification::bottomRight, true);
	}
	else if (slider.getName() == "Distortion")
	{
		g.setFont(20.0f);
		
		g.drawText(slider.getTextFromValue(slider.getValue()), bounds, juce::Justification::centredBottom, true);
	}
	else
	{
		g.setFont(14.0f);
		g.drawText(slider.getName(), bounds, juce::Justification::centredBottom, true);
	}
}

void BigRotary::paint(juce::Graphics& g)
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
juce::Rectangle<int> BigRotary::getSliderBounds() const
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
	auto peakCoefficients = makePeakFilter(chainSettings, audioProcessor.getSampleRate());
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
	auto x = sl(0);
	auto y = sl(0);
	auto w = sl(434);
	auto h = sl(180);

	g.setColour(Colours::black);
	g.fillRect(x, y, w, h);
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
	g.setColour(Colours::green);
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
	lateDriveSlider(*audioProcessor.apvts.getParameter("Drive"), "x", "Drive"),
	lateGirthSlider(*audioProcessor.apvts.getParameter("Girth"), "%", "Girth"),
	lateBiasSlider(*audioProcessor.apvts.getParameter("Late Bias"), "", "Symmetry"),
	lateDriveTypeSlider(*audioProcessor.apvts.getParameter("Late Distortion Type"), "", "Distortion"),
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
	gainSliderAttachment(audioProcessor.apvts, "Gain", gainSlider)

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
    addAndMakeVisible(screenImageComponent);

	setResizable(false, false);
    setSize(1000, 600);
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

    //Screen
    auto x = sl(283);
    auto y = sl(22);
    auto w = sl(434);
    auto h = sl(180);

	g.fillRect(x, y, w, h);

	g.drawImageAt(backgroundImage, 0, 0);
       
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Layout
/////////////////////////////////////////////////W///////////////////////////////////////////////////////////////////

void PlasmaAudioProcessorEditor::resized()
{
	//Analyzers
	responseCurveComponent.setBounds(sl(283), sl(22), sl(434), sl(180));

	//Images
	screenImageComponent.setBounds(sl(262), sl(2), sl(476), sl(229));

    //Predrive
    preGainSlider.setBounds(sqw(0.5), sq(5), sq(1.5), sq(5.5));
    driveSlider.setBounds(sqw(2.0), sq(5), sq(1.5), sq(5.5));
    girthSlider.setBounds(sqw(3.5), sq(5), sq(1.5), sq(5.5));
    driveTypeSlider.setBounds(sqw(0.5), sq(0.5), sq(2.5), sq(2.5));
    biasSlider.setBounds(sqw(2.75), sq(3.0), sq(1.5), sq(1.5));

    //Highpass
	highPassFreqSlider.setBounds(sqw(5.0), sq(8.5), sq(3.5), sq(3.5));
    highPassSlopeSlider.setBounds(sqw(5.75), sq(4.5), sq(2.0), sq(2.0));
    highPassResonanceSlider.setBounds(sqw(6.75), sq(6.60), sq(2.0), sq(2.0));
    highPassResonanceQualitySlider.setBounds(sqw(4.75), sq(6.60), sq(2.0), sq(2.0));

    //Peak
	peakFreqSlider.setBounds(sqw(8.25), sq(8.5), sq(3.5), sq(3.5));
	peakGainSlider.setBounds(sqw(9.0), sq(6.60), sq(2.0), sq(2.0));
	peakQualitySlider.setBounds(sqw(9.0), sq(4.5), sq(2.0), sq(2.0));

    //Lowpass
	lowPassFreqSlider.setBounds(sqw(11.5), sq(8.5), sq(3.5), sq(3.5));
    lowPassSlopeSlider.setBounds(sqw(12.25),sq(4.5),sq(2.0),sq(2.0));
	lowPassResonanceSlider.setBounds(sqw(11.25), sq(6.60), sq(2.0), sq(2.0));
	lowPassResonanceQualitySlider.setBounds(sqw(13.25), sq(6.60), sq(2.0), sq(2.0));
   
	//Latedrive
	gainSlider.setBounds(sqw(15.0), sq(5), sq(1.5), sq(5.5));
	lateDriveSlider.setBounds(sqw(16.5), sq(5), sq(1.5), sq(5.5));
	lateGirthSlider.setBounds(sqw(18.0), sq(5), sq(1.5), sq(5.5));
	lateDriveTypeSlider.setBounds(sqw(17.0), sq(0.5), sq(2.5), sq(2.5));
	lateBiasSlider.setBounds(sqw(15.75), sq(3.0), sq(1.5), sq(1.5));

	responseCurveComponent.update();

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
		&responseCurveComponent
    };
}

