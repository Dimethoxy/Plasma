#pragma once

#include <JuceHeader.h>
#include "CustomLookAndFeel.h";

class CustomRotarySlider : public Slider
{
public:
    CustomRotarySlider(juce::RangedAudioParameter& rap, const juce::String& unitSuffix, const juce::String& name) :
        juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox),
        param(&rap)
    {
        setTextValueSuffix(unitSuffix);
        setLookAndFeel(&lnf);
        setName(name);
        setColour(Slider::rotarySliderFillColourId, Colour(255, 0, 0));
    }

    //Destructor
    ~CustomRotarySlider()
    {
        setLookAndFeel(nullptr);
    }
    //Misc
    const juce::String name = "Slider";
    void paint(juce::Graphics& g) override;
    juce::Rectangle<int> getSliderBounds() const;
    int getTexHeight() const { return 14; }
    juce::String getDisplayString() const;
private:
    CustomLookAndFeel lnf;
    juce::RangedAudioParameter* param;
};