#pragma once

#include <JuceHeader.h>

struct CustomLookAndFeel : juce::LookAndFeel_V4
{
    void drawRotarySlider(juce::Graphics& g,
        int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle,
        float rotaryEndAngle,
        juce::Slider&) override;
};