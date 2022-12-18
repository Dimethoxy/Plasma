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

//=============================================================================================



//=============================================================================================

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

	//Colors
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

private:
	//Scaling
	CustomTextButton scaleUpButton,
		scaleDownButton,
		configButton,
		safeConfigButton,
		resetConfigButton,
		updateButton;

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
	AnalyserType lastAnalyserType = AnalyserType::Automatic;

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
	Colour backgroundColor = Colour(12, 13, 14);
	Colour foregroundColor = Colour(24, 26, 27);
	Colour accentColor = Colour(255, 0, 0);
	Colour fontColor = Colour(255, 255, 255);
	Colour optionsFontColor = Colour(255, 255, 255);
	Colour parseColourFromString(String str);
	void loadBackgroundColor(PropertiesFile* commonSettings);
	void loadForegroundColor(PropertiesFile* commonSettings);
	void loadAccentColor(PropertiesFile* commonSettings);
	void saveBackgroundColor(PropertiesFile* commonSettings);
	void saveForegroundColor(PropertiesFile* commonSettings);
	void saveAccentColor(PropertiesFile* commonSettings);
	Colour backgroundColorFallback = Colour(12, 13, 14);
	Colour foregroundColorFallback = Colour(24, 26, 27);
	Colour accentColorFallback = Colour(255, 0, 0);

	//Oscilloscope Settings
	int oscilloscopeBufferSize = 1024;
	int oscilloscopeSamplesPerBlock = 4;
	int oscilloscopeBufferSizeFallback = 1024;
	int oscilloscopeSamplesPerBlockFallback = 4;
	void loadOscilloscopeBufferSize(PropertiesFile* commonSettings);
	void loadOscilloscopeSamplesPerBlock(PropertiesFile* commonSettings);
	void saveOscilloscopeBufferSize(PropertiesFile* commonSettings);
	void saveOscilloscopeSamplesPerBlock(PropertiesFile* commonSettings);
	void setOscilloscopeBufferSize(int oscilloscopeBufferSize);
	void setOscilloscopeSamplesPerBlock(int oscilloscopeSamplesPerBlock);

	//Component Vectors
	std::vector<CustomLabel*> getLabels();
	std::vector<CustomLabel*> getOptionsLabels();
	std::vector<CustomRotarySlider*> getSliders();
	std::vector<Component*> getComps();
	std::vector<CustomTextButton*> getButtons();
	std::vector<CustomTextButton*> getOptionsButtons();
	std::vector<CustomTextbox*> getTextboxes();


	juce::URL createURL(const juce::String& apiEndpoint)
	{
		// Replace "YOUR_API_URL_HERE" with the actual URL of your web API
		return juce::URL("https://api.dimethoxy.com/" + apiEndpoint);
	}

	juce::String sendRequest(const juce::String& apiEndpoint)
	{
		juce::URL url = createURL(apiEndpoint);

		// Send a GET request to the specified URL
		juce::String responseString = url.readEntireTextStream();

		return responseString;
	}

	juce::String extractVersionNumber(const juce::String& payload)
	{
		juce::var responseJSON = juce::JSON::parse(payload);
		juce::String version = responseJSON["version"].toString();
		return version;
	}

	bool isUpToDate(const juce::String& currentVersion)
	{
		try
		{
			juce::String apiResponse = sendRequest("version?program=plasma");
			juce::String latestVersion = extractVersionNumber(apiResponse);
			return latestVersion == currentVersion;
		}
		catch (...)
		{
			// If the request fails or returns an error, assume the program is up to date
			return true;
		}
	}

	//End
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
