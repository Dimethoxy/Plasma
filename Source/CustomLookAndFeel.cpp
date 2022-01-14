#include "CustomLookAndFeel.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Buttons
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CustomLookAndFeel::drawButtonBackground(
	Graphics& g,
	Button& button,
	const Colour& backgroundColour,
	bool isMouseOverButton,
	bool isButtonDown)
{
	auto text = button.getButtonText();
	auto bounds = button.getBounds();
	Rectangle<float> area(0, 0, bounds.getWidth(), bounds.getHeight());
	auto center = area.getCentre();
	float lineSize = bounds.getHeight() / 15.0;

	//Select Color
	g.setColour(Colours::white);

	//Draw Foreground
	float iconSize = 2.5 * lineSize;
	if (text == "O")
	{
		g.setFont(getCustomFont().withHeight(4 * iconSize));
		g.drawText("Options", area, Justification::centred, false);
	}
	else if (text == "S")
	{
		g.setFont(getCustomFont().withHeight(4 * iconSize));
		g.drawText("Save", area, Justification::centred, false);
	}
	else if (text == "+")
	{
		Point<float> p1(center.x, center.y - iconSize);
		Point<float> p2(center.x, center.y + iconSize);
		Point<float> p3(center.x + iconSize, center.y);
		Point<float> p4(center.x - iconSize, center.y);
		Line<float> l1(p1, p2);
		Line<float> l2(p3, p4);
		g.drawLine(l1, lineSize);
		g.drawLine(l2, lineSize);
	}
	else if (text == "-")
	{
		Point<float> p3(center.x + iconSize, center.y);
		Point<float> p4(center.x - iconSize, center.y);
		Line<float> l2(p3, p4);
		g.drawLine(l2, lineSize);
	}
	g.drawRoundedRectangle(area.reduced(lineSize), 4 * lineSize, lineSize);
	//Outline
	//

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Slider
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CustomLookAndFeel::drawRotarySlider(juce::Graphics& g,
	int x, int y, int width, int height,
	float sliderPosProportional,
	float rotaryStartAngle,
	float rotaryEndAngle,
	juce::Slider& slider)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Check Type and Generate String

	//Default Skewfactor
	auto skewFactor = 0.5;

	//Selector Parameters
	bool isSelector = false;
	int numOptions = 4;
	int selectedOption = 0;

	//Symmertry
	bool isCentered = false;
	auto range = rotaryEndAngle - rotaryStartAngle;
	auto center = range / 2;

	//Style Setup
	if (slider.getName() == "Distortion")
	{
		isSelector = true;
		numOptions = 8;
		selectedOption = (int)slider.getValue();
	}
	else if (slider.getName() == "Slope")
	{
		isSelector = true;
		numOptions = 8;
		selectedOption = (int)slider.getValue();
	}
	else if (slider.getName() == "Symmetry")
	{
		isCentered = true;
		auto value = round(slider.getValue() * 100);
	}
	else if (slider.getName() == "Analyser Type")
	{
		isSelector = true;
		numOptions = 5;
		selectedOption = (int)slider.getValue();
	}
	else if (slider.getName() == "Lowpass" || slider.getName() == "Highpass" || slider.getName() == "Peak")
	{
		skewFactor = 0.80;
	}
	else if (slider.getName() == "Peak Resonance")
	{
		isCentered = true;
	}
	else if (slider.getName() == "Girth")
	{
		String str;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Drawing

	//Calculations
	NormalisableRange<float> targetRange{ 0, 1 };
	targetRange.setSkewForCentre(skewFactor);
	auto normalisedPos = targetRange.convertFrom0to1(sliderPosProportional);
	auto outline = slider.findColour(Slider::rotarySliderOutlineColourId);
	auto fill = slider.findColour(Slider::rotarySliderFillColourId);
	auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(width / 12);
	auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.3f;
	auto toAngle = rotaryStartAngle + normalisedPos * (rotaryEndAngle - rotaryStartAngle);
	auto lineW = jmin((float)width / 12, radius * 0.5f);
	auto arcRadius = radius - lineW * 0.5f;
	auto thumbWidth = lineW * 2.0f;
	auto lineSize = bounds.getHeight() / 40;

	Colour backgroundColor(18, 20, 20);
	//Draw Rail or Selector
	if (!isSelector)
	{
		//Draw Dark Rail
		Path backgroundArc;
		backgroundArc.addCentredArc(bounds.getCentreX(),
			bounds.getCentreY(),
			arcRadius,
			arcRadius,
			0.0f,
			rotaryStartAngle,
			rotaryEndAngle,
			true);
		g.setColour(Colour(18, 20, 20));
		g.strokePath(backgroundArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));

		//Draw Light Rail
		if (slider.isEnabled())
		{
			Path valueArc;
			if (!isCentered) {
				valueArc.addCentredArc(bounds.getCentreX(),
					bounds.getCentreY(),
					arcRadius,
					arcRadius,
					0.0f,
					rotaryStartAngle,
					toAngle,
					true);
			}
			else
			{
				valueArc.addCentredArc(bounds.getCentreX(),
					bounds.getCentreY(),
					arcRadius,
					arcRadius,
					0.0f,
					rotaryStartAngle + center,
					toAngle,
					true);
			}
			g.setColour(fill);
			g.strokePath(valueArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
		}
		//Draw Thumb
		Point<float> thumbPoint(bounds.getCentreX() + arcRadius * std::cos(toAngle - MathConstants<float>::halfPi),
			bounds.getCentreY() + arcRadius * std::sin(toAngle - MathConstants<float>::halfPi));
		g.setColour(backgroundColor);
		g.fillEllipse(Rectangle<float>(thumbWidth, thumbWidth).withCentre(thumbPoint));
		g.setColour(Colours::white);
		g.drawEllipse(Rectangle<float>(thumbWidth, thumbWidth).withCentre(thumbPoint), lineSize);
	}
	else {
		//Draw Selector
		auto spacing = (rotaryEndAngle - rotaryStartAngle) / (numOptions - 1);
		auto r = bounds.getHeight() / 2.5;
		auto dotSize = thumbWidth;
		auto radianOffset = rotaryStartAngle - rotaryEndAngle;
		auto angle = rotaryStartAngle;

		for (int i = 0; i < numOptions; i++)
		{
			//Calculate Position
			auto x = r * cos(angle - radianOffset);
			auto y = r * sin(angle - radianOffset);

			//Check if selected
			if (selectedOption != i)
			{

				//Dot Ring Unselected
				Point<float> dot(bounds.getCentreX() + x, bounds.getCentreY() + y);
				g.setColour(Colours::white);
				g.drawEllipse(Rectangle<float>(dotSize / 2, dotSize / 2).withCentre(dot), lineSize);

			}
			else
			{
				Point<float> fill(bounds.getCentreX() + x, bounds.getCentreY() + y);
				g.setColour(Colours::red);
				g.fillEllipse(Rectangle<float>(dotSize / 2, dotSize / 2).withCentre(fill));
				Point<float> dot(bounds.getCentreX() + x, bounds.getCentreY() + y);
				g.setColour(Colours::white);
				g.drawEllipse(Rectangle<float>(dotSize, dotSize).withCentre(dot), lineSize);

			}
			angle += spacing;
		}
	}

	//Calculate Knob
	auto sliderAngleRadian = jmap(normalisedPos, 0.0f, 1.0f, rotaryStartAngle, rotaryEndAngle);
	auto offset = width / 4;
	float r = width / 6;
	if (slider.isMouseButtonDown()) {
		offset = width / 4.5;
		r = width / 5;
	}
	auto circleBounds = Rectangle<float>(bounds.getX() + offset,
		bounds.getY() + offset,
		bounds.getWidth() - 2 * offset,
		bounds.getHeight() - 2 * offset);

	//Get Sine / Cosine
	float s, c;
	c = cos(-sliderAngleRadian);
	s = sin(-sliderAngleRadian);

	//Calculate Indicator
	float x0, x1, x2, y0, y1, y2;
	x0 = circleBounds.getCentreX();
	y0 = circleBounds.getCentreY();
	x1 = 0;
	y1 = 0;
	x2 = -r * s;
	y2 = -r * c;
	x1 = x1 + x0;
	y1 = y1 + y0;
	x2 = x2 + x0;
	y2 = y2 + y0;

	//Draw Knob
	g.setColour(Colours::white);
	g.drawLine(x1, y1, x2, y2, lineSize);
	g.drawEllipse(circleBounds, lineSize);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


}

Typeface::Ptr CustomLookAndFeel::getCustomTypeface()
{
	Typeface::Ptr typeface = Typeface::createSystemTypefaceFor(
		BinaryData::PoppinsMedium_ttf,
		BinaryData::PoppinsMedium_ttfSize);
	return typeface;
}

Font CustomLookAndFeel::getCustomFont()
{
	Font font(getCustomTypeface());
	return font;
}

