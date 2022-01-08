#pragma once
#include <JuceHeader.h>

class PlasmaLabel : public juce::Label
{
public:
    PlasmaLabel();
    void setCustomFontSize(int size);
private:
    Font getCustomFont();
    Typeface::Ptr getTypeFace();
};
