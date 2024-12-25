#pragma once

#include "CustomLabel.h"
#include "CustomRotarySlider.h"
#include "ValueEditor.h"
#include <JuceHeader.h>

// class ValueEditorBackground : public Component
// {};

class ValueEditor
  : public Component
  , public TextEditor::Listener
{
public:
  ValueEditor()
    : textbox("0", FontSizes::Main, Justification::centredLeft)
    , titleLabel("Value Editor", FontSizes::Titel, Justification::centredBottom)
  {
    addAndMakeVisible(textbox);
    addAndMakeVisible(titleLabel);
  }

  void resized() override
  {
    titleLabel.setBoundsRelative(0.20f, 0.0f, 0.6f, 0.42f);
    textbox.setBoundsRelative(0.37f, 0.44f, 0.26f, 0.12f);
  }

  void paint(Graphics& g) override
  {
    g.setColour(backgroundColor);
    g.fillRoundedRectangle(getLocalBounds().toFloat(), cornerSize);
  }

  void setColour(Colour background, Colour text)
  {
    backgroundColor = background;
    textColor = text;
  }

  void setSlider(CustomRotarySlider* slider)
  {
    this->slider = slider;
    titleLabel.setText(slider->getName(), dontSendNotification);
    textbox.setText(String(slider->getValue()), dontSendNotification);
    textbox.showEditor();
    textbox.grabKeyboardFocus();
    lastValue = slider->getValue();
  }

private:
  CustomRotarySlider* slider;
  CustomTextbox textbox;
  CustomLabel titleLabel;
  Colour backgroundColor = Colour(40, 42, 54);
  Colour textColor = Colour(68, 71, 90);
  float cornerSize = 5.0f;
  float lastValue = 0.0f;
};