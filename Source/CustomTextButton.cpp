#include "CustomTextButton.h"

CustomTextButton::CustomTextButton()
{
	setLookAndFeel(&lnf);
}

CustomTextButton::~CustomTextButton()
{
	setLookAndFeel(nullptr);
}

Typeface::Ptr CustomTextButton::getCustomTypeface()
{
	Typeface::Ptr typeface = Typeface::createSystemTypefaceFor(
		BinaryData::PoppinsMedium_ttf,
		BinaryData::PoppinsMedium_ttfSize);
	return typeface;
}

Font CustomTextButton::getCustomFont()
{
	Font font(getCustomTypeface());
	return font;
}

void CustomTextButton::paintButton(Graphics& g,
	bool shouldDrawButtonAsHighlighted,
	bool shouldDrawButtonAsDown)
{

	getLookAndFeel().drawButtonBackground(
		g,
		*this,
		Colours::aqua,
		shouldDrawButtonAsHighlighted,
		shouldDrawButtonAsDown);
	/*
	getLookAndFeel().drawButtonText(
		g,
		*this,
		shouldDrawButtonAsHighlighted,
		shouldDrawButtonAsDown);
	*/

	auto bounds = getBounds();
}