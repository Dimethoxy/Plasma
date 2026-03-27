#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

class LoudnessMeterComponent
  : public Component
  , public Timer
{
public:
  LoudnessMeterComponent(PlasmaAudioProcessor& audioProcessor)
    : audioProcessor(audioProcessor)
  {
    startTimerHz(60);
  }

  ~LoudnessMeterComponent() override {}

  void timerCallback() override { this->repaint(); }

  void paint(Graphics& g) override
  {
    const auto bounds = getLocalBounds().toFloat();
    const auto widht = bounds.getWidth();
    const auto height = bounds.getHeight();
    // g.setColour(backgroundColor);
    // g.fillRoundedRectangle(bounds, cornerRadius);

    const auto inBounds =
      bounds.withTrimmedRight(widht / 2).reduced(height / 24);
    // g.setColour(Colours::red);
    // g.fillRoundedRectangle(inBounds, cornerRadius);

    const auto inMeterBounds =
      inBounds.withTrimmedRight(inBounds.getWidth() * 0.60f);
    // g.setColour(accentColor);
    // g.fillRoundedRectangle(inMeterBounds, cornerRadius);

    const float trimFactor = 0.0f;
    const auto inMeterInnerBounds =
      inMeterBounds.reduced(0.3f * inMeterBounds.getWidth())
        .withTrimmedRight(inMeterBounds.getWidth() * trimFactor)
        .withTrimmedLeft(inMeterBounds.getWidth() * trimFactor)
        .toNearestInt();
    g.setColour(fontColor);
    const int meterBorderThickness = int(inMeterInnerBounds.getWidth() * 0.08f);
    g.drawRect(inMeterInnerBounds, meterBorderThickness);

    const auto barBounds = inMeterInnerBounds.reduced(meterBorderThickness * 2);
    const auto leftBarRawBounds = barBounds.withTrimmedRight(
      barBounds.getWidth() / 2.0f + meterBorderThickness);
    const auto rightBarRawBounds = barBounds.withTrimmedLeft(
      barBounds.getWidth() / 2.0f + meterBorderThickness / 2.0f);

    const float minValue = -64.0f;
    const float maxValue = 16.0f;
    // random number between 0 and 1
    const float leftRawValue =
      std::clamp(juce::Decibels::gainToDecibels(audioProcessor.rmsLevelLeftIn),
                 minValue,
                 maxValue);
    const float rightRawValue =
      std::clamp(juce::Decibels::gainToDecibels(audioProcessor.rmsLevelRightIn),
                 minValue,
                 maxValue);
    const float leftNormalizedValue =
      (leftRawValue - minValue) / (maxValue - minValue);
    const float rightNormalizedValue =
      (rightRawValue - minValue) / (maxValue - minValue);
    const float rawHeight = barBounds.getHeight();
    const float leftBarHeight = rawHeight * leftNormalizedValue;
    const float rightBarHeight = rawHeight * rightNormalizedValue;
    const auto leftBarBounds =
      leftBarRawBounds.withTrimmedTop(rawHeight - leftBarHeight);
    const auto rightBarBounds =
      rightBarRawBounds.withTrimmedTop(rawHeight - rightBarHeight);
    g.setColour(accentColor);
    g.fillRect(leftBarBounds);
    g.fillRect(rightBarBounds);
  }

  void setCornerRadius(float cornerRadius)
  {
    this->cornerRadius = cornerRadius;
  }

  void resized() override { auto bounds = getLocalBounds().toFloat(); }

  void setBackgroundColor(Colour c) { backgroundColor = c; }

  void setAccentColor(Colour c) { accentColor = c; }

  void setFontColor(Colour c) { fontColor = c; }

private:
  PlasmaAudioProcessor& audioProcessor;
  float cornerRadius = 5.0f;
  Colour backgroundColor = Colours::black;
  Colour accentColor = Colours::green;
  Colour fontColor = Colours::white;
  Rectangle<float> inBounds, outBounds;
};