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
    setVelocityModeParameters(1.0, 1, 0.0, false, ModifierKeys::noModifiers);
  }

  // Destructor
  ~CustomRotarySlider() { setLookAndFeel(nullptr); }

  void mouseDown(const MouseEvent& e)
  {

    ModifierKeys modifiers = ModifierKeys::getCurrentModifiersRealtime();

    if (modifiers.isShiftDown())
      this->setMouseDragSensitivity(2000);
    else
      this->setMouseDragSensitivity(200);

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

  void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel)
  {
    auto newWheel = wheel;
    const auto speed = e.mods.isShiftDown() ? 0.1 : 1.0;
    newWheel.deltaY *= speed;

    Slider::mouseWheelMove(e, newWheel);
  }
  // lets do the mouse wheel thing for dragging the slider as well

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
