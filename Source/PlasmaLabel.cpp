#include "PlasmaLabel.h"

PlasmaLabel::PlasmaLabel()
{
    setText("PLASMA", juce::dontSendNotification);
    setFont(getFont().withHeight(100));
    setJustificationType(Justification::centredTop);
}
void PlasmaLabel::setCustomFontSize(int size)
{
    setFont(getCustomFont().withHeight(size));
}
Typeface::Ptr PlasmaLabel::getTypeFace()
{
    Typeface::Ptr tface = Typeface::createSystemTypefaceFor(
        BinaryData::SedgwickAveDisplayRegular_ttf, 
        BinaryData::SedgwickAveDisplayRegular_ttfSize);
    return tface;
}
Font PlasmaLabel::getCustomFont()
{
    Font font(getTypeFace());
    return font;
}
