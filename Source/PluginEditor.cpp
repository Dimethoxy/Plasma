#include "PluginProcessor.h"
#include "PluginEditor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sliders LookAndFeel
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CustomRotaryLookAndFeel::drawRotarySlider(juce::Graphics& g,
	int x, int y, int width, int height,
	float sliderPosProportional, 
	float rotaryStartAngle,
	float rotaryEndAngle,
	juce::Slider& slider)
{
	//Stuff
	auto outline = slider.findColour(Slider::rotarySliderOutlineColourId);
	auto fill = slider.findColour(Slider::rotarySliderFillColourId);
	auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(10);
	auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.3f;
	auto toAngle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
	auto lineW = jmin(8.0f, radius * 0.5f);
	auto arcRadius = radius - lineW * 0.5f;
	bool selector =  false;
	if (!selector)
	{
		//Draw Dark Rail
		Path backgroundArc;
		backgroundArc.addCentredArc(bounds.getCentreX(),
			bounds.getCentreY(),
			arcRadius,
			arcRadius,
			0.0f,
			rotaryStartAngle,
			rotaryEndAngle,
			true);
		g.setColour(Colour(18, 20, 20));
		g.strokePath(backgroundArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));

		//Draw Light Rail
		if (slider.isEnabled())
		{
			Path valueArc;
			valueArc.addCentredArc(bounds.getCentreX(),
				bounds.getCentreY(),
				arcRadius,
				arcRadius,
				0.0f,
				rotaryStartAngle,
				toAngle,
				true);
			g.setColour(fill);
			g.strokePath(valueArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
		}
		//Draw Thumb
		auto thumbWidth = lineW * 2.0f;
		Point<float> thumbPoint(bounds.getCentreX() + arcRadius * std::cos(toAngle - MathConstants<float>::halfPi),
			bounds.getCentreY() + arcRadius * std::sin(toAngle - MathConstants<float>::halfPi));
		g.setColour(Colour(18, 20, 20));
		g.fillEllipse(Rectangle<float>(thumbWidth, thumbWidth).withCentre(thumbPoint));
		g.setColour(Colours::white);
		g.drawEllipse(Rectangle<float>(thumbWidth, thumbWidth).withCentre(thumbPoint), 2);
	}
	else {
		int numOptions = 4;
		auto spacing = (rotaryEndAngle - rotaryEndAngle) / numOptions;
		for (int i = 0; i < numOptions; i++) 
		{

		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Knob
	auto sliderAngleRadian = jmap(sliderPosProportional, 0.0f, 1.0f, rotaryStartAngle, rotaryEndAngle);
	auto offset = 30;
	float r = 20;
	if (slider.isMouseButtonDown()) {
		offset = 26;
		r = 24;
	}
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
	x2 = -r * s;
	y2 = -r * c;
	x1 = x1 + x0;
	y1 = y1 + y0;
	x2 = x2 + x0;
	y2 = y2 + y0;
	
	//Draw Knob
	g.setColour(Colours::white);
	g.drawLine(x1,y1,x2,y2, 4);
	g.drawEllipse(circleBounds, 4);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Tooltip
	if (slider.getName() == "Distortion")
	{
		switch ((int)slider.getValue())
		{
		case 1:
			slider.setHelpText("Distortion Type : Hardclip");
			break;
		case 2:
			slider.setHelpText("Distortion Type : Softclip");
			break;
		case 3:
			slider.setHelpText("Distortion Type : Overdrive");
			break;
		case 4:
			slider.setHelpText("Distortion Type : Bitcrush");
			break;
		case 5:
			slider.setHelpText("Distortion Type : Atan");
			break;
		case 6:
			slider.setHelpText("Distortion Type : Sinus");
			break;
		case 7:
			slider.setHelpText("Distortion Type : Cosinus");
			break;
		}
	}
	else if (slider.getName() == "Slope")
	{
		int slope = ((int)slider.getValue() + 1) * 12;
		String str;
		str << "Slope : ";
		str << slope;
		str << " db/oct";
		slider.setHelpText(str);
	}
	else if (slider.getName() == "Symmetry")
	{
		auto value = round(slider.getValue() * 100);
		String str;
		str << "Symmetry : ";
		if (value == 0)
		{
			str << "Centered";
		}
		else
		{
			str << value;
			str << "%";
		}


		slider.setHelpText(str);
	}
	else
	{
		String str;
		str << (round(slider.getValue() * 100)) / 100;
		slider.setHelpText((String)slider.getName() + " : " +
			str + " " +
			(String)slider.getTextValueSuffix());
	}
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
	
	//Get Chain Settings
	auto chainSettings = getChainSettings(audioProcessor.apvts);
	
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
	if (chainSettings.analyserType == 0)
	{
		g.setColour(Colours::white);
		g.strokePath(responseCurve, PathStrokeType(3));
	}
}

//preGainSlider(*audioProcessor.apvts.getParameter("Pre Gain"), "db"),
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Editor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PlasmaAudioProcessorEditor::PlasmaAudioProcessorEditor(PlasmaAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p),
	//Pregain
	preGainSlider(*audioProcessor.apvts.getParameter("Pre Gain"), "dB", "Gain"),
	driveSlider(*audioProcessor.apvts.getParameter("Drive"), "", "Drive"),
	girthSlider(*audioProcessor.apvts.getParameter("Girth"), "", "Girth"),
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
	lateDriveSlider(*audioProcessor.apvts.getParameter("Late Drive"), "", "Drive"),
	lateGirthSlider(*audioProcessor.apvts.getParameter("Girth"), "", "Girth"),
	lateBiasSlider(*audioProcessor.apvts.getParameter("Late Bias"), "", "Symmetry"),
	lateDriveTypeSlider(*audioProcessor.apvts.getParameter("Late Distortion Type"), "", "Distortion"),
	mixSlider(*audioProcessor.apvts.getParameter("Mix"), "%", "Mix"),
	analyserSlider(*audioProcessor.apvts.getParameter("Analyser Type"), "", "Analyser Type"),
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
	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
	}
	tooltipLabel.setText("", juce::dontSendNotification);
	addAndMakeVisible(tooltipLabel);

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
	bool clear = true;
	for (auto* comp : getComps())
	{
		if (comp->isMouseButtonDown()) 
		{
			tooltipLabel.setText(comp->getHelpText(), juce::dontSendNotification);
			clear = false;
		}
	}
	if (clear) {
		tooltipLabel.setText("", juce::dontSendNotification);
	}
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
    preGainSlider.setBounds(50, 110, 120, 120);
	driveTypeSlider.setBounds(50, 430, 120, 120);
	biasSlider.setBounds(50, 550, 120, 120);
    girthSlider.setBounds(50, 670, 120, 120);
	driveSlider.setBounds(50, 790, 120, 120);
	

    //Highpass
	highPassSlopeSlider.setBounds(260, 430, 120, 120);
	highPassResonanceQualitySlider.setBounds(260, 550, 120, 120);
	highPassResonanceSlider.setBounds(260, 670, 120, 120);
	highPassFreqSlider.setBounds(260, 790, 120, 120);

    //Peak
	peakStereoSlider.setBounds(470, 430, 120, 120);
	peakQualitySlider.setBounds(470, 550, 120, 120);
	peakGainSlider.setBounds(470, 670, 120, 120);
	peakFreqSlider.setBounds(470, 790, 120, 120);
	

    //Lowpass
	lowPassSlopeSlider.setBounds(680, 430, 120, 120);
	lowPassResonanceQualitySlider.setBounds(680, 550, 120, 120);
	lowPassResonanceSlider.setBounds(680, 670, 120, 120);
	lowPassFreqSlider.setBounds(680, 790, 120, 120);
   
	//Latedrive
	gainSlider.setBounds(890, 110, 120, 120);
	lateDriveTypeSlider.setBounds(890, 430, 120, 120);
	lateBiasSlider.setBounds(890, 550, 120, 120);
	lateGirthSlider.setBounds(890, 670, 120, 120);
	lateDriveSlider.setBounds(890, 790, 120, 120);

	//ToolTip
	tooltipLabel.setBounds(30, 0, 200, 55);

	//Mix
	mixSlider.setBounds(890, 230, 120, 120);
	analyserSlider.setBounds(50, 230, 120, 120);

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

