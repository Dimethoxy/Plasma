#pragma once

#include "CustomLabel.h"
#include "CustomRotarySlider.h"
#include "CustomTextButton.h"
#include "LoudnessMeterComponent.h"
#include "PlasmaLabel.h"
#include "PluginProcessor.h"
#include "ResponseCurveComponent.h"
#include "ShapercurveComponent.h"
#include "ValueEditor.h"
#include "Version.h"
#include <JuceHeader.h>

//=============================================================================================

const juce::String PLASMA_VERSION = ProjectInfo::versionString;
//

const Colour backgroundColorFactory = Colour(40, 42, 54);
const Colour foregroundColorFactory = Colour(68, 71, 90);
const Colour accentColorFactory = Colour(80, 250, 123);

//=============================================================================================

class PlasmaAudioProcessorEditor
  : public AudioProcessorEditor
  , public MultiTimer
  , public Button::Listener
  , public Slider::Listener
  , public Label::Listener
{
public:
  PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
  ~PlasmaAudioProcessorEditor() override;

  void paint(juce::Graphics&) override;
  void resized() override;

  void timerCallback(int timerID) override;
  void buttonClicked(Button* button) override;
  void sliderValueChanged(Slider* slider) override;
  void sliderDragStarted(Slider* slider) override;
  void sliderDragEnded(Slider* slider) override;
  void labelTextChanged(Label* label) override;
  void editorHidden(Label* label, TextEditor& textEditor) override;

  // Colors
  Colour getBackgroundColor();
  Colour getForegroundColor();
  Colour getAccentColor();
  Colour getFontColor();
  Colour getOptionsFontColor();

  void setBackgroundColor(Colour c);
  void setForegroundColor(Colour c);
  void setAccentColor(Colour c);
  void setFontColor(Colour c);
  void setOptionsFontColor(Colour c);
  void updateTextboxes();
  ValueEditor& getValueEditor();

private:
  // Scaling
  CustomTextButton scaleUpButton, scaleDownButton, configButton,
    safeConfigButton, resetConfigButton, updateButton;

  // Audio Processor
  PlasmaAudioProcessor& audioProcessor;

  // Config
  ApplicationProperties applicationProperties;
  PropertiesFile::Options options;
  int scale = 100;
  bool showConfig = false;
  void configWindow(bool visibility);
  WaveformComponent* waveformComponent;
  AnalyserType autoAnalyserType;
  bool isAutoAnalyser;
  void setAnalyserType(AnalyserType analyser);
  AnalyserType lastAnalyserType = AnalyserType::Automatic;
  int cornerRadius = 5;
  int cornerRadiusFallback = 5;

  // Sliders
  CustomRotarySlider
    // Drive
    gainSlider,
    driveSlider, girthSlider, biasSlider, driveTypeSlider,
    // Highpass
    highPassFreqSlider, highPassResonanceSlider, highPassResonanceQualitySlider,
    highPassSlopeSlider,
    // Peak
    peakStereoSlider, peakFreqSlider, peakGainSlider, peakQualitySlider,
    // DualPeak
    dualPeakWidthSlider, dualPeakFreqSlider, dualPeakGainSlider,
    dualPeakQualitySlider,
    // Lowpass
    lowPassFreqSlider, lowPassResonanceSlider, lowPassResonanceQualitySlider,
    lowPassSlopeSlider,
    // lateDrive
    lateBiasSlider, lateDriveTypeSlider, lateGirthSlider, lateDriveSlider,
    preGainSlider,
    // Output
    mixSlider, analyserSlider;

  // Response Curve Component
  ResponseCurveComponent responseCurveComponent;
  ShapercurveComponent earlyShapercurveComponent;
  ShapercurveComponent lateShapercurveComponent;

  // Loudness Meter Components
  LoudnessMeterComponent loudnessMeterComponent;

  // Value Editor
  ValueEditor valueEditor;

  // Attachments
  using APVTS = juce::AudioProcessorValueTreeState;
  using Attachment = APVTS::SliderAttachment;
  Attachment highPassFreqSliderAttachment, lowPassFreqSliderAttachment,
    biasSliderAttachment, lateBiasSliderAttachment, driveTypeSliderAttachment,
    lateDriveTypeSliderAttachment, highPassResonanceSliderAttachment,
    lowPassResonanceSliderAttachment, peakStereoSliderAttachment,
    peakFreqSliderAttachment, peakGainSliderAttachment,
    peakQualitySliderAttachment, dualPeakWidthSliderAttachment,
    dualPeakFreqSliderAttachment, dualPeakGainSliderAttachment,
    dualPeakQualitySliderAttachment, highPassResonanceQualitySliderAttachment,
    lowPassResonanceQualitySliderAttachment, highPassSlopeSliderAttachment,
    lowPassSlopeSliderAttachment, preGainSliderAttachment,
    driveSliderAttachment, girthSliderAttachment, lateGirthSliderAttachment,
    lateDriveSliderAttachment, gainSliderAttachment, analyserSliderAttachment,
    mixSliderAttachment;

  // Layout
  float sc(float val);
  Rectangle<int> headerArea();
  Rectangle<int> monitorArea();
  Rectangle<int> inArea();
  Rectangle<int> outArea();
  Rectangle<int> earlyArea();
  Rectangle<int> highpassArea();
  Rectangle<int> peakArea();
  Rectangle<int> dualPeakArea();
  Rectangle<int> lowpassArea();
  Rectangle<int> lateArea();
  int boxWidth = 135;
  int boxHeight = 550;

  // Fontsizes
  float fs_mainLabel();
  float fs_titelLabel();
  float padding = 10.0f;
  float knobLabelHeight = 0.80f;

  // Labels
  PlasmaLabel plasmaLabel;
  CustomLabel tooltipLabel,
    // Drive
    gainLabel, driveLabel, girthLabel, biasLabel, driveTypeLabel,
    // Highpass
    highPassFreqLabel, highPassResonanceLabel, highPassResonanceQualityLabel,
    highPassSlopeLabel,
    // Peak
    peakStereoLabel, peakFreqLabel, peakGainLabel, peakQualityLabel,
    // Dual Peak
    dualPeakWidthLabel, dualPeakFreqLabel, dualPeakGainLabel,
    dualPeakQualityLabel,
    // Lowpass
    lowPassFreqLabel, lowPassResonanceLabel, lowPassResonanceQualityLabel,
    lowPassSlopeLabel,
    // lateDrive
    lateBiasLabel, lateDriveTypeLabel, lateGirthLabel, lateDriveLabel,
    preGainLabel, mixLabel, analyserLabel,
    // Titels
    inLabel, outLabel, earlyLabel, highpassLabel, peakLabel, dualPeakLabel,
    lowpassLabel, lateLabel,
    // Options
    optionsLabel;

  // Options Labels
  CustomLabel configOscilloscopeBufferSizeLabel,
    configOscilloscopeSamplesPerBlockLabel, configBackgroundColorLabel,
    configForegroundColorLabel, configAccentColorLabel, configCornerRadiusLabel;
  CustomTextbox configOscilloscopeBufferSizeTextbox,
    configOscilloscopeSamplesPerBlockTextbox, configBackgroundColorTextbox,
    configForegroundColorTextbox, configAccentColorTextbox,
    configCornerRadiusTextbox;

  // Color
  bool testColorString(String string);
  Colour backgroundColor = backgroundColorFactory;
  Colour foregroundColor = foregroundColorFactory;
  Colour accentColor = accentColorFactory;
  Colour fontColor = Colour(255, 255, 255);
  Colour optionsFontColor = Colour(255, 255, 255);
  Colour parseColourFromString(String str);
  void loadBackgroundColor(PropertiesFile* commonSettings);
  void loadForegroundColor(PropertiesFile* commonSettings);
  void loadAccentColor(PropertiesFile* commonSettings);
  void saveBackgroundColor(PropertiesFile* commonSettings);
  void saveForegroundColor(PropertiesFile* commonSettings);
  void saveAccentColor(PropertiesFile* commonSettings);
  Colour backgroundColorFallback = backgroundColorFactory;
  Colour foregroundColorFallback = foregroundColorFactory;
  Colour accentColorFallback = accentColorFactory;

  // Oscilloscope Settings
  int oscilloscopeBufferSize = 1024;
  int oscilloscopeSamplesPerBlock = 4;
  int oscilloscopeBufferSizeFallback = 1024;
  int oscilloscopeSamplesPerBlockFallback = 4;
  void loadOscilloscopeBufferSize(PropertiesFile* commonSettings);
  void loadOscilloscopeSamplesPerBlock(PropertiesFile* commonSettings);
  void loadCornerRadius(PropertiesFile* commonSettings);
  void saveOscilloscopeBufferSize(PropertiesFile* commonSettings);
  void saveOscilloscopeSamplesPerBlock(PropertiesFile* commonSettings);
  void saveCornerRadius(PropertiesFile* commonSettings);
  void setOscilloscopeBufferSize(int oscilloscopeBufferSize);
  void setOscilloscopeSamplesPerBlock(int oscilloscopeSamplesPerBlock);
  void setCornerRadius(int cornerRadius);

  // Component Vectors
  std::vector<CustomLabel*> getLabels();
  std::vector<CustomLabel*> getOptionsLabels();
  std::vector<CustomRotarySlider*> getSliders();
  std::vector<Component*> getComps();
  std::vector<CustomTextButton*> getButtons();
  std::vector<CustomTextButton*> getOptionsButtons();
  std::vector<CustomTextbox*> getTextboxes();

  OpenGLContext openGLContext;
  VersionManager& versionManager;
  // End
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
