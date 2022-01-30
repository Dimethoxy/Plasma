#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class CustomLookAndFeel : public LookAndFeel_V4
{
	void drawRotarySlider(
		Graphics& g,
		int x, int y, int width, int height,
		float sliderPosProportional, float rotaryStartAngle,
		float rotaryEndAngle,
		juce::Slider&) override;

	void drawButtonBackground(
		Graphics& g,
		Button& button,
		const Colour& backgroundColour,
		bool isMouseOverButton,
		bool isButtonDown) override;

	void drawLabel(Graphics&, Label&) override;

private:
	Typeface::Ptr getCustomTypeface();
	Font getCustomFont();
	String getAnalyserName(AnalyserType analyserType);
};