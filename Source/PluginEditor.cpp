#include "PluginProcessor.h"
#include "PluginEditor.h"

//preGainSlider(*audioProcessor.apvts.getParameter("Pre Gain"), "db"),
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PlasmaAudioProcessorEditor::PlasmaAudioProcessorEditor(PlasmaAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p),

    preGainSliderAttachment(audioProcessor.apvts, "Pre Gain", gainSlider),
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
    else
    {
        jassert(! screenImage.isNull());
    }

	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
	}
    addAndMakeVisible(screenImageComponent);

    //Listen to parameter changes
    const auto& params = audioProcessor.getParameters();
    for (auto param : params)
    {
        param->addListener(this);
    }
    startTimer(60);

	//Update Monochain
	auto chainSettings = getChainSettings(audioProcessor.apvts);
	auto peakCoefficients = makePeakFilter(chainSettings, audioProcessor.getSampleRate());
	updateCoefficients(monoChain.get<ChainPositions::Peak>().coefficients, peakCoefficients);

	setResizable(false, false);
    setSize(1000, 550);
  }

PlasmaAudioProcessorEditor::~PlasmaAudioProcessorEditor()
{
	const auto& params = audioProcessor.getParameters();
    for (auto param : params)
    {
        param->removeListener(this);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Draw
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlasmaAudioProcessorEditor::paint (juce::Graphics& g)
{
    using namespace juce;
    //Background 2e2f31
    g.fillAll(Colour(46, 47, 49));

    //Screen
    auto x = sl(283);
    auto y = sl(22);
    auto w = sl(434);
    auto h = sl(180);

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
    for(size_t i = 1; i < mags.size(); ++i)
    {
        responseCurve.lineTo(x+i, map(mags[i]));
    }
    g.setColour(Colours::white);
    g.strokePath(responseCurve, PathStrokeType(3));
   
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Layout
/////////////////////////////////////////////////W///////////////////////////////////////////////////////////////////
int PlasmaAudioProcessorEditor::sq(float value)
{
    return round(value * 50.0f);
}
int PlasmaAudioProcessorEditor::sl(float value)
{
	return round(value * 1.0f);
}

void PlasmaAudioProcessorEditor::resized()
{
	//Images
	screenImageComponent.setBounds(sl(262), sl(2), sl(476), sl(229));

    //Predrive
    preGainSlider.setBounds(sq(0.5), sq(5), sq(1.5), sq(5.5));
    driveSlider.setBounds(sq(2.0), sq(5), sq(1.5), sq(5.5));
    girthSlider.setBounds(sq(3.5), sq(5), sq(1.5), sq(5.5));
    driveTypeSlider.setBounds(sq(0.5), sq(0.5), sq(2.5), sq(2.5));
    biasSlider.setBounds(sq(2.75), sq(3.0), sq(1.5), sq(1.5));

    //Highpass
    highPassSlopeSlider.setBounds(sq(6.0), sq(4.75), sq(1.5), sq(1.5));
    highPassFreqSlider.setBounds(sq(5.5), sq(8.25), sq(2.5), sq(2.5));
    highPassResonanceSlider.setBounds(sq(7.0), sq(6.5), sq(1.5), sq(1.5));
    highPassResonanceQualitySlider.setBounds(sq(5.0), sq(6.5), sq(1.5), sq(1.5));

    //Peak
	peakFreqSlider.setBounds(sq(8.75), sq(6.75), sq(2.5), sq(2.5));
	peakGainSlider.setBounds(sq(9.25), sq(5.25), sq(1.5), sq(1.5));
	peakQualitySlider.setBounds(sq(9.25), sq(9.25), sq(1.5), sq(1.5));

    //Lowpass
    lowPassSlopeSlider.setBounds(sq(12.5),sq(4.75),sq(1.5),sq(1.5));
    lowPassFreqSlider.setBounds(sq(12.0), sq(8.25), sq(2.5), sq(2.5));
	lowPassResonanceSlider.setBounds(sq(11.5), sq(6.5), sq(1.5), sq(1.5));
	lowPassResonanceQualitySlider.setBounds(sq(13.5), sq(6.5), sq(1.5), sq(1.5));
   
	//Latedrive
	gainSlider.setBounds(sq(15.0), sq(5), sq(1.5), sq(5.5));
	lateDriveSlider.setBounds(sq(16.5), sq(5), sq(1.5), sq(5.5));
	lateGirthSlider.setBounds(sq(18.0), sq(5), sq(1.5), sq(5.5));
	lateDriveTypeSlider.setBounds(sq(17.0), sq(0.5), sq(2.5), sq(2.5));
	lateBiasSlider.setBounds(sq(15.75), sq(3.0), sq(1.5), sq(1.5));

}

void PlasmaAudioProcessorEditor::parameterValueChanged(int parameterIndex, float newValue)
{
    parametersChanged.set(true);
}

void PlasmaAudioProcessorEditor::timerCallback()
{
    if (parametersChanged.compareAndSetBool(false, true))
    {
        //Update Monochain
        auto chainSettings = getChainSettings(audioProcessor.apvts);
        auto peakCoefficients = makePeakFilter(chainSettings, audioProcessor.getSampleRate());
        updateCoefficients(monoChain.get<ChainPositions::Peak>().coefficients, peakCoefficients);
        //signal a repaint
        repaint();
    }
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
		&lateDriveTypeSlider
    };
}