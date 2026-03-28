#pragma once

#include "CustomRotarySlider.h"
#include "PluginEditor.h"

void
CustomRotarySlider::mouseDown(const MouseEvent& e)
{

  ModifierKeys modifiers = ModifierKeys::getCurrentModifiersRealtime();

  if (modifiers.isShiftDown())
    this->setMouseDragSensitivity(4000);
  else
    this->setMouseDragSensitivity(200);

  if (modifiers.isRightButtonDown()) {
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
  } else if (modifiers.isCtrlDown() || modifiers.isCommandDown() ||
             modifiers.isMiddleButtonDown()) {
    auto* parent = getParentComponent();
    auto* editor = dynamic_cast<PlasmaAudioProcessorEditor*>(parent);
    auto& valueEditor = editor->getValueEditor();
    valueEditor.setVisible(true);
    valueEditor.setSlider(this);
  } else {
    Slider::mouseDown(e); // to the usual thing .... drag the slider
  }
}

void
CustomRotarySlider::paint(juce::Graphics& g)
{
  auto startAngleRadian = degreesToRadians(180.0f + 45.0f);
  auto endAngleRadian =
    degreesToRadians(180.0f - 45.0f) + MathConstants<float>::twoPi;
  auto range = getRange();
  auto sliderBounds = getSliderBounds();

  g.setColour(Colours::yellow);
  // g.drawRect(sliderBounds);

  getLookAndFeel().drawRotarySlider(
    g,
    sliderBounds.getX(),
    sliderBounds.getY(),
    sliderBounds.getWidth(),
    sliderBounds.getHeight(),
    jmap(getValue(), range.getStart(), range.getEnd(), 0.0, 1.0),
    startAngleRadian,
    endAngleRadian,
    *this);
}

Rectangle<int>
CustomRotarySlider::getSliderBounds() const
{
  return getLocalBounds();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tooltips
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
String
CustomRotarySlider::getTooltipString()
{
  int selectedOption = (int)getValue();
  if (getName() == "Distortion") {
    switch ((int)selectedOption) {
      case Hardclip:
        return ("Distortion Type : Hard Clip");
        break;
      case Softclip:
        return ("Distortion Type : Soft Clip");
        break;
      case Saturate:
        return ("Distortion Type : Saturate");
        break;
      case Atan:
        return ("Distortion Type : Atan");
        break;
      case Crunch:
        return ("Distortion Type : Crunch");
        break;
      case Bitcrush:
        return ("Distortion Type : Bitcrush");
        break;
      case Extreme:
        return ("Distortion Type : Extreme");
        break;
      case Scream:
        return ("Distortion Type : Scream");
        break;
      case Sine:
        return ("Distortion Type : Sine");
        break;
      case Cosine:
        return ("Distortion Type : Cosine");
        break;
      case Harmonize:
        return ("Distortion Type : Harmonize");
        break;
      case Weird:
        return ("Distortion Type : Weird");
        break;
    }
  } else if (getName() == "Slope") {
    if (selectedOption >= 8)
      return "Slope : Peak Only";
    int slope = (selectedOption + 1) * 12;
    String str;
    str << "Slope : ";
    str << slope;
    str << " db/oct";
    return (str);
  } else if (getName() == "Symmetry") {
    auto value = round(getValue() * 100);
    String str;
    str << "Symmetry : ";
    if (value == 0) {
      str << "Centered";
    } else {
      str << value;
      str << "%";
    }
    return str;
  } else if (getName() == "Analyser Type") {
    AnalyserType analyserType = static_cast<AnalyserType>(selectedOption);
    String str = getAnalyserName(analyserType);
    return "Analyser Type : " + str;
  } else if (getName() == "Lowpass" || getName() == "Highpass" ||
             getName() == "Peak") {
    String str;
    str << (round(getValue() * 100)) / 100;
    return (String)getName() + " : " + str + " " + (String)getTextValueSuffix();
  } else if (getName() == "Peak Resonance") {
    String str;
    str << (round(getValue() * 100)) / 100;
    return "Resonance : " + str + " " + (String)getTextValueSuffix();
  } else if (getName() == "Dual Peak Resonance") {
    String str;
    str << (round(getValue() * 100)) / 100;
    return "Resonance : " + str + " " + (String)getTextValueSuffix();
  } else if (getName() == "Drive") {
    String str;
    str << round((getValue() - 1) * 10);
    return "Drive : " + str + "%";
  } else if (getName() == "Girth") {
    int value = round(getValue() * 100);
    if (value >= 0) {
      String str;
      str << value;
      str << "%";
      return (String)getName() + " Stereo : " + str + " " +
             (String)getTextValueSuffix();
    } else {
      String str;
      str << -value;
      str << "%";
      return (String)getName() + " Mono : " + str + " " +
             (String)getTextValueSuffix();
    }
  } else {
    String str;
    str << (round(getValue() * 100)) / 100;
    return (String)getName() + " : " + str + "" + (String)getTextValueSuffix();
  }
  return "";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Analyser Name
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
String
CustomRotarySlider::getAnalyserName(AnalyserType analyserType)
{
  switch (analyserType) {
    case AnalyserType::Automatic: {
      return "Automatic";
      break;
    }
    case AnalyserType::Options: {
      return "Options";
      break;
    }
    case AnalyserType::Response: {
      return "Filter Response";
      break;
    }
    case AnalyserType::Shapercurve: {
      return "Shapercurve";
      break;
    }
    case AnalyserType::Loudness: {
      return "Loudness";
      break;
    }
    case AnalyserType::Waveform: {
      return "Waveform";
      break;
    }
  }
  return "Unknown Analyser Type";
}
