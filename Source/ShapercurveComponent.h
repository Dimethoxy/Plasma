#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PlasmaDistortionProcessor.h"

class ShapercurveComponent : public Component,
	juce::AudioProcessorParameter::Listener,
	juce::Timer
{
public:
	ShapercurveComponent(PlasmaAudioProcessor&, int stage);
	~ShapercurveComponent();

	void parameterValueChanged(int parameterIndex, float newValue) override;
	void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override {};
	void timerCallback() override;
	void paint(juce::Graphics& g) override;
	void setColor(Colour c);
private:
	PlasmaAudioProcessor& audioProcessor;
	juce::Atomic<bool> parametersChanged{ false };
	float earlyDrive = 0.0f;
	float lateDrive = 0.0f;
	Distortion earlyType = Distortion::Hardclip;
	Distortion lateType = Distortion::Hardclip;
	int stage = 0;
	PlasmaDistortionProcessor distortionProcessor;
	Colour color = Colour(255, 255, 255);
};