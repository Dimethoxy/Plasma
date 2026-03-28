#pragma once

#include "CustomLabel.h"
#include "PluginProcessor.h"
#include <JuceHeader.h>

class LoudnessMeterComponent
  : public Component
  , public Timer
{
public:
  LoudnessMeterComponent(PlasmaAudioProcessor& audioProcessor)
    : audioProcessor(audioProcessor)
    , inRmsLabel("In RMS",
                 FontSizes::LoudnessMeterPrimary,
                 Justification::centred)
    , inLufsLabel("In LUFS",
                  FontSizes::LoudnessMeterPrimary,
                  Justification::centred)
    , outLufsLabel("Out LUFS",
                   FontSizes::LoudnessMeterPrimary,
                   Justification::centred)
    , outRmsLabel("Out RMS",
                  FontSizes::LoudnessMeterPrimary,
                  Justification::centred)
    , inRmsValueLabel("-64db",
                      FontSizes::LoudnessMeterAverage,
                      Justification::centred)
    , inLufsValueLabel("-70db",
                       FontSizes::LoudnessMeterAverage,
                       Justification::centred)
    , outLufsValueLabel("-70db",
                        FontSizes::LoudnessMeterAverage,
                        Justification::centred)
    , outRmsValueLabel("-64db",
                       FontSizes::LoudnessMeterAverage,
                       Justification::centred)
    , inRmsPeakLabel("(-64db)",
                     FontSizes::LoudnessMeterPeak,
                     Justification::centred)
    , inLufsPeakLabel("(-70db)",
                      FontSizes::LoudnessMeterPeak,
                      Justification::centred)
    , outLufsPeakLabel("(-70db)",
                       FontSizes::LoudnessMeterPeak,
                       Justification::centred)
    , outRmsPeakLabel("(-64db)",
                      FontSizes::LoudnessMeterPeak,
                      Justification::centred)
  {
    addAndMakeVisible(inRmsLabel);
    addAndMakeVisible(inLufsLabel);
    addAndMakeVisible(outLufsLabel);
    addAndMakeVisible(outRmsLabel);
    addAndMakeVisible(inRmsValueLabel);
    addAndMakeVisible(inLufsValueLabel);
    addAndMakeVisible(outLufsValueLabel);
    addAndMakeVisible(outRmsValueLabel);
    addAndMakeVisible(inRmsPeakLabel);
    addAndMakeVisible(inLufsPeakLabel);
    addAndMakeVisible(outLufsPeakLabel);
    addAndMakeVisible(outRmsPeakLabel);

    inRmsLabel.setInterceptsMouseClicks(false, false);
    inLufsLabel.setInterceptsMouseClicks(false, false);
    outLufsLabel.setInterceptsMouseClicks(false, false);
    outRmsLabel.setInterceptsMouseClicks(false, false);
    inRmsValueLabel.setInterceptsMouseClicks(false, false);
    inLufsValueLabel.setInterceptsMouseClicks(false, false);
    outLufsValueLabel.setInterceptsMouseClicks(false, false);
    outRmsValueLabel.setInterceptsMouseClicks(false, false);
    inRmsPeakLabel.setInterceptsMouseClicks(false, false);
    inLufsPeakLabel.setInterceptsMouseClicks(false, false);
    outLufsPeakLabel.setInterceptsMouseClicks(false, false);
    outRmsPeakLabel.setInterceptsMouseClicks(false, false);

    inRmsLabel.setColour(Label::textColourId, fontColor);
    inLufsLabel.setColour(Label::textColourId, fontColor);
    outLufsLabel.setColour(Label::textColourId, fontColor);
    outRmsLabel.setColour(Label::textColourId, fontColor);
    inRmsValueLabel.setColour(Label::textColourId, fontColor);
    inLufsValueLabel.setColour(Label::textColourId, fontColor);
    outLufsValueLabel.setColour(Label::textColourId, fontColor);
    outRmsValueLabel.setColour(Label::textColourId, fontColor);
    inRmsPeakLabel.setColour(Label::textColourId, fontColor);
    inLufsPeakLabel.setColour(Label::textColourId, fontColor);
    outLufsPeakLabel.setColour(Label::textColourId, fontColor);
    outRmsPeakLabel.setColour(Label::textColourId, fontColor);

    startTimerHz(60);
  }

  ~LoudnessMeterComponent() override {}

  void timerCallback() override
  {
    updateMeterValueLabels();
    repaint();
  }

  void paint(Graphics& g) override
  {
    const auto bounds = getLocalBounds().toFloat();
    const auto inRmsBounds = getScopeBounds(bounds, kInRmsScope);
    const auto inLufsBounds = getScopeBounds(bounds, kInLufsScope);
    const auto outLufsBounds = getScopeBounds(bounds, kOutLufsScope);
    const auto outRmsBounds = getScopeBounds(bounds, kOutRmsScope);

    drawRmsScope(g,
                 inRmsBounds,
                 audioProcessor.rmsLevelLeftIn,
                 audioProcessor.rmsLevelRightIn);
    drawLufsScope(g,
                  inLufsBounds,
                  audioProcessor.momentaryLoudnessLeftIn,
                  audioProcessor.momentaryLoudnessRightIn);
    drawLufsScope(g,
                  outLufsBounds,
                  audioProcessor.momentaryLoudnessLeftOut,
                  audioProcessor.momentaryLoudnessRightOut);
    drawRmsScope(g,
                 outRmsBounds,
                 audioProcessor.rmsLevelLeftOut,
                 audioProcessor.rmsLevelRightOut);
  }

  void setCornerRadius(float cornerRadius)
  {
    this->cornerRadius = cornerRadius;
  }

  void resized() override
  {
    const auto bounds = getLocalBounds().toFloat();
    const auto inRmsBounds = getScopeBounds(bounds, kInRmsScope);
    const auto inLufsBounds = getScopeBounds(bounds, kInLufsScope);
    const auto outLufsBounds = getScopeBounds(bounds, kOutLufsScope);
    const auto outRmsBounds = getScopeBounds(bounds, kOutRmsScope);

    layoutScopeLabel(inRmsLabel, inRmsBounds);
    layoutScopeLabel(inLufsLabel, inLufsBounds);
    layoutScopeLabel(outLufsLabel, outLufsBounds);
    layoutScopeLabel(outRmsLabel, outRmsBounds);

    layoutScopeValueLabel(inRmsValueLabel, inRmsBounds);
    layoutScopeValueLabel(inLufsValueLabel, inLufsBounds);
    layoutScopeValueLabel(outLufsValueLabel, outLufsBounds);
    layoutScopeValueLabel(outRmsValueLabel, outRmsBounds);

    layoutScopePeakLabel(inRmsPeakLabel, inRmsBounds);
    layoutScopePeakLabel(inLufsPeakLabel, inLufsBounds);
    layoutScopePeakLabel(outLufsPeakLabel, outLufsBounds);
    layoutScopePeakLabel(outRmsPeakLabel, outRmsBounds);

    // Keep label font sizes in sync with the scaled bounds.
    resizeAllLabels();
  }

  void setBackgroundColor(Colour c) { backgroundColor = c; }

  void setAccentColor(Colour c) { accentColor = c; }

  void setFontColor(Colour c)
  {
    fontColor = c;
    inRmsLabel.setColour(Label::textColourId, c);
    inLufsLabel.setColour(Label::textColourId, c);
    outLufsLabel.setColour(Label::textColourId, c);
    outRmsLabel.setColour(Label::textColourId, c);
    inRmsValueLabel.setColour(Label::textColourId, c);
    inLufsValueLabel.setColour(Label::textColourId, c);
    outLufsValueLabel.setColour(Label::textColourId, c);
    outRmsValueLabel.setColour(Label::textColourId, c);
    inRmsPeakLabel.setColour(Label::textColourId, c);
    inLufsPeakLabel.setColour(Label::textColourId, c);
    outLufsPeakLabel.setColour(Label::textColourId, c);
    outRmsPeakLabel.setColour(Label::textColourId, c);
    repaint();
  }

private:
  static constexpr int numberOfScopes = 4;
  static constexpr int kInRmsScope = 0;
  static constexpr int kInLufsScope = 1;
  static constexpr int kOutLufsScope = 2;
  static constexpr int kOutRmsScope = 3;

  static constexpr int labelSmoothingHz = 60;
  static constexpr int labelSmoothingSeconds = 1;
  static constexpr int labelSmoothingSamples =
    labelSmoothingHz * labelSmoothingSeconds;

  int getTopLabelHeight(Rectangle<float> scopeBounds) const
  {
    return int(scopeBounds.getHeight() * 0.12f);
  }

  int getValueLabelHeight(Rectangle<float> scopeBounds) const
  {
    return int(scopeBounds.getHeight() * 0.08f);
  }

  int getPeakLabelHeight(Rectangle<float> scopeBounds) const
  {
    return int(scopeBounds.getHeight() * 0.06f);
  }

  int getLabelGap(Rectangle<float> scopeBounds) const
  {
    return std::max(1, int(scopeBounds.getHeight() * 0.01f));
  }

  Rectangle<float> getScopeBounds(Rectangle<float> bounds, int scopeIndex)
  {
    const auto scopeWidth = bounds.getWidth() / float(numberOfScopes);
    auto scopeBounds =
      bounds.withTrimmedLeft(scopeWidth * scopeIndex).withWidth(scopeWidth);
    scopeBounds = scopeBounds.reduced(bounds.getHeight() / 24.0f);
    const float horizontalInset =
      std::max(1.0f, scopeBounds.getWidth() * 0.04f);
    return scopeBounds.reduced(horizontalInset,
                               scopeBounds.getHeight() * 0.025f);
  }

  Rectangle<float> getMeterBounds(Rectangle<float> scopeBounds)
  {
    const float meterWidth = scopeBounds.getWidth() * 0.40f;
    const float meterHeight = scopeBounds.getHeight() * 0.78f;
    const float meterY = scopeBounds.getY() + scopeBounds.getHeight() * 0.1f;
    return Rectangle<float>(scopeBounds.getCentreX() - meterWidth * 0.5f,
                            meterY,
                            meterWidth,
                            meterHeight);
  }

  void layoutScopeLabel(CustomLabel& label, Rectangle<float> scopeBounds)
  {
    const int labelWidth = int(scopeBounds.getWidth());
    const int labelHeight = getTopLabelHeight(scopeBounds);
    const int labelX = int(scopeBounds.getCentreX() - (labelWidth / 2.0f));
    const int labelY = int(scopeBounds.getY());
    label.setBounds(labelX, labelY, labelWidth, labelHeight);
  }

  void layoutScopeValueLabel(CustomLabel& label, Rectangle<float> scopeBounds)
  {
    const int labelWidth = int(scopeBounds.getWidth() * 0.86f);
    const int labelHeight = getValueLabelHeight(scopeBounds);
    const int peakLabelHeight = getPeakLabelHeight(scopeBounds);
    const int labelGap = getLabelGap(scopeBounds);
    const int verticalOffset = int(scopeBounds.getHeight() * 0.04f);
    const int labelX = int(scopeBounds.getCentreX() - (labelWidth / 2.0f));
    const int labelY = int(scopeBounds.getBottom() - peakLabelHeight -
                           labelGap - labelHeight + verticalOffset);
    label.setBounds(labelX, labelY, labelWidth, labelHeight);
  }

  void layoutScopePeakLabel(CustomLabel& label, Rectangle<float> scopeBounds)
  {
    const int labelWidth = int(scopeBounds.getWidth() * 0.86f);
    const int labelHeight = getPeakLabelHeight(scopeBounds);
    const int verticalOffset = int(scopeBounds.getHeight() * 0.04f);
    const int labelX = int(scopeBounds.getCentreX() - (labelWidth / 2.0f));
    const int labelY =
      int(scopeBounds.getBottom() - labelHeight + verticalOffset);
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

  String formatDbPeakText(float dbValue) const
  {
    return "(" + formatDbValueText(dbValue) + ")";
  }

  float sanitizeLufsValue(float lufsValue) const
  {
    if (!std::isfinite(lufsValue)) {
      return -70.0f;
    }

    return std::clamp(lufsValue, -70.0f, 6.0f);
  }

  String formatLufsValueText(float lufsValue) const
  {
    const int displayLufs = int(std::round(lufsValue));
    return String(displayLufs) + "db";
  }

  String formatLufsPeakText(float lufsValue) const
  {
    return "(" + formatLufsValueText(lufsValue) + ")";
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

  float getAverageDb(const std::deque<float>& history,
                     float sum,
                     float fallbackValue) const
  {
    if (history.empty()) {
      return fallbackValue;
    }

    return sum / float(history.size());
  }

  float getPeakDb(const std::deque<float>& history, float fallbackValue) const
  {
    if (history.empty()) {
      return fallbackValue;
    }

    return *std::max_element(history.begin(), history.end());
  }

  void updateMeterValueLabels()
  {
    const auto inDb = getCombinedDbValue(audioProcessor.rmsLevelLeftIn,
                                         audioProcessor.rmsLevelRightIn);
    const auto outDb = getCombinedDbValue(audioProcessor.rmsLevelLeftOut,
                                          audioProcessor.rmsLevelRightOut);
    const auto inLufs = sanitizeLufsValue(audioProcessor.momentaryLoudnessIn);
    const auto outLufs = sanitizeLufsValue(audioProcessor.momentaryLoudnessOut);

    pushDbSample(inRmsHistory, inRmsHistorySum, inDb);
    pushDbSample(outRmsHistory, outRmsHistorySum, outDb);
    pushDbSample(inLufsHistory, inLufsHistorySum, inLufs);
    pushDbSample(outLufsHistory, outLufsHistorySum, outLufs);

    inRmsValueLabel.setText(
      formatDbValueText(getAverageDb(inRmsHistory, inRmsHistorySum, -64.0f)),
      dontSendNotification);
    outRmsValueLabel.setText(
      formatDbValueText(getAverageDb(outRmsHistory, outRmsHistorySum, -64.0f)),
      dontSendNotification);
    inRmsPeakLabel.setText(formatDbPeakText(getPeakDb(inRmsHistory, -64.0f)),
                           dontSendNotification);
    outRmsPeakLabel.setText(formatDbPeakText(getPeakDb(outRmsHistory, -64.0f)),
                            dontSendNotification);

    inLufsValueLabel.setText(formatLufsValueText(getAverageDb(
                               inLufsHistory, inLufsHistorySum, -70.0f)),
                             dontSendNotification);
    outLufsValueLabel.setText(formatLufsValueText(getAverageDb(
                                outLufsHistory, outLufsHistorySum, -70.0f)),
                              dontSendNotification);
    inLufsPeakLabel.setText(
      formatLufsPeakText(getPeakDb(inLufsHistory, -70.0f)),
      dontSendNotification);
    outLufsPeakLabel.setText(
      formatLufsPeakText(getPeakDb(outLufsHistory, -70.0f)),
      dontSendNotification);
  }

  void resizeAllLabels()
  {
    inRmsLabel.resize();
    inLufsLabel.resize();
    outLufsLabel.resize();
    outRmsLabel.resize();
    inRmsValueLabel.resize();
    inLufsValueLabel.resize();
    outLufsValueLabel.resize();
    outRmsValueLabel.resize();
    inRmsPeakLabel.resize();
    inLufsPeakLabel.resize();
    outLufsPeakLabel.resize();
    outRmsPeakLabel.resize();
  }

  void drawStereoScope(Graphics& g,
                       Rectangle<float> scopeBounds,
                       float leftValue,
                       float rightValue,
                       float minValue,
                       float maxValue)
  {
    const auto meterInnerBounds = getMeterBounds(scopeBounds).toNearestInt();

    g.setColour(fontColor);
    const int meterBorderThickness =
      std::max(1, int(std::round(meterInnerBounds.getWidth() * 0.08f)));
    g.drawRect(meterInnerBounds, meterBorderThickness);

    const auto barBounds = meterInnerBounds.reduced(meterBorderThickness * 2);
    if (barBounds.getWidth() < 3 || barBounds.getHeight() < 1) {
      return;
    }

    const int channelGap =
      std::max(1, int(std::round(float(barBounds.getWidth()) * 0.15f)));
    const int channelWidth = (barBounds.getWidth() - channelGap) / 2;
    if (channelWidth <= 0) {
      return;
    }

    const auto leftBarRawBounds = Rectangle<int>(
      barBounds.getX(), barBounds.getY(), channelWidth, barBounds.getHeight());
    const auto rightBarRawBounds =
      Rectangle<int>(leftBarRawBounds.getRight() + channelGap,
                     barBounds.getY(),
                     channelWidth,
                     barBounds.getHeight());

    const float leftRawValue = std::clamp(leftValue, minValue, maxValue);
    const float rightRawValue = std::clamp(rightValue, minValue, maxValue);
    const float leftNormalizedValue =
      (leftRawValue - minValue) / (maxValue - minValue);
    const float rightNormalizedValue =
      (rightRawValue - minValue) / (maxValue - minValue);

    const float rawHeight = float(barBounds.getHeight());
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

  void drawRmsScope(Graphics& g,
                    Rectangle<float> scopeBounds,
                    float leftGain,
                    float rightGain)
  {
    const float minValue = -64.0f;
    const float maxValue = 16.0f;
    const float leftDb =
      std::clamp(juce::Decibels::gainToDecibels(leftGain), minValue, maxValue);
    const float rightDb =
      std::clamp(juce::Decibels::gainToDecibels(rightGain), minValue, maxValue);
    drawStereoScope(g, scopeBounds, leftDb, rightDb, minValue, maxValue);
  }

  void drawLufsScope(Graphics& g,
                     Rectangle<float> scopeBounds,
                     float leftLufs,
                     float rightLufs)
  {
    const float minValue = -70.0f;
    const float maxValue = 6.0f;
    drawStereoScope(g,
                    scopeBounds,
                    sanitizeLufsValue(leftLufs),
                    sanitizeLufsValue(rightLufs),
                    minValue,
                    maxValue);
  }

  PlasmaAudioProcessor& audioProcessor;
  CustomLabel inRmsLabel;
  CustomLabel inLufsLabel;
  CustomLabel outLufsLabel;
  CustomLabel outRmsLabel;
  CustomLabel inRmsValueLabel;
  CustomLabel inLufsValueLabel;
  CustomLabel outLufsValueLabel;
  CustomLabel outRmsValueLabel;
  CustomLabel inRmsPeakLabel;
  CustomLabel inLufsPeakLabel;
  CustomLabel outLufsPeakLabel;
  CustomLabel outRmsPeakLabel;
  std::deque<float> inRmsHistory;
  std::deque<float> inLufsHistory;
  std::deque<float> outLufsHistory;
  std::deque<float> outRmsHistory;
  float inRmsHistorySum = 0.0f;
  float inLufsHistorySum = 0.0f;
  float outLufsHistorySum = 0.0f;
  float outRmsHistorySum = 0.0f;
  float cornerRadius = 5.0f;
  Colour backgroundColor = Colours::black;
  Colour accentColor = Colours::green;
  Colour fontColor = Colours::white;
};