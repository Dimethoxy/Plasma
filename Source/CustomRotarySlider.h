#pragma once

#include <JuceHeader.h>
#include "CustomLookAndFeel.h"

class CustomRotarySlider : public Slider
{
public:
	CustomRotarySlider(
		RangedAudioParameter& rap,
		const String& unitSuffix,
		const String& name) : Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
			Slider::TextEntryBoxPosition::NoTextBox),
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
	const String name = "Slider";
	void paint(Graphics& g) override;
	Rectangle<int> getSliderBounds() const;
	int getTexHeight() const { return 14; };
	String getTooltipString();
	bool toggle = false;
private:
	CustomLookAndFeel lnf;
	RangedAudioParameter* param;
	String getAnalyserName(AnalyserType analyserType);
};
