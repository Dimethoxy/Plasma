#include "PluginProcessor.h"
#include "PluginEditor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PlasmaAudioProcessorEditor::PlasmaAudioProcessorEditor(PlasmaAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p),
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Sliders
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Pregain
	preGainSlider(*audioProcessor.apvts.getParameter("Pre Gain"), "dB", "Gain"),
	driveSlider(*audioProcessor.apvts.getParameter("Drive"), "", "Drive"),
	girthSlider(*audioProcessor.apvts.getParameter("Girth"), "", "Girth"),
	biasSlider(*audioProcessor.apvts.getParameter("Bias"), "", "Symmetry"),
	driveTypeSlider(*audioProcessor.apvts.getParameter("Distortion Type"), "", "Distortion"),
	//Highpass
	highPassFreqSlider(*audioProcessor.apvts.getParameter("Highpass Freq"), "Hz", "Highpass"),
	highPassResonanceSlider(*audioProcessor.apvts.getParameter("Highpass Resonance"), "dB", "Resonance"),
	highPassResonanceQualitySlider(*audioProcessor.apvts.getParameter("Highpass Resonance Q"), "", "Quality"),
	highPassSlopeSlider(*audioProcessor.apvts.getParameter("Highpass Slope"), "dB/oct", "Slope"),
	//Peak
	peakStereoSlider(*audioProcessor.apvts.getParameter("Peak Stereo"), "%", "Peak Stereo"),
	peakFreqSlider(*audioProcessor.apvts.getParameter("Peak Freq"), "Hz", "Peak"),
	peakGainSlider(*audioProcessor.apvts.getParameter("Peak Gain"), "dB", "Peak Resonance"),
	peakQualitySlider(*audioProcessor.apvts.getParameter("Peak Quality"), "", "Quality"),
	//Lowpass
	lowPassFreqSlider(*audioProcessor.apvts.getParameter("Lowpass Freq"), "Hz", "Lowpass"),
	lowPassResonanceSlider(*audioProcessor.apvts.getParameter("Lowpass Resonance"), "dB", "Resonance"),
	lowPassResonanceQualitySlider(*audioProcessor.apvts.getParameter("Lowpass Resonance Q"), "", "Quality"),
	lowPassSlopeSlider(*audioProcessor.apvts.getParameter("Lowpass Slope"), "dB/oct", "Slope"),
	//Lategain
	gainSlider(*audioProcessor.apvts.getParameter("Gain"), "dB", "Gain"),
	lateDriveSlider(*audioProcessor.apvts.getParameter("Late Drive"), "", "Drive"),
	lateGirthSlider(*audioProcessor.apvts.getParameter("Girth"), "", "Girth"),
	lateBiasSlider(*audioProcessor.apvts.getParameter("Late Bias"), "", "Symmetry"),
	lateDriveTypeSlider(*audioProcessor.apvts.getParameter("Late Distortion Type"), "", "Distortion"),
	mixSlider(*audioProcessor.apvts.getParameter("Mix"), "%", "Mix"),
	analyserSlider(*audioProcessor.apvts.getParameter("Analyser Type"), "", "Analyser Type"),
	//ResponseCurve
	responseCurveComponent(audioProcessor),
	//Shapercurve
	earlyShapercurveComponent(audioProcessor, 0),
	lateShapercurveComponent(audioProcessor, 1),
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Attachments
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//In
	preGainSliderAttachment(audioProcessor.apvts, "Pre Gain", preGainSlider),
	analyserSliderAttachment(audioProcessor.apvts, "Analyser Type", analyserSlider),
	//Early
	driveTypeSliderAttachment(audioProcessor.apvts, "Distortion Type", driveTypeSlider),
	girthSliderAttachment(audioProcessor.apvts, "Girth", girthSlider),
	driveSliderAttachment(audioProcessor.apvts, "Drive", driveSlider),
	biasSliderAttachment(audioProcessor.apvts, "Bias", biasSlider),
	highPassResonanceSliderAttachment(audioProcessor.apvts, "Highpass Resonance", highPassResonanceSlider),
	highPassResonanceQualitySliderAttachment(audioProcessor.apvts, "Highpass Resonance Q", highPassResonanceQualitySlider),
	highPassFreqSliderAttachment(audioProcessor.apvts, "Highpass Freq", highPassFreqSlider),
	highPassSlopeSliderAttachment(audioProcessor.apvts, "Highpass Slope", highPassSlopeSlider),
	//Peak
	peakStereoSliderAttachment(audioProcessor.apvts, "Peak Stereo", peakStereoSlider),
	peakFreqSliderAttachment(audioProcessor.apvts, "Peak Freq", peakFreqSlider),
	peakGainSliderAttachment(audioProcessor.apvts, "Peak Gain", peakGainSlider),
	peakQualitySliderAttachment(audioProcessor.apvts, "Peak Q", peakQualitySlider),
	//Lowpass
	lowPassFreqSliderAttachment(audioProcessor.apvts, "Lowpass Freq", lowPassFreqSlider),
	lowPassSlopeSliderAttachment(audioProcessor.apvts, "Lowpass Slope", lowPassSlopeSlider),
	lowPassResonanceQualitySliderAttachment(audioProcessor.apvts, "Lowpass Resonance Q", lowPassResonanceQualitySlider),
	lowPassResonanceSliderAttachment(audioProcessor.apvts, "Lowpass Resonance", lowPassResonanceSlider),
	//Late
	lateBiasSliderAttachment(audioProcessor.apvts, "Late Bias", lateBiasSlider),
	lateDriveTypeSliderAttachment(audioProcessor.apvts, "Late Distortion Type", lateDriveTypeSlider),
	lateGirthSliderAttachment(audioProcessor.apvts, "Late Girth", lateGirthSlider),
	lateDriveSliderAttachment(audioProcessor.apvts, "Late Drive", lateDriveSlider),
	//Out
	gainSliderAttachment(audioProcessor.apvts, "Gain", gainSlider),
	mixSliderAttachment(audioProcessor.apvts, "Mix", mixSlider),
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Labels
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tooltipLabel("", FontSizes::Tooltipp, Justification::centredLeft),
	//Drive
	gainLabel("Gain", FontSizes::Main, Justification::centredTop),
	driveLabel("Drive", FontSizes::Main, Justification::centredTop),
	girthLabel("Girth", FontSizes::Main, Justification::centredTop),
	biasLabel("Symmetry", FontSizes::Main, Justification::centredTop),
	driveTypeLabel("Type", FontSizes::Main, Justification::centredTop),
	//Highpass
	highPassFreqLabel("Frequency", FontSizes::Main, Justification::centredTop),
	highPassResonanceLabel("Resonance", FontSizes::Main, Justification::centredTop),
	highPassResonanceQualityLabel("Q", FontSizes::Main, Justification::centredTop),
	highPassSlopeLabel("Slope", FontSizes::Main, Justification::centredTop),
	//Peak
	peakStereoLabel("Stereo", FontSizes::Main, Justification::centredTop),
	peakFreqLabel("Frequency", FontSizes::Main, Justification::centredTop),
	peakGainLabel("Gain", FontSizes::Main, Justification::centredTop),
	peakQualityLabel("Q", FontSizes::Main, Justification::centredTop),
	//Lowpass
	lowPassFreqLabel("Frequency", FontSizes::Main, Justification::centredTop),
	lowPassResonanceLabel("Resonance", FontSizes::Main, Justification::centredTop),
	lowPassResonanceQualityLabel("Q", FontSizes::Main, Justification::centredTop),
	lowPassSlopeLabel("Slope", FontSizes::Main, Justification::centredTop),
	//lateDrive
	lateBiasLabel("Symmetry", FontSizes::Main, Justification::centredTop),
	lateDriveTypeLabel("Type", FontSizes::Main, Justification::centredTop),
	lateGirthLabel("Girth", FontSizes::Main, Justification::centredTop),
	lateDriveLabel("Drive", FontSizes::Main, Justification::centredTop),
	preGainLabel("Gain", FontSizes::Main, Justification::centredTop),
	mixLabel("Mix", FontSizes::Main, Justification::centredTop),
	analyserLabel("Analyser", FontSizes::Main, Justification::centredTop),
	//Titels
	inLabel("Input", FontSizes::Titel, Justification::centredTop),
	outLabel("Output", FontSizes::Titel, Justification::centredTop),
	earlyLabel("Distortion", FontSizes::Titel, Justification::centredTop),
	highpassLabel("Highpass", FontSizes::Titel, Justification::centredTop),
	peakLabel("Peak", FontSizes::Titel, Justification::centredTop),
	lowpassLabel("Lowpass", FontSizes::Titel, Justification::centredTop),
	lateLabel("Distortion", FontSizes::Titel, Justification::centredTop),
	plasmaLabel(),
	configButton(),
	scaleUpButton(),
	scaleDownButton(),
	//Options
	optionsLabel("Options", FontSizes::Titel, Justification::centredLeft),
	configOscilloscopeBufferSizeLabel("Oscilloscope Buffer Size", FontSizes::Main, Justification::centredLeft),
	configOscilloscopeSamplesPerBlockLabel("Oscilloscope Block Size", FontSizes::Main, Justification::centredLeft),
	configBackgroundColorLabel("Background Color", FontSizes::Main, Justification::centredLeft),
	configForegroundColorLabel("Foreground Color", FontSizes::Main, Justification::centredLeft),
	configAccentColorLabel("Accent Color", FontSizes::Main, Justification::centredLeft),
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Textboxes
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	configOscilloscopeBufferSizeTextbox("16", FontSizes::Main, Justification::centredLeft),
	configOscilloscopeSamplesPerBlockTextbox("128", FontSizes::Main, Justification::centredLeft),
	configBackgroundColorTextbox("#182020", FontSizes::Main, Justification::centredLeft),
	configForegroundColorTextbox("#242627", FontSizes::Main, Justification::centredLeft),
	configAccentColorTextbox("#FF0000", FontSizes::Main, Justification::centredLeft)
{

	//Waveform
	waveformComponent = &p.waveformComponent;
	addAndMakeVisible(waveformComponent);

	//Load Config File
	options.applicationName = "Plasma";
	options.filenameSuffix = ".config";
	applicationProperties.setStorageParameters(options);
	auto userSettings = applicationProperties.getUserSettings();
	auto commonSettings = applicationProperties.getCommonSettings(false);

	//Load Config Data
	scale = userSettings->getIntValue("scale", 100);
	loadBackgroundColor(commonSettings);
	loadForegroundColor(commonSettings);
	loadAccentColor(commonSettings);

	//Update Config Textboxes
	configBackgroundColorTextbox.setText("#" + getBackgroundColor().toDisplayString(false), NotificationType::dontSendNotification);
	configForegroundColorTextbox.setText("#" + getForegroundColor().toDisplayString(false), NotificationType::dontSendNotification);
	configAccentColorTextbox.setText("#" + getAccentColor().toDisplayString(false), NotificationType::dontSendNotification);

	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
	}
	for (auto* comp : getSliders())
	{
		addAndMakeVisible(comp);
		comp->addListener(this);
	}
	for (auto* label : getLabels())
	{
		addAndMakeVisible(label);
	}
	for (auto* label : getOptionsLabels())
	{
		addAndMakeVisible(label);
	}
	for (auto* textbox : getTextboxes())
	{
		addAndMakeVisible(textbox);
		textbox->addListener(this);
	}
	//Logo
	addAndMakeVisible(plasmaLabel);

	//Options Button
	configButton.setButtonText("O");
	configButton.addListener(this);
	addAndMakeVisible(configButton);

	//Scale Up Button
	scaleUpButton.setButtonText("+");
	scaleUpButton.addListener(this);
	addAndMakeVisible(scaleUpButton);

	//Scale Down Button
	scaleDownButton.setButtonText("-");
	scaleDownButton.addListener(this);
	addAndMakeVisible(scaleDownButton);

	//Save Options
	safeConfigButton.setButtonText("S");
	safeConfigButton.addListener(this);
	addAndMakeVisible(safeConfigButton);
	safeConfigButton.setVisible(false);

	//Hide Options Menu
	optionsLabel.setVisible(false);
	configOscilloscopeBufferSizeLabel.setVisible(true);

	//Reloader Analyser Knob
	sliderValueChanged(&analyserSlider);
	sliderDragEnded(&analyserSlider);

	//Window
	setResizable(false, false);
	setSize(sc(810), sc(940)); //810 ... 1060
}
PlasmaAudioProcessorEditor::~PlasmaAudioProcessorEditor()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Draw
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaAudioProcessorEditor::paint(juce::Graphics& g)
{
	using namespace juce;

	//Back
	g.fillAll(getBackgroundColor());

	//Front
	g.setColour(getForegroundColor());
	g.fillRect(headerArea());
	g.fillRect(monitorArea());
	g.fillRect(inArea());
	g.fillRect(outArea());
	g.fillRect(earlyArea());
	g.fillRect(highpassArea());
	g.fillRect(peakArea());
	g.fillRect(lowpassArea());
	g.fillRect(lateArea());

	//Monitor Background
	g.setColour(getBackgroundColor());
	g.fillRect(monitorArea().reduced(sc(padding)));

	float lineSize = sc(2.0f);
	float lineOffset = 0.0f;
	Line<float> inLine(
		Point<float>(inArea().getCentreX() - sc(33), inArea().getY() + fs_titelLabel()),
		Point<float>(inArea().getCentreX() + sc(33), inArea().getY() + fs_titelLabel()));

	Line<float> outLine(
		Point<float>(outArea().getCentreX() - sc(43), outArea().getY() + fs_titelLabel()),
		Point<float>(outArea().getCentreX() + sc(43), outArea().getY() + fs_titelLabel()));

	Line<float> earlyLine(
		Point<float>(earlyArea().getCentreX() - sc(59), earlyArea().getY() + fs_titelLabel()),
		Point<float>(earlyArea().getCentreX() + sc(59), earlyArea().getY() + fs_titelLabel()));

	Line<float> highpassLine(
		Point<float>(highpassArea().getCentreX() - sc(56), highpassArea().getY() + fs_titelLabel()),
		Point<float>(highpassArea().getCentreX() + sc(56), highpassArea().getY() + fs_titelLabel()));

	Line<float> peakLine(
		Point<float>(peakArea().getCentreX() - sc(29), peakArea().getY() + fs_titelLabel()),
		Point<float>(peakArea().getCentreX() + sc(29), peakArea().getY() + fs_titelLabel()));

	Line<float> lowpassLine(
		Point<float>(lowpassArea().getCentreX() - sc(54), lowpassArea().getY() + fs_titelLabel()),
		Point<float>(lowpassArea().getCentreX() + sc(54), lowpassArea().getY() + fs_titelLabel()));

	Line<float> lateLine(
		Point<float>(lateArea().getCentreX() - sc(59), lateArea().getY() + fs_titelLabel()),
		Point<float>(lateArea().getCentreX() + sc(59), lateArea().getY() + fs_titelLabel()));

	Line<float> optionsLine(
		Point<float>(optionsLabel.getBounds().getCentreX() - sc(46), optionsLabel.getBounds().getY() + sc(37)),
		Point<float>(optionsLabel.getBounds().getCentreX() + sc(46), optionsLabel.getBounds().getY() + sc(37)));

	g.setColour(getFontColor());
	g.drawLine(inLine, lineSize);
	g.drawLine(outLine, lineSize);
	g.drawLine(earlyLine, lineSize);
	g.drawLine(highpassLine, lineSize);
	g.drawLine(peakLine, lineSize);
	g.drawLine(lowpassLine, lineSize);
	g.drawLine(lateLine, lineSize);
	if (showConfig)
	{
		g.setColour(getOptionsFontColor());
		g.drawLine(optionsLine, lineSize);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Timer Callback
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaAudioProcessorEditor::timerCallback()
{
	loudnessMeterIn.repaint();
	loudnessMeterOut.repaint();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Interaction
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaAudioProcessorEditor::configWindow(bool visibility)
{
	//Make visible
	if (visibility)
	{
		//Show Option Components
		safeConfigButton.setVisible(true);
		optionsLabel.setVisible(true);

		//Show Config Labels
		configOscilloscopeBufferSizeLabel.setVisible(true);
		configOscilloscopeSamplesPerBlockLabel.setVisible(true);
		configBackgroundColorLabel.setVisible(true);
		configForegroundColorLabel.setVisible(true);
		configAccentColorLabel.setVisible(true);

		//Show Config Inputs
		configOscilloscopeBufferSizeTextbox.setVisible(true);
		configOscilloscopeSamplesPerBlockTextbox.setVisible(true);
		configBackgroundColorTextbox.setVisible(true);
		configForegroundColorTextbox.setVisible(true);
		configAccentColorTextbox.setVisible(true);

		//Hide Tooltip
		tooltipLabel.setVisible(false);

		//Set Config to visible
		showConfig = true;
	}
	//Hide
	else
	{
		//Hide Options Components
		safeConfigButton.setVisible(false);
		optionsLabel.setVisible(false);

		//Hide Config Labels
		configOscilloscopeBufferSizeLabel.setVisible(false);
		configOscilloscopeSamplesPerBlockLabel.setVisible(false);
		configBackgroundColorLabel.setVisible(false);
		configForegroundColorLabel.setVisible(false);
		configAccentColorLabel.setVisible(false);

		//Hide Config Inputs
		configOscilloscopeBufferSizeTextbox.setVisible(false);
		configOscilloscopeSamplesPerBlockTextbox.setVisible(false);
		configBackgroundColorTextbox.setVisible(false);
		configForegroundColorTextbox.setVisible(false);
		configAccentColorTextbox.setVisible(false);

		//Show Tooltip
		tooltipLabel.setVisible(true);

		//Set Config to hidden
		showConfig = false;
	}
}
void PlasmaAudioProcessorEditor::buttonClicked(Button* button)
{
	if (button == &scaleUpButton)
	{
		if (scale <= 400)
		{
			scale += 20;
			auto userSettings = applicationProperties.getUserSettings();
			auto commonSettings = applicationProperties.getCommonSettings(false);
			userSettings->setValue("scale", scale);
			userSettings->save();
			resized();
		}
	}
	else if (button == &scaleDownButton)
	{
		if (scale > 40)
		{
			scale -= 20;
			auto userSettings = applicationProperties.getUserSettings();
			auto commonSettings = applicationProperties.getCommonSettings(false);
			userSettings->setValue("scale", scale);
			userSettings->save();
			resized();
		}
	}
	else if (button == &configButton)
	{
		analyserSlider.setValue(AnalyserType::Options);
	}
	else if (button == &safeConfigButton)
	{
		//Load Config File
		options.applicationName = "Plasma";
		options.filenameSuffix = ".config";
		applicationProperties.setStorageParameters(options);
		auto userSettings = applicationProperties.getUserSettings();
		auto commonSettings = applicationProperties.getCommonSettings(false);

		//Save Colors
		saveBackgroundColor(commonSettings);
		saveForegroundColor(commonSettings);
		saveAccentColor(commonSettings);

		//Repaint
		repaint();
	}
}
void PlasmaAudioProcessorEditor::sliderDragStarted(Slider* slider)
{
	if (
		slider == &driveSlider ||
		slider == &girthSlider ||
		slider == &biasSlider ||
		slider == &driveTypeSlider ||
		slider == &lateDriveSlider ||
		slider == &lateGirthSlider ||
		slider == &lateBiasSlider ||
		slider == &lateDriveTypeSlider)
	{
		autoAnalyserType = AnalyserType::Shapercurve;
	}
	else if (
		slider == &highPassFreqSlider ||
		slider == &highPassResonanceSlider ||
		slider == &highPassResonanceQualitySlider ||
		slider == &highPassSlopeSlider ||
		slider == &peakStereoSlider ||
		slider == &peakFreqSlider ||
		slider == &peakGainSlider ||
		slider == &peakQualitySlider ||
		slider == &lowPassFreqSlider ||
		slider == &lowPassResonanceSlider ||
		slider == &lowPassResonanceQualitySlider ||
		slider == &lowPassSlopeSlider)
	{
		autoAnalyserType = AnalyserType::Response;
	}
	else
	{
		autoAnalyserType = AnalyserType::Waveform;
	}
	if (isAutoAnalyser)
	{
		setAnalyserType(autoAnalyserType);
	}
	tooltipLabel.setText(static_cast<CustomRotarySlider*>(slider)->getTooltipString(), juce::dontSendNotification);
}
void PlasmaAudioProcessorEditor::sliderDragEnded(Slider* slider)
{
	autoAnalyserType = AnalyserType::Waveform;
	if (isAutoAnalyser)
	{
		setAnalyserType(autoAnalyserType);
	}
	tooltipLabel.setText("", juce::dontSendNotification);
}
void PlasmaAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	if (slider == &analyserSlider)
	{
		AnalyserType analyser = static_cast<AnalyserType>(analyserSlider.getValue());
		if (analyser == AnalyserType::Automatic)
		{
			isAutoAnalyser = true;
		}
		else
		{
			isAutoAnalyser = false;
			setAnalyserType(analyser);
		}
	}
	tooltipLabel.setText(static_cast<CustomRotarySlider*>(slider)->getTooltipString(), juce::dontSendNotification);
}
void PlasmaAudioProcessorEditor::setAnalyserType(AnalyserType analyser)
{
	//Waveform
	if (analyser == AnalyserType::Waveform)
	{
		waveformComponent->setVisible(true);
	}
	else
	{
		waveformComponent->setVisible(false);
	}

	//Repsonse
	if (analyser == AnalyserType::Response)
	{
		responseCurveComponent.setVisible(true);
	}
	else
	{
		responseCurveComponent.setVisible(false);
	}

	//Distortion
	if (analyser == AnalyserType::Shapercurve)
	{
		earlyShapercurveComponent.setVisible(true);
		lateShapercurveComponent.setVisible(true);
	}
	else
	{
		earlyShapercurveComponent.setVisible(false);
		lateShapercurveComponent.setVisible(false);
	}

	//Options
	if (analyser == AnalyserType::Options)
	{
		configWindow(true);
	}
	else
	{
		configWindow(false);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Layout
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float PlasmaAudioProcessorEditor::sc(float val)
{
	float factor = float(scale) / 100.0f;
	return val * factor;
}
Rectangle<int> PlasmaAudioProcessorEditor::headerArea()
{
	Rectangle<int> area(0, 0, getWidth(), sc(50));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::inArea()
{
	Rectangle<int> area(sc(padding), headerArea().getBottom() + sc(padding), sc(boxWidth), sc(310));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::earlyArea()
{
	Rectangle<int> area(sc(padding), sc(380), sc(boxWidth), sc(boxHeight));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::highpassArea()
{
	Rectangle<int> area(earlyArea().getRight() + sc(padding), sc(380), sc(boxWidth), sc(boxHeight));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::peakArea()
{
	Rectangle<int> area(highpassArea().getRight() + sc(padding), sc(380), sc(boxWidth), sc(boxHeight));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::lowpassArea()
{
	Rectangle<int> area(peakArea().getRight() + sc(padding), sc(380), sc(boxWidth), sc(boxHeight));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::lateArea()
{
	Rectangle<int> area(lowpassArea().getRight() + sc(padding), sc(380), sc(boxWidth), sc(boxHeight));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::outArea()
{
	Rectangle<int> area(lateArea().getX(), headerArea().getBottom() + sc(padding), sc(boxWidth), sc(310));
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::monitorArea()
{
	Rectangle<int> area(highpassArea().getX(), sc(60), lowpassArea().getRight() - highpassArea().getX(), sc(310));
	return area;
}
float PlasmaAudioProcessorEditor::fs_mainLabel()
{
	return sc(28.0f);
}
float PlasmaAudioProcessorEditor::fs_titelLabel()
{
	return sc(42.0f);
}
void PlasmaAudioProcessorEditor::resized()
{

	int knobSize = 120;
	///////////////////////////////////////////////////////////////////////////////////////////
	//Monitor
	responseCurveComponent.setBounds(
		monitorArea().getX(),
		monitorArea().getY() + sc(10),
		monitorArea().getWidth() - sc(10),
		monitorArea().getHeight() - 2 * sc(padding));
	responseCurveComponent.update();
	responseCurveComponent.setPadding(sc(padding));
	//loudnessMeterIn.setBounds(220, 60, 620, 155);
	//loudnessMeterOut.setBounds(220, 215, 620, 155);
	auto logoX = headerArea().getCentreX() - sc(100);
	plasmaLabel.setBounds(logoX, sc(-42), sc(200), sc(100));
	plasmaLabel.setCustomFontSize(sc(100));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//In
	inLabel.setBounds(
		inArea().getX(),
		inArea().getY() + sc(padding),
		inArea().getWidth(),
		sc(40));
	//Gain
	preGainSlider.setBounds(
		inArea().getCentreX() - sc(knobSize) / 2,
		sc(110),
		sc(knobSize),
		sc(knobSize));
	preGainLabel.setBounds(
		preGainSlider.getBounds().getX(),
		preGainSlider.getBounds().getY() + preGainSlider.getBounds().getHeight() * knobLabelHeight,
		preGainSlider.getBounds().getWidth(),
		sc(40));
	//Analyser
	analyserSlider.setBounds(
		inArea().getCentreX() - sc(knobSize) / 2,
		sc(230),
		sc(knobSize),
		sc(knobSize));
	analyserLabel.setBounds(
		analyserSlider.getBounds().getX(),
		analyserSlider.getBounds().getY() + analyserSlider.getBounds().getHeight() * knobLabelHeight,
		analyserSlider.getBounds().getWidth(),
		sc(40));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Early
	earlyLabel.setBounds(
		earlyArea().getX(),
		earlyArea().getY() + sc(padding),
		earlyArea().getWidth(),
		sc(40));
	//Type
	driveTypeSlider.setBounds(
		earlyArea().getCentreX() - sc(knobSize) / 2,
		sc(430),
		sc(knobSize),
		sc(knobSize));
	driveTypeLabel.setBounds(
		driveTypeSlider.getBounds().getX(),
		driveTypeSlider.getBounds().getY() + driveTypeSlider.getBounds().getHeight() * knobLabelHeight,
		driveTypeSlider.getBounds().getWidth(),
		sc(40));
	//Symmetry
	biasSlider.setBounds(
		earlyArea().getCentreX() - sc(knobSize) / 2,
		sc(550),
		sc(knobSize),
		sc(knobSize));
	biasLabel.setBounds(
		biasSlider.getBounds().getX(),
		biasSlider.getBounds().getY() + biasSlider.getBounds().getHeight() * knobLabelHeight,
		biasSlider.getBounds().getWidth(),
		sc(40));
	//Girth
	girthSlider.setBounds(
		earlyArea().getCentreX() - sc(knobSize) / 2,
		sc(670),
		sc(knobSize),
		sc(knobSize));
	girthLabel.setBounds(
		girthSlider.getBounds().getX(),
		girthSlider.getBounds().getY() + girthSlider.getBounds().getHeight() * knobLabelHeight,
		girthSlider.getBounds().getWidth(),
		sc(40));
	//Drive
	driveSlider.setBounds(
		earlyArea().getCentreX() - sc(knobSize) / 2,
		sc(790),
		sc(knobSize),
		sc(knobSize));
	driveLabel.setBounds(
		driveSlider.getBounds().getX(),
		driveSlider.getBounds().getY() + driveSlider.getBounds().getHeight() * knobLabelHeight,
		driveSlider.getBounds().getWidth(),
		sc(40));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Highpass
	highpassLabel.setBounds(
		highpassArea().getX(),
		highpassArea().getY() + sc(padding),
		highpassArea().getWidth(),
		sc(40));
	//Slope
	highPassSlopeSlider.setBounds(
		highpassArea().getCentreX() - sc(knobSize) / 2,
		sc(430),
		sc(knobSize),
		sc(knobSize));
	highPassSlopeLabel.setBounds(
		highPassSlopeSlider.getBounds().getX(),
		highPassSlopeSlider.getBounds().getY() + highPassSlopeSlider.getBounds().getHeight() * knobLabelHeight,
		highPassSlopeSlider.getBounds().getWidth(),
		sc(40));
	//Resonance Quality
	highPassResonanceQualitySlider.setBounds(
		highpassArea().getCentreX() - sc(knobSize) / 2,
		sc(550),
		sc(knobSize),
		sc(knobSize));
	highPassResonanceQualityLabel.setBounds(
		highPassResonanceQualitySlider.getBounds().getX(),
		highPassResonanceQualitySlider.getBounds().getY() + highPassResonanceQualitySlider.getBounds().getHeight() * knobLabelHeight,
		highPassResonanceQualitySlider.getBounds().getWidth(),
		sc(40));
	//Resonance
	highPassResonanceSlider.setBounds(
		highpassArea().getCentreX() - sc(knobSize) / 2,
		sc(670),
		sc(knobSize),
		sc(knobSize));
	highPassResonanceLabel.setBounds(
		highPassResonanceSlider.getBounds().getX(),
		highPassResonanceSlider.getBounds().getY() + highPassResonanceSlider.getBounds().getHeight() * knobLabelHeight,
		highPassResonanceSlider.getBounds().getWidth(),
		sc(40));
	//Frequency
	highPassFreqSlider.setBounds(
		highpassArea().getCentreX() - sc(knobSize) / 2,
		sc(790),
		sc(knobSize),
		sc(knobSize));
	highPassFreqLabel.setBounds(
		highPassFreqSlider.getBounds().getX(),
		highPassFreqSlider.getBounds().getY() + highPassFreqSlider.getBounds().getHeight() * knobLabelHeight,
		highPassFreqSlider.getBounds().getWidth(),
		sc(40));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Peak
	peakLabel.setBounds(
		peakArea().getX(),
		peakArea().getY() + sc(padding),
		peakArea().getWidth(),
		sc(40));
	//Stereo
	peakStereoSlider.setBounds(
		peakArea().getCentreX() - sc(knobSize) / 2,
		sc(430),
		sc(knobSize),
		sc(knobSize));
	peakStereoLabel.setBounds(
		peakStereoSlider.getBounds().getX(),
		peakStereoSlider.getBounds().getY() + peakStereoSlider.getBounds().getHeight() * knobLabelHeight,
		peakStereoSlider.getBounds().getWidth(),
		sc(40));
	//Peak Quality
	peakQualitySlider.setBounds(
		peakArea().getCentreX() - sc(knobSize) / 2,
		sc(550),
		sc(knobSize),
		sc(knobSize));
	peakQualityLabel.setBounds(
		peakQualitySlider.getBounds().getX(),
		peakQualitySlider.getBounds().getY() + peakQualitySlider.getBounds().getHeight() * knobLabelHeight,
		peakQualitySlider.getBounds().getWidth(),
		sc(40));
	//Peak Gain
	peakGainSlider.setBounds(
		peakArea().getCentreX() - sc(knobSize) / 2,
		sc(670),
		sc(knobSize),
		sc(knobSize));
	peakGainLabel.setBounds(
		peakGainSlider.getBounds().getX(),
		peakGainSlider.getBounds().getY() + peakGainSlider.getBounds().getHeight() * knobLabelHeight,
		peakGainSlider.getBounds().getWidth(),
		sc(40));
	//Frequency
	peakFreqSlider.setBounds(
		peakArea().getCentreX() - sc(knobSize) / 2,
		sc(790),
		sc(knobSize),
		sc(knobSize));
	peakFreqLabel.setBounds(
		peakFreqSlider.getBounds().getX(),
		peakFreqSlider.getBounds().getY() + peakFreqSlider.getBounds().getHeight() * knobLabelHeight,
		peakFreqSlider.getBounds().getWidth(),
		sc(40));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Lowpass
	lowpassLabel.setBounds(
		lowpassArea().getX(),
		lowpassArea().getY() + sc(padding),
		lowpassArea().getWidth(),
		sc(40));
	//Slope
	lowPassSlopeSlider.setBounds(
		lowpassArea().getCentreX() - sc(knobSize) / 2,
		sc(430),
		sc(knobSize),
		sc(knobSize));
	lowPassSlopeLabel.setBounds(
		lowPassSlopeSlider.getBounds().getX(),
		lowPassSlopeSlider.getBounds().getY() + lowPassSlopeSlider.getBounds().getHeight() * knobLabelHeight,
		lowPassSlopeSlider.getBounds().getWidth(),
		sc(40));
	//Resonance Quality
	lowPassResonanceQualitySlider.setBounds(
		lowpassArea().getCentreX() - sc(knobSize) / 2,
		sc(550),
		sc(knobSize),
		sc(knobSize));
	lowPassResonanceQualityLabel.setBounds(
		lowPassResonanceQualitySlider.getBounds().getX(),
		lowPassResonanceQualitySlider.getBounds().getY() + lowPassResonanceQualitySlider.getBounds().getHeight() * knobLabelHeight,
		lowPassResonanceQualitySlider.getBounds().getWidth(),
		sc(40));
	//Resonance
	lowPassResonanceSlider.setBounds(
		lowpassArea().getCentreX() - sc(knobSize) / 2,
		sc(670),
		sc(knobSize),
		sc(knobSize));
	lowPassResonanceLabel.setBounds(
		lowPassResonanceSlider.getBounds().getX(),
		lowPassResonanceSlider.getBounds().getY() + lowPassResonanceSlider.getBounds().getHeight() * knobLabelHeight,
		lowPassResonanceSlider.getBounds().getWidth(),
		sc(40));
	//Frequency
	lowPassFreqSlider.setBounds(
		lowpassArea().getCentreX() - sc(knobSize) / 2,
		sc(790),
		sc(knobSize),
		sc(knobSize));
	lowPassFreqLabel.setBounds(
		lowPassFreqSlider.getBounds().getX(),
		lowPassFreqSlider.getBounds().getY() + lowPassFreqSlider.getBounds().getHeight() * knobLabelHeight,
		lowPassFreqSlider.getBounds().getWidth(),
		sc(40));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Latedrive
	lateLabel.setBounds(
		lateArea().getX(),
		lateArea().getY() + sc(padding),
		lateArea().getWidth(),
		sc(40));
	//Type
	lateDriveTypeSlider.setBounds(
		lateArea().getCentreX() - sc(knobSize) / 2,
		sc(430),
		sc(knobSize),
		sc(knobSize));
	lateDriveTypeLabel.setBounds(
		lateDriveTypeSlider.getBounds().getX(),
		lateDriveTypeSlider.getBounds().getY() + lateDriveTypeSlider.getBounds().getHeight() * knobLabelHeight,
		lateDriveTypeSlider.getBounds().getWidth(),
		sc(40));
	//Symmetry
	lateBiasSlider.setBounds(
		lateArea().getCentreX() - sc(knobSize) / 2,
		sc(550),
		sc(knobSize),
		sc(knobSize));
	lateBiasLabel.setBounds(
		lateBiasSlider.getBounds().getX(),
		lateBiasSlider.getBounds().getY() + lateBiasSlider.getBounds().getHeight() * knobLabelHeight,
		lateBiasSlider.getBounds().getWidth(),
		sc(40));
	//Girth
	lateGirthSlider.setBounds(
		lateArea().getCentreX() - sc(knobSize) / 2,
		sc(670),
		sc(knobSize),
		sc(knobSize));
	lateGirthLabel.setBounds(
		lateGirthSlider.getBounds().getX(),
		lateGirthSlider.getBounds().getY() + lateGirthSlider.getBounds().getHeight() * knobLabelHeight,
		lateGirthSlider.getBounds().getWidth(),
		sc(40));
	//Drive
	lateDriveSlider.setBounds(
		lateArea().getCentreX() - sc(knobSize) / 2,
		sc(790),
		sc(knobSize),
		sc(knobSize));
	lateDriveLabel.setBounds(
		lateDriveSlider.getBounds().getX(),
		lateDriveSlider.getBounds().getY() + lateDriveSlider.getBounds().getHeight() * knobLabelHeight,
		lateDriveSlider.getBounds().getWidth(),
		sc(40));

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Out
	outLabel.setBounds(
		outArea().getX(),
		outArea().getY() + sc(padding),
		outArea().getWidth(),
		sc(40));
	//Gain
	gainSlider.setBounds(
		outArea().getCentreX() - sc(knobSize) / 2,
		sc(110),
		sc(knobSize),
		sc(knobSize));
	gainLabel.setBounds(
		gainSlider.getBounds().getX(),
		gainSlider.getBounds().getY() + gainSlider.getBounds().getHeight() * knobLabelHeight,
		gainSlider.getBounds().getWidth(),
		sc(40));
	//Mix
	mixSlider.setBounds(
		outArea().getCentreX() - sc(knobSize) / 2,
		sc(230),
		sc(knobSize),
		sc(knobSize));
	mixLabel.setBounds(
		mixSlider.getBounds().getX(),
		mixSlider.getBounds().getY() + mixSlider.getBounds().getHeight() * knobLabelHeight,
		mixSlider.getBounds().getWidth(),
		sc(40));

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Scale Knobs
	int scaleKnobSize = headerArea().getHeight() - 2 * (sc(padding));
	configButton.setBounds(
		getWidth() - 2.34 * scaleKnobSize - sc(padding),
		sc(padding),
		2.34 * scaleKnobSize,
		scaleKnobSize);
	scaleDownButton.setBounds(
		configButton.getX() - sc(padding) - scaleKnobSize,
		sc(padding),
		scaleKnobSize,
		scaleKnobSize);
	scaleUpButton.setBounds(
		scaleDownButton.getX() - sc(padding) - scaleKnobSize,
		sc(padding),
		scaleKnobSize,
		scaleKnobSize);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Options
	int lineSize = sc(40);
	int labelOffset = sc(5);
	int textBoxSize = sc(30);
	//Title
	optionsLabel.setBounds
	(
		monitorArea().getX() + 2 * sc(padding),
		monitorArea().getY() + 2 * sc(padding),
		sc(100),
		sc(40)
	);
	//Save
	safeConfigButton.setBounds
	(
		monitorArea().getRight() - sc(30) * 2.5 - sc(padding),
		monitorArea().getY() + 3 * sc(padding),
		2 * sc(30),
		sc(30)
	);
	//Oscilloscope Buffer Size 
	configOscilloscopeBufferSizeLabel.setBounds
	(
		monitorArea().getX() + 2 * sc(padding),
		monitorArea().getY() + 2 * sc(padding) + 1 * lineSize + labelOffset,
		sc(200),
		lineSize
	);
	configOscilloscopeBufferSizeTextbox.setBounds
	(
		configOscilloscopeBufferSizeLabel.getBounds().getRight() + sc(padding),
		configOscilloscopeBufferSizeLabel.getBounds().getY() + sc(5),
		sc(50),
		textBoxSize
	);
	//Oscilloscope Samples Per Block Label
	configOscilloscopeSamplesPerBlockLabel.setBounds(
		monitorArea().getX() + 2 * sc(padding),
		monitorArea().getY() + 2 * sc(padding) + 2 * lineSize + labelOffset,
		sc(200),
		lineSize);
	configOscilloscopeSamplesPerBlockTextbox.setBounds
	(
		configOscilloscopeSamplesPerBlockLabel.getBounds().getRight() + sc(padding),
		configOscilloscopeSamplesPerBlockLabel.getBounds().getY() + sc(5),
		sc(50),
		textBoxSize
	);
	//Background Color
	configBackgroundColorLabel.setBounds(
		monitorArea().getX() + 2 * sc(padding),
		monitorArea().getY() + 2 * sc(padding) + 3 * lineSize + labelOffset,
		sc(150),
		lineSize);
	configBackgroundColorTextbox.setBounds
	(
		configBackgroundColorLabel.getBounds().getRight() + sc(padding),
		configBackgroundColorLabel.getBounds().getY() + sc(5),
		sc(70),
		textBoxSize
	);
	//Foreground Color
	configForegroundColorLabel.setBounds(
		monitorArea().getX() + 2 * sc(padding),
		monitorArea().getY() + 2 * sc(padding) + 4 * lineSize + labelOffset,
		sc(150),
		lineSize);
	configForegroundColorTextbox.setBounds
	(
		configForegroundColorLabel.getBounds().getRight() + sc(padding),
		configForegroundColorLabel.getBounds().getY() + sc(5),
		sc(70),
		textBoxSize
	);
	//Accent Color
	configAccentColorLabel.setBounds(
		monitorArea().getX() + 2 * sc(padding),
		monitorArea().getY() + 2 * sc(padding) + 5 * lineSize + labelOffset,
		sc(110),
		lineSize);
	configAccentColorTextbox.setBounds
	(
		configAccentColorLabel.getBounds().getRight() + sc(padding),
		configAccentColorLabel.getBounds().getY() + sc(5),
		sc(70),
		textBoxSize
	);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Analyser
	waveformComponent->setBounds(monitorArea().reduced(sc(padding)));
	tooltipLabel.setBounds(
		sc(padding) + monitorArea().getX(),
		sc(5) + monitorArea().getY(),
		sc(300),
		sc(40));
	earlyShapercurveComponent.setBounds(
		monitorArea().getCentreX() - sc(200) - sc(padding),
		monitorArea().getCentreY() - sc(200) / 2,
		sc(200),
		sc(200));
	lateShapercurveComponent.setBounds(
		monitorArea().getCentreX() + sc(padding),
		monitorArea().getCentreY() - sc(200) / 2,
		sc(200),
		sc(200));
	tooltipLabel.setAlwaysOnTop(true);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Update Labels & Textboxes
	for (auto* label : getLabels())
	{
		label->resize();
	}
	for (auto* label : getOptionsLabels())
	{
		label->resize();
	}
	for (auto* textbox : getTextboxes())
	{
		textbox->resize();
	}
	setSize(lateArea().getRight() + sc(padding), lateArea().getBottom() + sc(padding));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Textboxes
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaAudioProcessorEditor::editorHidden(Label* label, TextEditor& textEditor)
{
	auto text = label->getText();

	if (label == &configBackgroundColorTextbox)
	{
		if (!testColorString(text))
		{
			label->setText("#" + getBackgroundColor().toDisplayString(false), NotificationType::dontSendNotification);
		}
		else
		{
			setBackgroundColor(parseColourFromString(text));
			repaint();
		}
	}
	else if (label == &configForegroundColorTextbox)
	{
		if (!testColorString(text))
		{
			label->setText("#" + getForegroundColor().toDisplayString(false), NotificationType::dontSendNotification);
		}
		else
		{

			setForegroundColor(parseColourFromString(text));
			repaint();
		}
	}
	else if (label == &configAccentColorTextbox)
	{
		if (!testColorString(text))
		{
			label->setText("#" + getAccentColor().toDisplayString(false), NotificationType::dontSendNotification);
		}
		else
		{
			setAccentColor(parseColourFromString(text));
			repaint();
		}
	}
}

void PlasmaAudioProcessorEditor::labelTextChanged(Label* label)
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Colors
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaAudioProcessorEditor::loadBackgroundColor(PropertiesFile* commonSettings)
{
	auto r = commonSettings->getIntValue("backgroundColorRed", backgroundColorFallback.getRed());
	auto g = commonSettings->getIntValue("backgroundColorGreen", backgroundColorFallback.getGreen());
	auto b = commonSettings->getIntValue("backgroundColorBlue", backgroundColorFallback.getBlue());
	setBackgroundColor(Colour(r, g, b));
}

void PlasmaAudioProcessorEditor::loadForegroundColor(PropertiesFile* commonSettings)
{
	auto r = commonSettings->getIntValue("foregroundColorRed", foregroundColorFallback.getRed());
	auto g = commonSettings->getIntValue("foregroundColorGreen", foregroundColorFallback.getGreen());
	auto b = commonSettings->getIntValue("foregroundColorBlue", foregroundColorFallback.getBlue());
	setForegroundColor(Colour(r, g, b));
}

void PlasmaAudioProcessorEditor::loadAccentColor(PropertiesFile* commonSettings)
{
	auto r = commonSettings->getIntValue("accentColorRed", accentColorFallback.getRed());
	auto g = commonSettings->getIntValue("accentColorGreen", accentColorFallback.getGreen());
	auto b = commonSettings->getIntValue("accentColorBlue", accentColorFallback.getBlue());
	setAccentColor(Colour(r, g, b));
}

void PlasmaAudioProcessorEditor::saveBackgroundColor(PropertiesFile* commonSettings)
{
	auto c = getBackgroundColor();
	auto r = c.getRed();
	auto g = c.getGreen();
	auto b = c.getBlue();
	commonSettings->setValue("backgroundColorRed", r);
	commonSettings->setValue("backgroundColorGreen", g);
	commonSettings->setValue("backgroundColorBlue", b);
}

void PlasmaAudioProcessorEditor::saveForegroundColor(PropertiesFile* commonSettings)
{
	auto c = getForegroundColor();
	auto r = c.getRed();
	auto g = c.getGreen();
	auto b = c.getBlue();
	commonSettings->setValue("foregroundColorRed", r);
	commonSettings->setValue("foregroundColorGreen", g);
	commonSettings->setValue("foregroundColorBlue", b);
}

void PlasmaAudioProcessorEditor::saveAccentColor(PropertiesFile* commonSettings)
{
	auto c = getAccentColor();
	auto r = c.getRed();
	auto g = c.getGreen();
	auto b = c.getBlue();
	commonSettings->setValue("accentColorRed", r);
	commonSettings->setValue("accentColorGreen", g);
	commonSettings->setValue("accentColorBlue", b);
}

Colour PlasmaAudioProcessorEditor::parseColourFromString(String str)
{
	int r, g, b;
	r = str.substring(1, 3).getHexValue32();
	g = str.substring(3, 5).getHexValue32();
	b = str.substring(5, 7).getHexValue32();
	return Colour(r, g, b);
}

Colour PlasmaAudioProcessorEditor::getBackgroundColor()
{
	return backgroundColor;
}

Colour PlasmaAudioProcessorEditor::getForegroundColor()
{
	return foregroundColor;
}

Colour PlasmaAudioProcessorEditor::getAccentColor()
{
	return accentColor;
}

Colour PlasmaAudioProcessorEditor::getFontColor()
{
	return fontColor;
}

Colour PlasmaAudioProcessorEditor::getOptionsFontColor()
{
	return optionsFontColor;
}

void PlasmaAudioProcessorEditor::setBackgroundColor(Colour c)
{
	backgroundColor = c;
	auto brightness = c.getBrightness();
	if (brightness <= 0.5)
	{
		setOptionsFontColor(Colours::white);
	}
	else
	{
		setOptionsFontColor(Colours::black);
	}
	for (auto* slider : getSliders())
	{
		slider->setColour(Slider::ColourIds::backgroundColourId, c);
	}
}

void PlasmaAudioProcessorEditor::setForegroundColor(Colour c)
{
	foregroundColor = c;
	auto brightness = c.getBrightness();
	if (brightness <= 0.5)
	{
		setFontColor(Colours::white);
	}
	else
	{
		setFontColor(Colours::black);
	}
}

void PlasmaAudioProcessorEditor::setAccentColor(Colour c)
{
	accentColor = c;
	for (auto* slider : getSliders())
	{
		slider->setColour(Slider::ColourIds::rotarySliderFillColourId, c);
	}
}

void PlasmaAudioProcessorEditor::setFontColor(Colour c)
{
	fontColor = c;
	for (auto* slider : getSliders())
	{
		slider->setColour(Slider::ColourIds::thumbColourId, c);
	}
	for (auto* label : getLabels())
	{
		label->setColour(Label::ColourIds::textColourId, c);
	}
	for (auto* button : getButtons())
	{
		button->setColour(TextButton::ColourIds::textColourOnId, c);
		button->setColour(TextButton::ColourIds::textColourOffId, c);
	}
	plasmaLabel.setColour(Label::ColourIds::textColourId, c);
}

void PlasmaAudioProcessorEditor::setOptionsFontColor(Colour c)
{
	optionsFontColor = c;
	for (auto* label : getOptionsLabels())
	{
		label->setColour(Label::ColourIds::textColourId, c);
	}
	for (auto* textbox : getTextboxes())
	{
		textbox->setColour(Label::ColourIds::textColourId, c);
		textbox->setColour(Label::ColourIds::textWhenEditingColourId, c);
	}
	for (auto* button : getOptionsButtons())
	{
		button->setColour(TextButton::ColourIds::textColourOnId, c);
		button->setColour(TextButton::ColourIds::textColourOffId, c);
	}
	waveformComponent->setColor(c);
	responseCurveComponent.setColor(c);
	earlyShapercurveComponent.setColor(c);
	lateShapercurveComponent.setColor(c);
}

bool PlasmaAudioProcessorEditor::testColorString(String string)
{
	if (string[0] != '#')
		return false;

	if (!(string.length() == 7))
		return false;

	for (int i = 1; i < string.length(); i++)
		if (!((string[i] >= '0' && string[i] <= 9)
			|| (string[i] >= 'a' && string[i] <= 'f')
			|| (string[i] >= 'A' || string[i] <= 'F')))
			return false;

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Misc
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<juce::Component*> PlasmaAudioProcessorEditor::getComps()
{
	return
	{
		&responseCurveComponent,
		&earlyShapercurveComponent,
		&lateShapercurveComponent,
		&loudnessMeterIn,
		&loudnessMeterOut
	};
}

std::vector<CustomRotarySlider*> PlasmaAudioProcessorEditor::getSliders()
{
	return
	{
		&gainSlider,
		&driveSlider,
		&girthSlider,
		&biasSlider,
		&lateBiasSlider,
		&highPassSlopeSlider,
		&highPassFreqSlider,
		&highPassResonanceSlider,
		&highPassResonanceQualitySlider,
		&peakStereoSlider,
		&peakFreqSlider,
		&peakGainSlider,
		&peakQualitySlider,
		&lowPassSlopeSlider,
		&lowPassFreqSlider,
		&lowPassResonanceSlider,
		&lowPassResonanceQualitySlider,
		&lateGirthSlider,
		&lateDriveSlider,
		&preGainSlider,
		&driveTypeSlider,
		&lateDriveTypeSlider,
		&mixSlider,
		&analyserSlider,
	};
}

std::vector<CustomLabel*> PlasmaAudioProcessorEditor::getLabels()
{
	return
	{
		//Drive
		&gainLabel,
		&driveLabel,
		&girthLabel,
		&biasLabel,
		&driveTypeLabel,
		//Highpass
		&highPassFreqLabel,
		&highPassResonanceLabel,
		&highPassResonanceQualityLabel,
		&highPassSlopeLabel,
		//Peak
		&peakStereoLabel,
		&peakFreqLabel,
		&peakGainLabel,
		&peakQualityLabel,
		//Lowpass
		&lowPassFreqLabel,
		&lowPassResonanceLabel,
		&lowPassResonanceQualityLabel,
		&lowPassSlopeLabel,
		//lateDrive
		&lateBiasLabel,
		&lateDriveTypeLabel,
		&lateGirthLabel,
		&lateDriveLabel,
		&preGainLabel,
		&mixLabel,
		&analyserLabel,
		//Titels
		&inLabel,
		&outLabel,
		&earlyLabel,
		&highpassLabel,
		&peakLabel,
		&lowpassLabel,
		&lateLabel
	};
}

std::vector<CustomLabel*> PlasmaAudioProcessorEditor::getOptionsLabels()
{
	return
	{
		&tooltipLabel,
		&optionsLabel,
		&configOscilloscopeBufferSizeLabel,
		&configOscilloscopeSamplesPerBlockLabel,
		&configBackgroundColorLabel,
		&configForegroundColorLabel,
		&configAccentColorLabel
	};
}

std::vector<CustomTextbox*> PlasmaAudioProcessorEditor::getTextboxes()
{
	return
	{
		&configOscilloscopeBufferSizeTextbox,
		&configOscilloscopeSamplesPerBlockTextbox,
		&configBackgroundColorTextbox,
		&configForegroundColorTextbox,
		&configAccentColorTextbox
	};
}

std::vector<CustomTextButton*> PlasmaAudioProcessorEditor::getButtons()
{
	return
	{
		&scaleUpButton,
		&scaleDownButton,
		&configButton,
	};
}

std::vector<CustomTextButton*> PlasmaAudioProcessorEditor::getOptionsButtons()
{
	return
	{
		&safeConfigButton
	};
}