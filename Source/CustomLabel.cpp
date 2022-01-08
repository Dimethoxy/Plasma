#include "CustomLabel.h"
#include "PluginEditor.h"

CustomLabel::CustomLabel(String text, int size, Justification justification, bool underline)
{
    setCustomFontSize(size);
    setText(text, juce::dontSendNotification);
    setFont(getFont().withHeight(getCustomFontSize()));
    setJustificationType(justification);
}

void CustomLabel::resize()
{
    setFont(getFont().withHeight(getScaledCustomFontSize()));
}

Typeface::Ptr CustomLabel::getTypeface()
{
    Typeface::Ptr typeface = Typeface::createSystemTypefaceFor(BinaryData::PoppinsMedium_ttf, BinaryData::PoppinsMedium_ttfSize);
    return typeface;
}

Font CustomLabel::getCustomFont()
{
    Font font(getTypeface());
    return font;
}

void CustomLabel::setCustomFontSize(int size)
{
    customFontSize = size;
}

float CustomLabel::getCustomFontSize()
{
    float factor = 1.0f;
    switch (customFontSize)
    {
    case FontSizes::Main:
    {
        return mainSize * factor;
    }
    case FontSizes::Titel:
    {
        return titelSize * factor;
    }
    }
}

float CustomLabel::getScaledCustomFontSize()
{
    float factor = getBounds().getHeight() / 40.0f;
    switch (customFontSize)
    {
    case FontSizes::Main:
    {
        return mainSize * factor;
    }
    case FontSizes::Titel:
    {
        return titelSize * factor;
    }
    }
}

