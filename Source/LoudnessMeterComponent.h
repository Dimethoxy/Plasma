#pragma once

#include "CustomLabel.h"
#include "PluginProcessor.h"
#include <JuceHeader.h>
#include <deque>

class LoudnessMeterComponent
  : public Component
  , public Timer
{
public:
  LoudnessMeterComponent(PlasmaAudioProcessor& audioProcessor)
    : audioProcessor(audioProcessor)
    , inRmsLabel("In RMS", FontSizes::Tooltipp, Justification::centred)
    , outRmsLabel("Out RMS", FontSizes::Tooltipp, Justification::centred)
    , inRmsValueLabel("-64db", FontSizes::Tooltipp, Justification::centred)
    , outRmsValueLabel("-64db", FontSizes::Tooltipp, Justification::centred)
  {
    addAndMakeVisible(inRmsLabel);
    addAndMakeVisible(outRmsLabel);
    addAndMakeVisible(inRmsValueLabel);
    addAndMakeVisible(outRmsValueLabel);
    inRmsLabel.setInterceptsMouseClicks(false, false);
    outRmsLabel.setInterceptsMouseClicks(false, false);
    inRmsValueLabel.setInterceptsMouseClicks(false, false);
    outRmsValueLabel.setInterceptsMouseClicks(false, false);
    inRmsLabel.setColour(Label::textColourId, fontColor);
    outRmsLabel.setColour(Label::textColourId, fontColor);
    inRmsValueLabel.setColour(Label::textColourId, fontColor);
    outRmsValueLabel.setColour(Label::textColourId, fontColor);
    startTimerHz(60);
  }

  ~LoudnessMeterComponent() override {}

  void timerCallback() override
  {
    updateRmsValueLabels();
    repaint();
  }

  void paint(Graphics& g) override
  {
    const auto bounds = getLocalBounds().toFloat();
    // g.setColour(backgroundColor);
    // g.fillRoundedRectangle(bounds, cornerRadius);

    const auto inBounds = getScopeBounds(bounds, false);
    const auto outBounds = getScopeBounds(bounds, true);
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

  void resized() override
  {
    const auto bounds = getLocalBounds().toFloat();
    const auto inBounds = getScopeBounds(bounds, false);
    const auto outBounds = getScopeBounds(bounds, true);

    layoutRmsLabel(inRmsLabel, inBounds, false);
    layoutRmsLabel(outRmsLabel, outBounds, true);
    layoutRmsValueLabel(inRmsValueLabel, inBounds, false);
    layoutRmsValueLabel(outRmsValueLabel, outBounds, true);
  }

  void setBackgroundColor(Colour c) { backgroundColor = c; }

  void setAccentColor(Colour c) { accentColor = c; }

  void setFontColor(Colour c)
  {
    fontColor = c;
    inRmsLabel.setColour(Label::textColourId, c);
    outRmsLabel.setColour(Label::textColourId, c);
    inRmsValueLabel.setColour(Label::textColourId, c);
    outRmsValueLabel.setColour(Label::textColourId, c);
    repaint();
  }

private:
  static constexpr int labelSmoothingHz = 60;
  static constexpr int labelSmoothingSeconds = 1;
  static constexpr int labelSmoothingSamples =
    labelSmoothingHz * labelSmoothingSeconds;

  Rectangle<float> getScopeBounds(Rectangle<float> bounds, bool rightSide)
  {
    const auto halfBounds =
      rightSide ? bounds.withTrimmedLeft(bounds.getWidth() / 2.0f)
                : bounds.withTrimmedRight(bounds.getWidth() / 2.0f);
    const auto scopeBounds = halfBounds.reduced(bounds.getHeight() / 24.0f);

    return scopeBounds.reduced(0.0f, scopeBounds.getHeight() * 0.025f);
  }

  Rectangle<float> getMeterBounds(Rectangle<float> scopeBounds,
                                  bool alignToRight)
  {
    return alignToRight
             ? scopeBounds.withTrimmedLeft(scopeBounds.getWidth() * 0.60f)
             : scopeBounds.withTrimmedRight(scopeBounds.getWidth() * 0.60f);
  }

  void layoutRmsLabel(CustomLabel& label,
                      Rectangle<float> scopeBounds,
                      bool alignToRight)
  {
    const auto meterBounds = getMeterBounds(scopeBounds, alignToRight);
    const int labelWidth = int(meterBounds.getWidth() * 1.8f);
    const int labelHeight = int(scopeBounds.getHeight() * 0.12f);
    const int labelX = int(meterBounds.getCentreX() - (labelWidth / 2.0f));
    const int labelY = int(scopeBounds.getY());
    label.setBounds(labelX, labelY, labelWidth, labelHeight);
  }

  void layoutRmsValueLabel(CustomLabel& label,
                           Rectangle<float> scopeBounds,
                           bool alignToRight)
  {
    const auto meterBounds = getMeterBounds(scopeBounds, alignToRight);
    const int labelWidth = int(meterBounds.getWidth() * 1.5f);
    const int labelHeight = int(scopeBounds.getHeight() * 0.10f);
    const int labelX = int(meterBounds.getCentreX() - (labelWidth / 2.0f));
    const int labelY = int(scopeBounds.getBottom() - labelHeight);
    label.setBounds(labelX, labelY, labelWidth, labelHeight);
  }

  float getCombinedDbValue(float leftGain, float rightGain) const
  {
    const float minValue = -64.0f;
    const float maxValue = 16.0f;
    const float leftDb =
      std::clamp(juce::Decibels::gainToDecibels(leftGain), minValue, maxValue);
    const float rightDb =
      std::clamp(juce::Decibels::gainToDecibels(rightGain), minValue, maxValue);
    return std::max(leftDb, rightDb);
  }

  String formatDbValueText(float dbValue) const
  {
    const int displayDb = int(std::round(dbValue));
    return String(displayDb) + "db";
  }

  void pushDbSample(std::deque<float>& history, float& sum, float sample)
  {
    history.push_back(sample);
    sum += sample;

    if (int(history.size()) > labelSmoothingSamples) {
      sum -= history.front();
      history.pop_front();
    }
  }

  float getAverageDb(const std::deque<float>& history, float sum) const
  {
    if (history.empty()) {
      return -64.0f;
    }

    return sum / float(history.size());
  }

  void updateRmsValueLabels()
  {
    const auto inDb = getCombinedDbValue(audioProcessor.rmsLevelLeftIn,
                                         audioProcessor.rmsLevelRightIn);
    const auto outDb = getCombinedDbValue(audioProcessor.rmsLevelLeftOut,
                                          audioProcessor.rmsLevelRightOut);

    pushDbSample(inRmsHistory, inRmsHistorySum, inDb);
    pushDbSample(outRmsHistory, outRmsHistorySum, outDb);

    inRmsValueLabel.setText(
      formatDbValueText(getAverageDb(inRmsHistory, inRmsHistorySum)),
      dontSendNotification);
    outRmsValueLabel.setText(
      formatDbValueText(getAverageDb(outRmsHistory, outRmsHistorySum)),
      dontSendNotification);
  }

  void drawRmsScope(Graphics& g,
                    Rectangle<float> scopeBounds,
                    float leftGain,
                    float rightGain,
                    bool alignToRight)
  {
    const auto meterBounds = getMeterBounds(scopeBounds, alignToRight);

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
  CustomLabel inRmsLabel;
  CustomLabel outRmsLabel;
  CustomLabel inRmsValueLabel;
  CustomLabel outRmsValueLabel;
  std::deque<float> inRmsHistory;
  std::deque<float> outRmsHistory;
  float inRmsHistorySum = 0.0f;
  float outRmsHistorySum = 0.0f;
  float cornerRadius = 5.0f;
  Colour backgroundColor = Colours::black;
  Colour accentColor = Colours::green;
  Colour fontColor = Colours::white;
  Rectangle<float> inBounds, outBounds;
};