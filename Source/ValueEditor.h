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
    , titleLabel("Value Editor", FontSizes::Main, Justification::centredBottom)
  {
    addAndMakeVisible(textbox);
    addAndMakeVisible(titleLabel);
    textbox.onEditorHide = [this] { this->textEditorHide(); };
  }

  void resized() override
  {
    titleLabel.setBoundsRelative(0.10f, 0.0f, 0.8f, 0.49f);
    textbox.setBoundsRelative(0.37f, 0.52f, 0.26f, 0.12f);
  }

  void paint(Graphics& g) override
  {
    g.setColour(backgroundColor);
    g.fillRoundedRectangle(getLocalBounds().toFloat(), cornerSize);
    g.setColour(textColor);
    const float reduction = getWidth() * 0.13f;
    const auto innerBounds = getLocalBounds()
                               .reduced(reduction)
                               .withCentre(getLocalBounds().getCentre())
                               .toFloat();
    g.drawRoundedRectangle(innerBounds, cornerSize, reduction / 20.0f);
  }

  void setColour(Colour background, Colour text)
  {
    backgroundColor = background;
    textColor = text;
  }

  void setSlider(CustomRotarySlider* slider)
  {
    this->slider = slider;
    titleLabel.setText(slider->getName() + ":", dontSendNotification);
    textbox.setText(String(slider->getValue()), dontSendNotification);
    textbox.showEditor();
    textbox.grabKeyboardFocus();
    lastValue = slider->getValue();
  }

  void textEditorHide()
  {
    const String newText = textbox.getText();
    const float newValue = newText.getFloatValue();
    slider->setValue(newValue);
    const float setValue = slider->getValue();
    textbox.setText(String(setValue), dontSendNotification);
    setVisible(false);
  }

  void setBackgroundColor(Colour color) { backgroundColor = color; }

  void setCornerRadius(float corner) { cornerSize = corner; }

  void setFontColor(Colour color)
  {
    textbox.setColour(Label::ColourIds::textColourId, color);
    textbox.setColour(Label::ColourIds::textWhenEditingColourId, color);
    textbox.setColour(TextEditor::ColourIds::highlightedTextColourId, color);
    titleLabel.setColour(Label::ColourIds::textColourId, color);
    textColor = color;
    repaint();
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