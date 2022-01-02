#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

inline int sl(float value)
{
    return round(value * 1.0f);
}

class ResponseCurveComponent : public Component,
    juce::AudioProcessorParameter::Listener,
    juce::Timer
{
public:
    ResponseCurveComponent(PlasmaAudioProcessor&);
    ~ResponseCurveComponent();

    void parameterValueChanged(int parameterIndex, float newValue) override;
    void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override {};
    void timerCallback() override;
    void update();
    void paint(juce::Graphics& g) override;

private:
    PlasmaAudioProcessor& audioProcessor;
    juce::Atomic<bool> parametersChanged{ false };
    MonoChain monoChain;
};