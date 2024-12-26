#pragma once

#include "CustomLookAndFeel.h"
#include "PluginProcessor.h"
#include <JuceHeader.h>
enum FontSizes
{
  Main,
  Titel,
  Tooltipp
};
class CustomLabel : public Label
{
public:
  CustomLabel(String text, int size, Justification justification);
  ~CustomLabel();
  void resize();

protected:
  void paint(Graphics&) override;

private:
  int mainSize = 20;
  int titelSize = 29;
  int TooltipSize = 18;
  int customFontSize;
  void setCustomFontSize(int size);
  Typeface::Ptr getTypeface();
  Font getCustomFont();
  float getCustomFontSize();
  float getScaledCustomFontSize();
  CustomLookAndFeel lnf;
};

class CustomTextbox : public CustomLabel
{
public:
  CustomTextbox(String text, int size, Justification justification)
    : CustomLabel(text, size, justification)
  {
    setEditable(true);
  };
};
