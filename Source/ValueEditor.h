#pragma once

#include "CustomLabel.h"
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
    : textbox("Default Value", FontSizes::Main, Justification::centredLeft)
  {
    addAndMakeVisible(textbox);
    textbox.showEditor();
    textbox.grabKeyboardFocus();
  }

  void resized() override
  {
    textbox.setBoundsRelative(0.40f, 0.44f, 0.2f, 0.12f);
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

private:
  CustomTextbox textbox;
  Colour backgroundColor = Colour(40, 42, 54);
  Colour textColor = Colour(68, 71, 90);
  float cornerSize = 5.0f;
};