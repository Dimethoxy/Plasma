#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

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
	void setPadding(float newPadding);
private:
	PlasmaAudioProcessor& audioProcessor;
	juce::Atomic<bool> parametersChanged{ false };
	MonoChain monoChain;
	float padding = 10;
};