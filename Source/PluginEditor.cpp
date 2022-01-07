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
tooltipLabel("", FontSizes::Main, Justification::centredLeft, false),
//Drive
gainLabel("Gain", FontSizes::Main, Justification::centredTop, false),
driveLabel("Drive", FontSizes(Main), Justification::centredTop, false),
girthLabel("Girth", FontSizes(Main), Justification::centredTop, false),
biasLabel("Symmetry", FontSizes(Main), Justification::centredTop, false),
driveTypeLabel("Type", FontSizes(Main), Justification::centredTop, false),
//Highpass
highPassFreqLabel("Frequency", FontSizes(Main), Justification::centredTop, false),
highPassResonanceLabel("Resonance", FontSizes(Main), Justification::centredTop, false),
highPassResonanceQualityLabel("Q", FontSizes(Main), Justification::centredTop, false),
highPassSlopeLabel("Slope", FontSizes(Main), Justification::centredTop, false),
//Peak
peakStereoLabel("Stereo", FontSizes(Main), Justification::centredTop, false),
peakFreqLabel("Frequency", FontSizes(Main), Justification::centredTop, false),
peakGainLabel("Gain", FontSizes(Main), Justification::centredTop, false),
peakQualityLabel("Q", FontSizes(Main), Justification::centredTop, false),
//Lowpass
lowPassFreqLabel("Frequency", FontSizes(Main), Justification::centredTop, false),
lowPassResonanceLabel("Resonance", FontSizes(Main), Justification::centredTop, false),
lowPassResonanceQualityLabel("Q", FontSizes(Main), Justification::centredTop, false),
lowPassSlopeLabel("Slope", FontSizes(Main), Justification::centredTop, false),
//lateDrive
lateBiasLabel("Symmetry", FontSizes(Main), Justification::centredTop, false),
lateDriveTypeLabel("Type", FontSizes(Main), Justification::centredTop, false),
lateGirthLabel("Girth", FontSizes(Main), Justification::centredTop, false),
lateDriveLabel("Drive", FontSizes(Main), Justification::centredTop, false),
preGainLabel("Gain", FontSizes(Main), Justification::centredTop, false),
mixLabel("Mix", FontSizes(Main), Justification::centredTop, false),
analyserLabel("Analyser", FontSizes(Main), Justification::centredTop, false),
//Titels
inLabel("Input", FontSizes(Titel), Justification::centredTop, true),
outLabel("Output", FontSizes(Titel), Justification::centredTop, true),
earlyLabel("Distortion", FontSizes(Titel), Justification::centredTop, true),
highpassLabel("Highpass", FontSizes(Titel), Justification::centredTop, true),
peakLabel("Peak", FontSizes(Titel), Justification::centredTop, true),
lowpassLabel("Lowpass", FontSizes(Titel), Justification::centredTop, true),
lateLabel("Distortion", FontSizes(Titel), Justification::centredTop, true),
plasmaLabel()
{
	//Load Config File
	options.applicationName = "Plasma";
	options.filenameSuffix = ".config";
	applicationProperties.setStorageParameters(options);
	auto userSettings = applicationProperties.getUserSettings();
	auto commonSettings = applicationProperties.getCommonSettings(false);
	
	//Load Config Data
	scaling = userSettings->getIntValue("scale", 100);

	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
	}
	for (auto* label : getLabels())
	{
		addAndMakeVisible(label);
	}
	
	scaleUpButton.setButtonText("+");
	scaleUpButton.addListener(this);
	addAndMakeVisible(scaleUpButton);
	
	scaleDownButton.setButtonText("-");
	scaleDownButton.addListener(this);
	addAndMakeVisible(scaleDownButton);
	
	addAndMakeVisible(plasmaLabel);

	//Tooltip
	Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::PoppinsMedium_ttf, BinaryData::PoppinsMedium_ttfSize);
	Font popFont(tface);
	tooltipLabel.setFont(popFont.withHeight(sc(24.0)));
	tooltipLabel.setJustificationType(juce::Justification::centredLeft);
	tooltipLabel.setText("", juce::dontSendNotification);
	addAndMakeVisible(tooltipLabel);

	setResizable(false, false);
	setSize(sc(810), sc(940)); //810 ... 1060
}
PlasmaAudioProcessorEditor::~PlasmaAudioProcessorEditor()
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Draw
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Colour PlasmaAudioProcessorEditor::c_back()
{
	return Colour(18, 20, 20);
}
Colour PlasmaAudioProcessorEditor::c_front()
{
	return Colour(24, 26, 27);
}

