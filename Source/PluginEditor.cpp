#include "PluginProcessor.h"
#include "PluginEditor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PlasmaAudioProcessorEditor::PlasmaAudioProcessorEditor(PlasmaAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p), 
    highPassFreqSliderAttachment(audioProcessor.apvts, "Highpass Freq", highPassFreqSlider),
    lowPassFreqSliderAttachment(audioProcessor.apvts, "Lowpass Freq", lowPassFreqSlider),
    peakFreqSliderAttachment(audioProcessor.apvts, "Peak Freq", peakFreqSlider),
    biasSliderAttachment(audioProcessor.apvts, "Bias", biasSlider),
    lateBiasSliderAttachment(audioProcessor.apvts, "Late Bias", lateBiasSlider),
    driveTypeSliderAttachment(audioProcessor.apvts, "Distortion Type", driveTypeSlider),
    lateDriveTypeSliderAttachment(audioProcessor.apvts, "Late Distortion Type", lateDriveTypeSlider),
    highPassResonanceSliderAttachment(audioProcessor.apvts, "Highpass Resonance", highPassResonanceSlider),
    lowPassResonanceSliderAttachment(audioProcessor.apvts, "Lowpass Resonance", lowPassResonanceSlider),
    peakGainSliderAttachment(audioProcessor.apvts, "Peak Gain", highPassResonanceQualitySlider),
    highPassResonanceQualitySliderAttachment(audioProcessor.apvts, "Highpass Resonance Q", highPassResonanceQualitySlider),
	lowPassResonanceQualitySliderAttachment(audioProcessor.apvts, "Lowpass Resonance Q", lowPassResonanceQualitySlider),
	peakQualitySliderAttachment(audioProcessor.apvts, "Peak Q", peakQualitySlider),
	highPassSlopeSliderAttachment(audioProcessor.apvts, "Highpass Slope", highPassSlopeSlider),
	lowPassSlopeSliderAttachment(audioProcessor.apvts, "Lowpass Slope", lowPassSlopeSlider),
	preGainSliderAttachment(audioProcessor.apvts, "Pre Gain", gainSlider),
	driveSliderAttachment(audioProcessor.apvts, "Drive", driveSlider),
	girthSliderAttachment(audioProcessor.apvts, "Girth", girthSlider),
	lateGirthSliderAttachment(audioProcessor.apvts, "Late Girth", lateGirthSlider),
	lateDriveSliderAttachment(audioProcessor.apvts, "Late Drive", lateDriveSlider),
	gainSliderAttachment(audioProcessor.apvts, "Gain", gainSlider)
{
	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
	}
	setSize(1000, 500);
}

PlasmaAudioProcessorEditor::~PlasmaAudioProcessorEditor()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Draw
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlasmaAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour(35, 35, 35));
	g.fillRect(sq(5.0), sq(0.5), sq(10.0), sq(3.5)); // height
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Layout
/////////////////////////////////////////////////W///////////////////////////////////////////////////////////////////
int PlasmaAudioProcessorEditor::sq(float value)
{
    return round(value * 50.0f);
}

void PlasmaAudioProcessorEditor::resized()
{
    preGainSlider.setBounds(sq(0.5), sq(4), sq(1.5), sq(5.5));
    driveSlider.setBounds(sq(2.0), sq(4), sq(1.5), sq(5.5));
    girthSlider.setBounds(sq(3.5), sq(4), sq(1.5), sq(5.5));

    driveTypeSlider.setBounds(sq(1.25), sq(1.5), sq(1.5), sq(1.5));
    biasSlider.setBounds(sq(2.75), sq(1.5), sq(1.5), sq(1.5));
	lateDriveTypeSlider.setBounds(sq(17.25), sq(1.5), sq(1.5), sq(1.5));
	lateBiasSlider.setBounds(sq(15.75), sq(1.5), sq(1.5), sq(1.5));

	gainSlider.setBounds(sq(15.0), sq(4), sq(1.5), sq(5.5));
    lateDriveSlider.setBounds(sq(16.5), sq(4), sq(1.5), sq(5.5));
	lateGirthSlider.setBounds(sq(18.0), sq(4), sq(1.5), sq(5.5));

    highPassSlopeSlider.setBounds(sq(6.0), sq(4.25), sq(1.5), sq(1.5));
    highPassFreqSlider.setBounds(sq(5.5), sq(7.25), sq(2.5), sq(2.5));
    highPassResonanceSlider.setBounds(sq(7.0), sq(5.75), sq(1.5), sq(1.5));
    highPassResonanceQualitySlider.setBounds(sq(5.0), sq(5.75), sq(1.5), sq(1.5));

	peakFreqSlider.setBounds(sq(8.75), sq(5.75), sq(2.5), sq(2.5));
	peakGainSlider.setBounds(sq(9.25), sq(4.25), sq(1.5), sq(1.5));
	peakQualitySlider.setBounds(sq(9.25), sq(8.25), sq(1.5), sq(1.5));

    lowPassSlopeSlider.setBounds(sq(12.5),sq(4.25),sq(1.5),sq(1.5));
    lowPassFreqSlider.setBounds(sq(12.0), sq(7.25), sq(2.5), sq(2.5));
	lowPassResonanceSlider.setBounds(sq(11.5), sq(5.75), sq(1.5), sq(1.5));
	lowPassResonanceQualitySlider.setBounds(sq(13.5), sq(5.75), sq(1.5), sq(1.5));


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
        &driveTypeSlider,
        &lateDriveTypeSlider,

        &lateGirthSlider,
        &lateDriveSlider,
        &preGainSlider,

        & highPassSlopeSlider,
        &highPassFreqSlider,
        &highPassResonanceSlider,
        &highPassResonanceQualitySlider,

        &peakFreqSlider,
        &peakGainSlider,
        &peakQualitySlider,

        &lowPassSlopeSlider,
        &lowPassFreqSlider,
		&lowPassResonanceSlider,
		&lowPassResonanceQualitySlider
    };
}