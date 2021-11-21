#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

struct CustomRotarySlider : juce::Slider 
{
    CustomRotarySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
                                        juce::Slider::TextEntryBoxPosition::NoTextBox)
    {

    }
};
struct CustomSlider : juce::Slider
{
	CustomSlider() : juce::Slider(juce::Slider::SliderStyle::LinearVertical,
		juce::Slider::TextEntryBoxPosition::NoTextBox)
	{

	}
};
struct CustomHorizontalSlider : juce::Slider
{
	CustomHorizontalSlider() : juce::Slider(juce::Slider::SliderStyle::LinearHorizontal,
		juce::Slider::TextEntryBoxPosition::NoTextBox)
	{

	}
};

class PlasmaAudioProcessorEditor : public juce::AudioProcessorEditor,
    public Slider::Listener
{
public:
    PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
    ~PlasmaAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override;

private:
    PlasmaAudioProcessor& audioProcessor;
    
    int sq(float value);

    CustomRotarySlider highPassFreqSlider, lowPassFreqSlider, peakFreqSlider;
    CustomRotarySlider biasSlider, lateBiasSlider, driveTypeSlider, lateDriveTypeSlider;
    CustomRotarySlider highPassResonanceSlider, lowPassResonanceSlider, peakGainSlider;
    CustomRotarySlider highPassResonanceQualitySlider, lowPassResonanceQualitySlider, peakQualitySlider;
    CustomRotarySlider highPassSlopeSlider, lowPassSlopeSlider;

    CustomSlider gainSlider, driveSlider, girthSlider, lateGirthSlider, lateDriveSlider, preGainSlider;

    using APVTS = juce::AudioProcessorValueTreeState;
    using Attachment = APVTS::SliderAttachment;
   
    Attachment highPassFreqSliderAttachment,
        lowPassFreqSliderAttachment,
        peakFreqSliderAttachment,
        biasSliderAttachment,
        lateBiasSliderAttachment,
        driveTypeSliderAttachment,
        lateDriveTypeSliderAttachment,
        highPassResonanceSliderAttachment,
        lowPassResonanceSliderAttachment,
        peakGainSliderAttachment,
        highPassResonanceQualitySliderAttachment,
        lowPassResonanceQualitySliderAttachment,
        peakQualitySliderAttachment,
        highPassSlopeSliderAttachment,
        lowPassSlopeSliderAttachment,
        preGainSliderAttachment,
        driveSliderAttachment,
        girthSliderAttachment,
        lateGirthSliderAttachment,
        lateDriveSliderAttachment,
        gainSliderAttachment;

    std::vector<juce::Component*> getComps();

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
