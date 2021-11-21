#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
