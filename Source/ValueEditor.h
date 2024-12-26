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
    textbox.setBoundsRelative(0.35f, 0.52f, 0.3f, 0.12f);
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

  const String readValue(CustomRotarySlider* slider)
  {
    const auto rawValue = slider->getValue();
    const String name = slider->getName();
    if (name == "Symmetry") {
      return String(rawValue * 100.0f);
    } else if (name == "Girth") {
      return String(rawValue * 100.0f);
    } else if (name == "Drive") {
      return String((rawValue - 1.0f) * 10.0f);
    } else if (name == "Slope") {
      int slope = static_cast<int>((rawValue + 1) * 12.0f);
      if (slope <= 96) {
        return String(slope);
      } else {
        return String("Bypass");
      }
    } else if (name == "Distortion") {
      const int dist = static_cast<int>(rawValue);
      if (dist == 0) {
        return String("Hard Clip");
      } else if (dist == 1) {
        return String("Soft Clip");
      } else if (dist == 2) {
        return String("Saturate");
      } else if (dist == 3) {
        return String("Atan");
      } else if (dist == 4) {
        return String("Crunch");
      } else if (dist == 5) {
        return String("Bitcrush");
      } else if (dist == 6) {
        return String("Extreme");
      } else if (dist == 7) {
        return String("Scream");
      } else if (dist == 8) {
        return String("Sine");
      } else if (dist == 9) {
        return String("Cosine");
      } else if (dist == 10) {
        return String("Harmonize");
      } else if (dist == 11) {
        return String("Weird");
      };
    }
    return String(rawValue);
  }

  const float writeValue(String value)
  {
    if (name == "Symmetry") {
      return value.getFloatValue() / 100.0f;
    } else if (name == "Girth") {
      return value.getFloatValue() / 100.0f;
    } else if (name == "Drive") {
      return (value.getFloatValue() / 10.0f) + 1.0f;
    } else if (name == "Slope") {
      if (value == "Bypass") {
        return 7.0f;
      } else {
        return (value.getFloatValue() / 12.0f) - 1.0f;
      }
    } else if (name == "Distortion") {
      if (value == "Hard Clip") {
        return 0.0f;
      } else if (value == "Soft Clip") {
        return 1.0f;
      } else if (value == "Saturate") {
        return 2.0f;
      } else if (value == "Atan") {
        return 3.0f;
      } else if (value == "Crunch") {
        return 4.0f;
      } else if (value == "Bitcrush") {
        return 5.0f;
      } else if (value == "Extreme") {
        return 6.0f;
      } else if (value == "Scream") {
        return 7.0f;
      } else if (value == "Sine") {
        return 8.0f;
      } else if (value == "Cosine") {
        return 9.0f;
      } else if (value == "Harmonize") {
        return 10.0f;
      } else if (value == "Weird") {
        return 11.0f;
      }
    }
    return value.getFloatValue();
  }

  void setSlider(CustomRotarySlider* slider)
  {
    this->slider = slider;
    this->name = slider->getName();
    titleLabel.setText(slider->getName() + ":", dontSendNotification);
    const auto convertedValue = readValue(slider);
    textbox.setText(convertedValue, dontSendNotification);
    textbox.showEditor();
    textbox.grabKeyboardFocus();
    lastValue = slider->getValue();
  }

  void textEditorHide()
  {
    const String newText = textbox.getText();
    const float newValue = writeValue(newText);
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
  String name = "Value Editor";
  CustomTextbox textbox;
  CustomLabel titleLabel;
  Colour backgroundColor = Colour(40, 42, 54);
  Colour textColor = Colour(68, 71, 90);
  float cornerSize = 5.0f;
  float lastValue = 0.0f;
};