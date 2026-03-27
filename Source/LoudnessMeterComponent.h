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
    const auto outBounds =
      bounds.withTrimmedLeft(widht / 2).reduced(height / 24);
    // g.setColour(Colours::red);
    // g.fillRoundedRectangle(inBounds, cornerRadius);

    drawRmsScope(g,
                 inBounds,
                 audioProcessor.rmsLevelLeftIn,
                 audioProcessor.rmsLevelRightIn,
                 false);
    drawRmsScope(g,
                 outBounds,
                 audioProcessor.rmsLevelLeftOut,
                 audioProcessor.rmsLevelRightOut,
                 true);
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
  void drawRmsScope(Graphics& g,
                    Rectangle<float> scopeBounds,
                    float leftGain,
                    float rightGain,
                    bool alignToRight)
  {
    const auto meterBounds =
      alignToRight
        ? scopeBounds.withTrimmedLeft(scopeBounds.getWidth() * 0.60f)
        : scopeBounds.withTrimmedRight(scopeBounds.getWidth() * 0.60f);

    const float trimFactor = 0.0f;
    const auto meterInnerBounds =
      meterBounds.reduced(0.3f * meterBounds.getWidth())
        .withTrimmedRight(meterBounds.getWidth() * trimFactor)
        .withTrimmedLeft(meterBounds.getWidth() * trimFactor)
        .toNearestInt();

    g.setColour(fontColor);
    const int meterBorderThickness = int(meterInnerBounds.getWidth() * 0.08f);
    g.drawRect(meterInnerBounds, meterBorderThickness);

    const auto barBounds = meterInnerBounds.reduced(meterBorderThickness * 2);
    const auto leftBarRawBounds = barBounds.withTrimmedRight(
      barBounds.getWidth() / 2.0f + meterBorderThickness);
    const auto rightBarRawBounds = barBounds.withTrimmedLeft(
      barBounds.getWidth() / 2.0f + meterBorderThickness / 2.0f);

    const float minValue = -64.0f;
    const float maxValue = 16.0f;
    const float leftRawValue =
      std::clamp(juce::Decibels::gainToDecibels(leftGain), minValue, maxValue);
    const float rightRawValue =
      std::clamp(juce::Decibels::gainToDecibels(rightGain), minValue, maxValue);
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

  PlasmaAudioProcessor& audioProcessor;
  float cornerRadius = 5.0f;
  Colour backgroundColor = Colours::black;
  Colour accentColor = Colours::green;
  Colour fontColor = Colours::white;
  Rectangle<float> inBounds, outBounds;
};