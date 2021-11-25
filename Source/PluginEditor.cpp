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

	setResizable(false, false);
    setSize(1000, 550);
  }

PlasmaAudioProcessorEditor::~PlasmaAudioProcessorEditor()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Draw
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlasmaAudioProcessorEditor::paint (juce::Graphics& g)
{
    //2e2f31
    g.fillAll(juce::Colour(46, 47, 49));
	g.fillRect(sl(283), sl(22), sl(434), sl(180)); // height
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Update
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlasmaAudioProcessorEditor::sliderValueChanged (Slider* slider)
{

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