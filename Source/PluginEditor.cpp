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
	tooltipLabel("", 24.00, Justification::centredLeft, false),
	//Drive
	gainLabel("Gain", fs_mainLabel(), Justification::centredTop, false),
	driveLabel("Drive", fs_mainLabel(), Justification::centredTop, false),
	girthLabel("Girth", fs_mainLabel(), Justification::centredTop, false),
	biasLabel("Symmetry", fs_mainLabel(), Justification::centredTop, false),
	driveTypeLabel("Type", fs_mainLabel(), Justification::centredTop, false),
	//Highpass
	highPassFreqLabel("Frequency", fs_mainLabel(), Justification::centredTop, false),
	highPassResonanceLabel("Resonance", fs_mainLabel(), Justification::centredTop, false),
	highPassResonanceQualityLabel("Q", fs_mainLabel(), Justification::centredTop, false),
	highPassSlopeLabel("Slope", fs_mainLabel(), Justification::centredTop, false),
	//Peak
	peakStereoLabel("Stereo", fs_mainLabel(), Justification::centredTop, false),
	peakFreqLabel("Frequency", fs_mainLabel(), Justification::centredTop, false),
	peakGainLabel("Gain", fs_mainLabel(), Justification::centredTop, false),
	peakQualityLabel("Q", fs_mainLabel(), Justification::centredTop, false),
	//Lowpass
	lowPassFreqLabel("Frequency", fs_mainLabel(), Justification::centredTop, false),
	lowPassResonanceLabel("Resonance", fs_mainLabel(), Justification::centredTop, false),
	lowPassResonanceQualityLabel("Q", fs_mainLabel(), Justification::centredTop, false),
	lowPassSlopeLabel("Slope", fs_mainLabel(), Justification::centredTop, false),
	//lateDrive
	lateBiasLabel("Symmetry", fs_mainLabel(), Justification::centredTop, false),
	lateDriveTypeLabel("Type", fs_mainLabel(), Justification::centredTop, false),
	lateGirthLabel("Girth", fs_mainLabel(), Justification::centredTop, false),
	lateDriveLabel("Drive", fs_mainLabel(), Justification::centredTop, false),
	preGainLabel("Gain", fs_mainLabel(), Justification::centredTop, false),
	mixLabel("Mix", fs_mainLabel(), Justification::centredTop, false),
	analyserLabel("Analyser", fs_mainLabel(), Justification::centredTop, false),
	//Titels
	inLabel("Input", fs_titelLabel(), Justification::centredTop, true),
	outLabel("Output", fs_titelLabel(), Justification::centredTop, true),
	earlyLabel("Distortion", fs_titelLabel(), Justification::centredTop, true),
	highpassLabel("Highpass", fs_titelLabel(), Justification::centredTop, true),
	peakLabel("Peak", fs_titelLabel(), Justification::centredTop, true),
	lowpassLabel("Lowpass", fs_titelLabel(), Justification::centredTop, true),
	lateLabel("Distortion", fs_titelLabel(), Justification::centredTop, true),
	plasmaLabel()
{
	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
	}
	for (auto* label : getLabels())
	{
		addAndMakeVisible(label);
	}
	addAndMakeVisible(plasmaLabel);

	//Tooltip
	Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::PoppinsMedium_ttf, BinaryData::PoppinsMedium_ttfSize);
	Font popFont(tface);
	tooltipLabel.setFont(popFont.withHeight(24.0));
	tooltipLabel.setJustificationType(juce::Justification::centredLeft);
	tooltipLabel.setText("", juce::dontSendNotification);
	addAndMakeVisible(tooltipLabel);

	setResizable(false, false);
	setSize(810, 940); //810 ... 1060
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
	g.fillRect(monitorArea().reduced(10));

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
	float lineSize = 2.0f;
	float lineOffset = 0.0f;
	Line<float> inLine(Point<float>(inArea().getCentreX() - 32, inArea().getY() + fs_titelLabel()),
		Point<float>(inArea().getCentreX() + 32, inArea().getY() + fs_titelLabel()));
	
	Line<float> outLine(Point<float>(outArea().getCentreX() - 42, outArea().getY() + fs_titelLabel()),
		Point<float>(outArea().getCentreX() + 42, outArea().getY() + fs_titelLabel()));
	
	Line<float> earlyLine(Point<float>(earlyArea().getCentreX() - 58, earlyArea().getY() + fs_titelLabel()),
		Point<float>(earlyArea().getCentreX() + 58, earlyArea().getY() + fs_titelLabel()));
	
	Line<float> highpassArea(Point<float>(highpassArea().getCentreX() - 56, highpassArea().getY() + fs_titelLabel()),
		Point<float>(highpassArea().getCentreX() + 56, highpassArea().getY() + fs_titelLabel()));
	
	Line<float> peakArea(Point<float>(peakArea().getCentreX() - 30, peakArea().getY() + fs_titelLabel()),
		Point<float>(peakArea().getCentreX() + 30, peakArea().getY() + fs_titelLabel()));
	
	Line<float> lowpassArea(Point<float>(lowpassArea().getCentreX() - 54, lowpassArea().getY() + fs_titelLabel()),
		Point<float>(lowpassArea().getCentreX() + 54, lowpassArea().getY() + fs_titelLabel()));
	
	Line<float> lateArea(Point<float>(lateArea().getCentreX() - 58, lateArea().getY() + fs_titelLabel()),
		Point<float>(lateArea().getCentreX() + 58, lateArea().getY() + fs_titelLabel()));

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
Rectangle<int> PlasmaAudioProcessorEditor::headerArea()
{
	Rectangle<int> area(0, 0, getWidth(), 50);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::inArea()
{
	Rectangle<int> area(10, headerArea().getBottom() + 10, boxWidth, 310);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::earlyArea()
{
	Rectangle<int> area(10, 380, boxWidth, boxHeight);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::highpassArea()
{
	Rectangle<int> area(earlyArea().getRight()+10, 380, boxWidth, boxHeight);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::peakArea()
{
	Rectangle<int> area(highpassArea().getRight() + 10, 380, boxWidth, boxHeight);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::lowpassArea()
{
	Rectangle<int> area(peakArea().getRight() + 10, 380, boxWidth, boxHeight);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::lateArea()
{
	Rectangle<int> area(lowpassArea().getRight() + 10, 380, boxWidth, boxHeight);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::outArea()
{
	Rectangle<int> area(lateArea().getX(), headerArea().getBottom() + 10, boxWidth, 310);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::monitorArea()
{
	Rectangle<int> area(highpassArea().getX(), 60, lowpassArea().getRight() - highpassArea().getX(), 310);
	return area;
}
float PlasmaAudioProcessorEditor::fs_mainLabel()
{
	return 28.0f;
}
float PlasmaAudioProcessorEditor::fs_titelLabel()
{
	return 42.0f;
}
void PlasmaAudioProcessorEditor::resized()
{
	int knobSize = 120;

	responseCurveComponent.setBounds(monitorArea().getX(), monitorArea().getY() + 10, monitorArea().getWidth() - 10, 290);
	responseCurveComponent.update();
	//loudnessMeterIn.setBounds(220, 60, 620, 155);
	//loudnessMeterOut.setBounds(220, 215, 620, 155);
	tooltipLabel.setBounds(monitorArea().getX() + 15, monitorArea().getY() + 10, 300, 40);
	plasmaLabel.setBounds(0, -42, getWidth(), 100);

	//In
	inLabel.setBounds(inArea().getX(), inArea().getY() + padding, inArea().getWidth(), knobSize / 2);
	preGainSlider.setBounds(inArea().getCentreX() - knobSize / 2, 110, knobSize, knobSize);
	preGainLabel.setBounds(
		preGainSlider.getBounds().getX(),
		preGainSlider.getBounds().getY() + preGainSlider.getBounds().getHeight() * knobLabelHeight,
		preGainSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	analyserSlider.setBounds(inArea().getCentreX() - knobSize / 2, 230, knobSize, knobSize);
	analyserLabel.setBounds(
		analyserSlider.getBounds().getX(),
		analyserSlider.getBounds().getY() + analyserSlider.getBounds().getHeight() * knobLabelHeight,
		analyserSlider.getBounds().getWidth(),
		2 * fs_mainLabel());

    //Early
	earlyLabel.setBounds(earlyArea().getX(), earlyArea().getY() + padding, earlyArea().getWidth(), knobSize / 2);
	driveTypeSlider.setBounds(earlyArea().getCentreX() - knobSize / 2, 430, knobSize, knobSize);
	driveTypeLabel.setBounds(
		driveTypeSlider.getBounds().getX(),
		driveTypeSlider.getBounds().getY() + driveTypeSlider.getBounds().getHeight() * knobLabelHeight,
		driveTypeSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	biasSlider.setBounds(earlyArea().getCentreX() - knobSize / 2, 550, knobSize, knobSize);
	biasLabel.setBounds(
		biasSlider.getBounds().getX(),
		biasSlider.getBounds().getY() + biasSlider.getBounds().getHeight() * knobLabelHeight,
		biasSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
    girthSlider.setBounds(earlyArea().getCentreX() - knobSize / 2, 670, knobSize, knobSize);
	girthLabel.setBounds(
		girthSlider.getBounds().getX(),
		girthSlider.getBounds().getY() + girthSlider.getBounds().getHeight() * knobLabelHeight,
		girthSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	driveSlider.setBounds(earlyArea().getCentreX() - knobSize / 2, 790, knobSize, knobSize);
	driveLabel.setBounds(
		driveSlider.getBounds().getX(),
		driveSlider.getBounds().getY() + driveSlider.getBounds().getHeight() * knobLabelHeight,
		driveSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	
    //Highpass
	highpassLabel.setBounds(highpassArea().getX(), highpassArea().getY() + padding, highpassArea().getWidth(), knobSize / 2);
	highPassSlopeSlider.setBounds(highpassArea().getCentreX() - knobSize / 2, 430, knobSize, knobSize);
	highPassSlopeLabel.setBounds(
		highPassSlopeSlider.getBounds().getX(),
		highPassSlopeSlider.getBounds().getY() + highPassSlopeSlider.getBounds().getHeight() * knobLabelHeight,
		highPassSlopeSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	highPassResonanceQualitySlider.setBounds(highpassArea().getCentreX() - knobSize / 2, 550, knobSize, knobSize);
	highPassResonanceQualityLabel.setBounds(
		highPassResonanceQualitySlider.getBounds().getX(),
		highPassResonanceQualitySlider.getBounds().getY() + highPassResonanceQualitySlider.getBounds().getHeight() * knobLabelHeight,
		highPassResonanceQualitySlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	highPassResonanceSlider.setBounds(highpassArea().getCentreX() - knobSize / 2, 670, knobSize, knobSize);
	highPassResonanceLabel.setBounds(
		highPassResonanceSlider.getBounds().getX(),
		highPassResonanceSlider.getBounds().getY() + highPassResonanceSlider.getBounds().getHeight() * knobLabelHeight,
		highPassResonanceSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	highPassFreqSlider.setBounds(highpassArea().getCentreX() - knobSize / 2, 790, knobSize, knobSize);
	highPassFreqLabel.setBounds(
		highPassFreqSlider.getBounds().getX(),
		highPassFreqSlider.getBounds().getY() + highPassFreqSlider.getBounds().getHeight() * knobLabelHeight,
		highPassFreqSlider.getBounds().getWidth(),
		2 * fs_mainLabel());

    //Peak
	peakLabel.setBounds(peakArea().getX(), peakArea().getY() + padding, peakArea().getWidth(), knobSize / 2);
	peakStereoSlider.setBounds(peakArea().getCentreX() - knobSize / 2, 430, knobSize, knobSize);
	peakStereoLabel.setBounds(
		peakStereoSlider.getBounds().getX(),
		peakStereoSlider.getBounds().getY() + peakStereoSlider.getBounds().getHeight() * knobLabelHeight,
		peakStereoSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	peakQualitySlider.setBounds(peakArea().getCentreX() - knobSize / 2, 550, knobSize, knobSize);
	peakQualityLabel.setBounds(
		peakQualitySlider.getBounds().getX(),
		peakQualitySlider.getBounds().getY() + peakQualitySlider.getBounds().getHeight() * knobLabelHeight,
		peakQualitySlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	peakGainSlider.setBounds(peakArea().getCentreX() - knobSize / 2, 670, knobSize, knobSize);
	peakGainLabel.setBounds(
		peakGainSlider.getBounds().getX(),
		peakGainSlider.getBounds().getY() + peakGainSlider.getBounds().getHeight() * knobLabelHeight,
		peakGainSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	peakFreqSlider.setBounds(peakArea().getCentreX() - knobSize / 2, 790, knobSize, knobSize);
	peakFreqLabel.setBounds(
		peakFreqSlider.getBounds().getX(),
		peakFreqSlider.getBounds().getY() + peakFreqSlider.getBounds().getHeight() * knobLabelHeight,
		peakFreqSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	

    //Lowpass
	lowpassLabel.setBounds(lowpassArea().getX(), lowpassArea().getY() + padding, lowpassArea().getWidth(), knobSize / 2);
	lowPassSlopeSlider.setBounds(lowpassArea().getCentreX() - knobSize / 2, 430, knobSize, knobSize);
	lowPassSlopeLabel.setBounds(
		lowPassSlopeSlider.getBounds().getX(),
		lowPassSlopeSlider.getBounds().getY() + lowPassSlopeSlider.getBounds().getHeight() * knobLabelHeight,
		lowPassSlopeSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	lowPassResonanceQualitySlider.setBounds(lowpassArea().getCentreX() - knobSize / 2, 550, knobSize, knobSize);
	lowPassResonanceQualityLabel.setBounds(
		lowPassResonanceQualitySlider.getBounds().getX(),
		lowPassResonanceQualitySlider.getBounds().getY() + lowPassResonanceQualitySlider.getBounds().getHeight() * knobLabelHeight,
		lowPassResonanceQualitySlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	lowPassResonanceSlider.setBounds(lowpassArea().getCentreX() - knobSize / 2, 670, knobSize, knobSize);
	lowPassResonanceLabel.setBounds(
		lowPassResonanceSlider.getBounds().getX(),
		lowPassResonanceSlider.getBounds().getY() + lowPassResonanceSlider.getBounds().getHeight() * knobLabelHeight,
		lowPassResonanceSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	lowPassFreqSlider.setBounds(lowpassArea().getCentreX() - knobSize / 2, 790, knobSize, knobSize);
	lowPassFreqLabel.setBounds(
		lowPassFreqSlider.getBounds().getX(),
		lowPassFreqSlider.getBounds().getY() + lowPassFreqSlider.getBounds().getHeight() * knobLabelHeight,
		lowPassFreqSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
   
	//Latedrive
	lateLabel.setBounds(lateArea().getX(), lateArea().getY() + padding, lateArea().getWidth(), knobSize / 2);
	lateDriveTypeSlider.setBounds(lateArea().getCentreX() - knobSize / 2, 430, knobSize, knobSize);
	lateDriveTypeLabel.setBounds(
		lateDriveTypeSlider.getBounds().getX(),
		lateDriveTypeSlider.getBounds().getY() + lateDriveTypeSlider.getBounds().getHeight() * knobLabelHeight,
		lateDriveTypeSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	lateBiasSlider.setBounds(lateArea().getCentreX() - knobSize / 2, 550, knobSize, knobSize);
	lateBiasLabel.setBounds(
		lateBiasSlider.getBounds().getX(),
		lateBiasSlider.getBounds().getY() + lateBiasSlider.getBounds().getHeight() * knobLabelHeight,
		lateBiasSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	lateGirthSlider.setBounds(lateArea().getCentreX() - knobSize / 2, 670, knobSize, knobSize);
	lateGirthLabel.setBounds(
		lateGirthSlider.getBounds().getX(),
		lateGirthSlider.getBounds().getY() + lateGirthSlider.getBounds().getHeight() * knobLabelHeight,
		lateGirthSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	lateDriveSlider.setBounds(lateArea().getCentreX() - knobSize / 2, 790, knobSize, knobSize);
	lateDriveLabel.setBounds(
		lateDriveSlider.getBounds().getX(),
		lateDriveSlider.getBounds().getY() + lateDriveSlider.getBounds().getHeight() * knobLabelHeight,
		lateDriveSlider.getBounds().getWidth(),
		2 * fs_mainLabel());

	//Out
	outLabel.setBounds(outArea().getX(), outArea().getY() + padding, outArea().getWidth(), knobSize / 2);
	gainSlider.setBounds(outArea().getCentreX() - knobSize / 2, 110, knobSize, knobSize);
	gainLabel.setBounds(
		gainSlider.getBounds().getX(),
		gainSlider.getBounds().getY() + gainSlider.getBounds().getHeight() * knobLabelHeight,
		gainSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
	mixSlider.setBounds(outArea().getCentreX() - knobSize / 2, 230, knobSize, knobSize);
	mixLabel.setBounds(
		mixSlider.getBounds().getX(),
		mixSlider.getBounds().getY() + mixSlider.getBounds().getHeight() * knobLabelHeight,
		mixSlider.getBounds().getWidth(),
		2 * fs_mainLabel());
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

