#pragma once

#include "CustomLookAndFeel.h"
#include <JuceHeader.h>

class CustomRotarySlider
  : public Slider
  , public MouseListener
{
public:
  CustomRotarySlider(RangedAudioParameter& rap,
                     const String& unitSuffix,
                     const String& name)
    : Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
             Slider::TextEntryBoxPosition::NoTextBox)
    , param(&rap)
  {
    setTextValueSuffix(unitSuffix);
    setLookAndFeel(&lnf);
    setName(name);
    setColour(Slider::rotarySliderFillColourId, Colour(255, 0, 0));
  }

  // Destructor
  ~CustomRotarySlider() { setLookAndFeel(nullptr); }

  void mouseDown(const MouseEvent& e)
  {

    ModifierKeys modifiers = ModifierKeys::getCurrentModifiersRealtime();

    if (modifiers.isRightButtonDown() || modifiers.isCtrlDown()) {
      auto* parent = this->getParentComponent();
      auto* editor = dynamic_cast<AudioProcessorEditor*>(parent);
      auto* hostContext = editor->getHostContext();
      if (hostContext == nullptr)
        return;
      auto contextMenu = hostContext->getContextMenuForParameter(param);
      if (contextMenu == nullptr)
        return;
      auto position = editor->getMouseXYRelative();
      contextMenu->showNativeMenu(position);
    } else {
      Slider::mouseDown(e); // to the usual thing .... drag the slider
    }
  }

  // Misc
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
