/*
-Implement spectrum analyser
-Implement option menu
-Fix global color settings
-Fix analyser lines getting fucked when scaling GUI
-Implementing Factory Presets
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "CustomRotarySlider.h"
#include "ResponseCurveComponent.h"
#include "LoudnessMeterComponent.h"
#include "CustomLabel.h"
#include "CustomTextButton.h"
#include "PlasmaLabel.h"
#include "ShapercurveComponent.h"

class CustomTextbox : public CustomLabel
{
public:
	CustomTextbox(String text, int size, Justification justification) : CustomLabel(text, size, justification)
	{
		setEditable(true);
	};
};

enum FontSizes
{
	Main,
	Titel,
	Tooltipp
};

class PlasmaAudioProcessorEditor : public AudioProcessorEditor,
	public Timer,
	public Button::Listener,
	public Slider::Listener,
	public Label::Listener
{
public:
	PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
	~PlasmaAudioProcessorEditor() override;

	void paint(juce::Graphics&) override;
	void resized() override;

	void timerCallback() override;
	void buttonClicked(Button* button) override;
	void sliderValueChanged(Slider* slider) override;
	void sliderDragStarted(Slider* slider) override;
	void sliderDragEnded(Slider* slider) override;
	void labelTextChanged(Label* label) override;
	void editorHidden(Label* label, TextEditor& textEditor) override;
private:
	//Scaling
	CustomTextButton scaleUpButton;
	CustomTextButton scaleDownButton;
	CustomTextButton configButton;
	CustomTextButton safeConfigButton;

	//Audio Processor
	PlasmaAudioProcessor& audioProcessor;

	//Config
	ApplicationProperties applicationProperties;
	PropertiesFile::Options options;
	int scale = 100;
	bool showConfig = false;
	void configWindow(bool visibility);
	WaveformComponent* waveformComponent;
	AnalyserType autoAnalyserType;
	bool isAutoAnalyser;
	void setAnalyserType(AnalyserType analyser);

	//Sliders
	CustomRotarySlider
		//Drive
		gainSlider,
		driveSlider,
		girthSlider,
		biasSlider,
		driveTypeSlider,
		//Highpass
		highPassFreqSlider,
		highPassResonanceSlider,
		highPassResonanceQualitySlider,
		highPassSlopeSlider,
		//Peak
		peakStereoSlider,
		peakFreqSlider,
		peakGainSlider,
		peakQualitySlider,
		//Lowpass
		lowPassFreqSlider,
		lowPassResonanceSlider,
		lowPassResonanceQualitySlider,
		lowPassSlopeSlider,
		//lateDrive
		lateBiasSlider,
		lateDriveTypeSlider,
		lateGirthSlider,
		lateDriveSlider,
		preGainSlider,
		//Output
		mixSlider,
		analyserSlider;


	//Response Curve Component
	ResponseCurveComponent responseCurveComponent;
	ShapercurveComponent earlyShapercurveComponent;
	ShapercurveComponent lateShapercurveComponent;

	//Loudness Meter Components
	Gui::LoudnessMeterComponent loudnessMeterIn, loudnessMeterOut;

	//Attachments
	using APVTS = juce::AudioProcessorValueTreeState;
	using Attachment = APVTS::SliderAttachment;
	Attachment highPassFreqSliderAttachment,
		lowPassFreqSliderAttachment,
		peakFreqSliderAttachment,
		biasSliderAttachment,
		lateBiasSliderAttachment,
		driveTypeSliderAttachment,
		lateDriveTypeSliderAttachment,
		highPassResonanceSliderAttachment,
		lowPassResonanceSliderAttachment,
		peakGainSliderAttachment,
		peakStereoSliderAttachment,
		highPassResonanceQualitySliderAttachment,
		lowPassResonanceQualitySliderAttachment,
		peakQualitySliderAttachment,
		highPassSlopeSliderAttachment,
		lowPassSlopeSliderAttachment,
		preGainSliderAttachment,
		driveSliderAttachment,
		girthSliderAttachment,
		lateGirthSliderAttachment,
		lateDriveSliderAttachment,
		gainSliderAttachment,
		analyserSliderAttachment,
		mixSliderAttachment;

	//Layout
	float sc(float val);
	Rectangle<int> headerArea();
	Rectangle<int> monitorArea();
	Rectangle<int> inArea();
	Rectangle<int> outArea();
	Rectangle<int> earlyArea();
	Rectangle<int> highpassArea();
	Rectangle<int> peakArea();
	Rectangle<int> lowpassArea();
	Rectangle<int> lateArea();
	int boxWidth = 150;
	int boxHeight = 550;

	//Colors
	Colour c_back();
	Colour c_front();

	//Fontsizes
	float fs_mainLabel();
	float fs_titelLabel();
	float padding = 10.0f;
	float knobLabelHeight = 0.80f;

	//Labels
	PlasmaLabel plasmaLabel;
	CustomLabel
		tooltipLabel,
		//Drive
		gainLabel,
		driveLabel,
		girthLabel,
		biasLabel,
		driveTypeLabel,
		//Highpass
		highPassFreqLabel,
		highPassResonanceLabel,
		highPassResonanceQualityLabel,
		highPassSlopeLabel,
		//Peak
		peakStereoLabel,
		peakFreqLabel,
		peakGainLabel,
		peakQualityLabel,
		//Lowpass
		lowPassFreqLabel,
		lowPassResonanceLabel,
		lowPassResonanceQualityLabel,
		lowPassSlopeLabel,
		//lateDrive
		lateBiasLabel,
		lateDriveTypeLabel,
		lateGirthLabel,
		lateDriveLabel,
		preGainLabel,
		mixLabel,
		analyserLabel,
		//Titels
		inLabel,
		outLabel,
		earlyLabel,
		highpassLabel,
		peakLabel,
		lowpassLabel,
		lateLabel,
		//Options
		optionsLabel;

	//Options Labels
	CustomLabel configOscilloscopeBufferSizeLabel,
		configOscilloscopeSamplesPerBlockLabel,
		configBackgroundColorLabel,
		configForegroundColorLabel,
		configAccentColorLabel;
	CustomTextbox configOscilloscopeBufferSizeTextbox,
		configOscilloscopeSamplesPerBlockTextbox,
		configBackgroundColorTextbox,
		configForegroundColorTextbox,
		configAccentColorTextbox;

	//Color
	bool testColorString(String string);

	//Component Vectors
	std::vector<CustomLabel*> getLabels();
	std::vector<CustomRotarySlider*> getSliders();
	std::vector<Component*> getComps();
	std::vector<CustomTextbox*> getTextboxes();

	//End
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