void PlasmaAudioProcessorEditor::paint (juce::Graphics& g)
{
    using namespace juce;
	
	//Back
	g.fillAll(c_back());

	//Front
	g.setColour(c_front());
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
	g.setColour(c_back());
	g.fillRect(monitorArea().reduced(sc(padding)));

	//Add and make visible all components
	
	bool clear = true;
	for (auto* component : getComps())
	{
		if (component->isMouseButtonDown())
		{
			tooltipLabel.setText(component->getHelpText(), juce::dontSendNotification);
			clear = false;
		}
	}
	if (clear) {
		tooltipLabel.setText("", juce::dontSendNotification);
	}
	float lineSize = sc(2.0f);
	float lineOffset = 0.0f;
	Line<float> inLine(Point<float>(inArea().getCentreX() - sc(32), inArea().getY() + fs_titelLabel()),
		Point<float>(inArea().getCentreX() + sc(32), inArea().getY() + fs_titelLabel()));
	
	Line<float> outLine(Point<float>(outArea().getCentreX() - sc(42), outArea().getY() + fs_titelLabel()),
		Point<float>(outArea().getCentreX() + sc(42), outArea().getY() + fs_titelLabel()));
	
	Line<float> earlyLine(Point<float>(earlyArea().getCentreX() - sc(58), earlyArea().getY() + fs_titelLabel()),
		Point<float>(earlyArea().getCentreX() + sc(58), earlyArea().getY() + fs_titelLabel()));
	
	Line<float> highpassArea(Point<float>(highpassArea().getCentreX() - sc(56), highpassArea().getY() + fs_titelLabel()),
		Point<float>(highpassArea().getCentreX() + sc(56), highpassArea().getY() + fs_titelLabel()));
	
	Line<float> peakArea(Point<float>(peakArea().getCentreX() - sc(30), peakArea().getY() + fs_titelLabel()),
		Point<float>(peakArea().getCentreX() + sc(30), peakArea().getY() + fs_titelLabel()));
	
	Line<float> lowpassArea(Point<float>(lowpassArea().getCentreX() - sc(54), lowpassArea().getY() + fs_titelLabel()),
		Point<float>(lowpassArea().getCentreX() + sc(54), lowpassArea().getY() + fs_titelLabel()));
	
	Line<float> lateArea(Point<float>(lateArea().getCentreX() - sc(58), lateArea().getY() + fs_titelLabel()),
		Point<float>(lateArea().getCentreX() + sc(58), lateArea().getY() + fs_titelLabel()));

	g.setColour(Colours::white);
	g.drawLine(inLine, lineSize);
	g.drawLine(outLine, lineSize);
	g.drawLine(earlyLine, lineSize);
	g.drawLine(highpassArea, lineSize);
	g.drawLine(peakArea, lineSize);
	g.drawLine(lowpassArea, lineSize);
	g.drawLine(lateArea, lineSize);
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
//Layout
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float PlasmaAudioProcessorEditor::sc(float val) 
{	
	float factor = float(scaling) / 100.0f;
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
void PlasmaAudioProcessorEditor::buttonClicked(Button* button)
{
	if (button == &scaleUpButton) 
	{
		if (scaling < 400)
		{
			scaling += 20;
			auto userSettings = applicationProperties.getUserSettings();
			auto commonSettings = applicationProperties.getCommonSettings(false);
			userSettings->setValue("scale", scaling);
			userSettings->save();
			resized();
		}
	}
	else if (button == &scaleDownButton)
	{
		if (scaling >= 40)
		{
			scaling -= 20;
			auto userSettings = applicationProperties.getUserSettings();
			auto commonSettings = applicationProperties.getCommonSettings(false);
			userSettings->setValue("scale", scaling);
			userSettings->save();
			resized();
		}
	}
}
void PlasmaAudioProcessorEditor::resized()
{
	int knobSize = 120;
	///////////////////////////////////////////////////////////////////////////////////////////
	//Monitor
	responseCurveComponent.setBounds(
		monitorArea().getX(), 
		monitorArea().getY() + 10, 
		monitorArea().getWidth() - 10, 
		monitorArea().getHeight() - 2 * sc(padding));
	responseCurveComponent.update();
	//loudnessMeterIn.setBounds(220, 60, 620, 155);
	//loudnessMeterOut.setBounds(220, 215, 620, 155);
	tooltipLabel.setBounds(
		monitorArea().getX() + sc(padding), 
		monitorArea().getY() + sc(padding), 
		sc(300), 
		sc(40));
	auto logoX = headerArea().getCentreX() - sc(100);
	plasmaLabel.setBounds(logoX, sc(-42), sc(200), sc(100));
	plasmaLabel.setFontSize(sc(100));
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
		sc (110), 
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
	//Update Labels
	for (auto* label : getLabels())
	{
		label->resize();
	}
	setSize(lateArea().getRight() + sc(padding), lateArea().getBottom() + sc(padding));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Scale Knobs
	int scaleKnobSize = headerArea().getHeight() - 2 * (sc(padding));
	scaleDownButton.setBounds(
		getWidth() - scaleKnobSize - sc(padding),
		sc(padding),
		scaleKnobSize,
		scaleKnobSize);
	scaleUpButton.setBounds(
		scaleDownButton.getX() - sc(padding) - scaleKnobSize,
		sc(padding),
		scaleKnobSize,
		scaleKnobSize);
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Misc
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<juce::Component*> PlasmaAudioProcessorEditor::getComps()
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
		&responseCurveComponent,
		&mixSlider,
		&analyserSlider,
		&loudnessMeterIn,
		&loudnessMeterOut
    };
}

std::vector<CustomLabel*> PlasmaAudioProcessorEditor::getLabels()
{
	return
	{
		&tooltipLabel,
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

