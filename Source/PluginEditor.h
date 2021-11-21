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
    
    float sq(float value);

    CustomRotarySlider highPassFreqSlider, lowPassFreqSlider, peakFreqSlider;
    CustomRotarySlider biasSlider, lateBiasSlider, driveTypeSlider, lateDriveTypeSlider;
    CustomRotarySlider highPassResonanceSlider, lowPassResonanceSlider, peakGainSlider;
    CustomRotarySlider highPassResonanceQualitySlider, lowPassResonanceQualitySlider, peakQualitySlider;
    CustomRotarySlider highPassSlopeSlider, lowPassSlopeSlider;

    CustomSlider gainSlider, driveSlider, girthSlider, lateGirthSlider, lateDriveSlider, lateGainSlider;

    std::vector<juce::Component*> getComps();

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
