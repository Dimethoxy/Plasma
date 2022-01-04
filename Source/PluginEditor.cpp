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
	tooltipLabel("", 24.00, Justification::centredLeft),
	//Drive
	gainLabel("Gain", fs_mainLabel, Justification::centredTop),
	driveLabel("Drive", fs_mainLabel, Justification::centredTop),
	girthLabel("Girth", fs_mainLabel, Justification::centredTop),
	biasLabel("Symmertry", fs_mainLabel, Justification::centredTop),
	driveTypeLabel("Drive Type", fs_mainLabel, Justification::centredTop),
	//Highpass
	highPassFreqLabel("Frequency", fs_mainLabel, Justification::centredTop),
	highPassResonanceLabel("Resonance", fs_mainLabel, Justification::centredTop),
	highPassResonanceQualityLabel("Q", fs_mainLabel, Justification::centredTop),
	highPassSlopeLabel("Slope", fs_mainLabel, Justification::centredTop),
	//Peak
	peakStereoLabel("Stereo", fs_mainLabel, Justification::centredTop),
	peakFreqLabel("Frequency", fs_mainLabel, Justification::centredTop),
	peakGainLabel("Gain", fs_mainLabel, Justification::centredTop),
	peakQualityLabel("Q", fs_mainLabel, Justification::centredTop),
	//Lowpass
	lowPassFreqLabel("Frequency", fs_mainLabel, Justification::centredTop),
	lowPassResonanceLabel("Resonance", fs_mainLabel, Justification::centredTop),
	lowPassResonanceQualityLabel("Q", fs_mainLabel, Justification::centredTop),
	lowPassSlopeLabel("Slope", fs_mainLabel, Justification::centredTop),
	//lateDrive
	lateBiasLabel("Symmertry", fs_mainLabel, Justification::centredTop),
	lateDriveTypeLabel("Drive Type", fs_mainLabel, Justification::centredTop),
	lateGirthLabel("Girth", fs_mainLabel, Justification::centredTop),
	lateDriveLabel("Drive", fs_mainLabel, Justification::centredTop),
	preGainLabel("Gain", fs_mainLabel, Justification::centredTop),
	mixLabel("Mix", fs_mainLabel, Justification::centredTop),
	analyserLabel("Analyser", fs_mainLabel, Justification::centredTop)
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

	//Tooltip
	Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::PoppinsMedium_ttf, BinaryData::PoppinsMedium_ttfSize);
	Font popFont(tface);
	tooltipLabel.setFont(popFont.withHeight(24.0));
	tooltipLabel.setJustificationType(juce::Justification::centredLeft);
	tooltipLabel.setText("", juce::dontSendNotification);
	addAndMakeVisible(tooltipLabel);

	setResizable(false, false);
	setSize(1060, 940);
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
Rectangle<int> PlasmaAudioProcessorEditor::monitorArea()
{
	Rectangle<int> area(220, 60, 620, 310);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::inArea()
{
	Rectangle<int> area(10, 60, 200, 310);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::outArea()
{
	Rectangle<int> area(850, 60, 200, 310);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::earlyArea()
{
	Rectangle<int> area(10, 380, 200, 550);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::highpassArea()
{
	Rectangle<int> area(220, 380, 200, 550);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::peakArea()
{
	Rectangle<int> area(430, 380, 200, 550);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::lowpassArea()
{
	Rectangle<int> area(640, 380, 200, 550);
	return area;
}
Rectangle<int> PlasmaAudioProcessorEditor::lateArea()
{
	Rectangle<int> area(850, 380, 200, 550);
	return area;
}
void PlasmaAudioProcessorEditor::resized()
{
	//Analyzers
	responseCurveComponent.setBounds(220, 70, 620, 290);
	responseCurveComponent.update();
	//loudnessMeterIn.setBounds(220, 60, 620, 155);
	//loudnessMeterOut.setBounds(220, 215, 620, 155);
	tooltipLabel.setBounds(235, 70, 300, 40);

    //Early
    preGainSlider.setBounds(50, 110, 120, 120);
	preGainLabel.setBounds(
		preGainSlider.getBounds().getX(),
		preGainSlider.getBounds().getY() + preGainSlider.getBounds().getY()*0.85f,
		preGainSlider.getBounds().getWidth(),
		2 * fs_mainLabel);
	driveTypeSlider.setBounds(50, 430, 120, 120);
	driveTypeLabel.setBounds(
		driveTypeSlider.getBounds().getX(),
		driveTypeSlider.getBounds().getY() + driveTypeSlider.getBounds().getY() * 0.85f,
		driveTypeSlider.getBounds().getWidth(),
		2 * fs_mainLabel);
	biasSlider.setBounds(50, 550, 120, 120);
    girthSlider.setBounds(50, 670, 120, 120);
	driveSlider.setBounds(50, 790, 120, 120);
	

    //Highpass
	highPassSlopeSlider.setBounds(260, 430, 120, 120);
	highPassResonanceQualitySlider.setBounds(260, 550, 120, 120);
	highPassResonanceSlider.setBounds(260, 670, 120, 120);
	highPassFreqSlider.setBounds(260, 790, 120, 120);

    //Peak
	peakStereoSlider.setBounds(470, 430, 120, 120);
	peakQualitySlider.setBounds(470, 550, 120, 120);
	peakGainSlider.setBounds(470, 670, 120, 120);
	peakFreqSlider.setBounds(470, 790, 120, 120);
	

    //Lowpass
	lowPassSlopeSlider.setBounds(680, 430, 120, 120);
	lowPassResonanceQualitySlider.setBounds(680, 550, 120, 120);
	lowPassResonanceSlider.setBounds(680, 670, 120, 120);
	lowPassFreqSlider.setBounds(680, 790, 120, 120);
   
	//Latedrive
	gainSlider.setBounds(890, 110, 120, 120);
	lateDriveTypeSlider.setBounds(890, 430, 120, 120);
	lateBiasSlider.setBounds(890, 550, 120, 120);
	lateGirthSlider.setBounds(890, 670, 120, 120);
	lateDriveSlider.setBounds(890, 790, 120, 120);

	//Mix
	mixSlider.setBounds(890, 230, 120, 120);
	analyserSlider.setBounds(50, 230, 120, 120);
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
		&analyserLabel
	};
}

