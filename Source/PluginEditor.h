/*
-Fix Tooltip
-Implement spectrum analyser
-Implement option menu
-Fix global color settings
-Fix WaveformComponent line size
-Factory Presets
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

enum FontSizes
{
	Main,
	Titel,
	Tooltipp
};

class PlasmaAudioProcessorEditor : public juce::AudioProcessorEditor,
	public Timer,
	public Button::Listener,
	public Slider::Listener
{
public:
	PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
	~PlasmaAudioProcessorEditor() override;

	void paint(juce::Graphics&) override;
	void resized() override;

	void timerCallback() override;
	void buttonClicked(Button* button) override;
	void sliderValueChanged(Slider* slider);
	void sliderDragStarted(Slider* slider);
	void sliderDragEnded(Slider* slider);
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
	std::vector<juce::Component*> getComps();

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
		backgroundColorLabel,
		foregroundColorLabel,
		accentColorLabel,
		scaleLabel,
		optionsLabel;


	//Label Vector
	std::vector<CustomLabel*> getLabels();
	std::vector<CustomRotarySlider*> getSliders();

	//End
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
