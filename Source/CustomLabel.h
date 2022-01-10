#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class CustomLabel : public Label
{
public:
    CustomLabel(String text, int size, Justification justification);
    void resize();
private:
    int mainSize = 20;
    int titelSize = 29;
    int customFontSize;
    void setCustomFontSize(int size);
    Typeface::Ptr getTypeface();
    Font getCustomFont();
    float getCustomFontSize();
    float getScaledCustomFontSize();
};

