#pragma once

#include <JuceHeader.h>
#include "CustomLookAndFeel.h"

class CustomTextButton : public TextButton
{
public:
	CustomTextButton();
	~CustomTextButton();
	void paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool 	shouldDrawButtonAsDown) override;
	//void paint(Graphics& g) override;
private:
	Typeface::Ptr getCustomTypeface();
	Font getCustomFont();
	CustomLookAndFeel lnf;
};

