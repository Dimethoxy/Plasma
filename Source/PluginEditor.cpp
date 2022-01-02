#include "PluginProcessor.h"
#include "PluginEditor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PlasmaAudioProcessorEditor::PlasmaAudioProcessorEditor(PlasmaAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p),
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
	peakStereoSlider(*audioProcessor.apvts.getParameter("Peak Stereo"), "%", "Stereo"),
	peakFreqSlider(*audioProcessor.apvts.getParameter("Peak Freq"), "Hz", "Peak"),
	peakGainSlider(*audioProcessor.apvts.getParameter("Peak Gain"), "dB", "Resonance"),
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
	//Attachments
	preGainSliderAttachment(audioProcessor.apvts, "Pre Gain", preGainSlider),
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
    lowPassFreqSliderAttachment(audioProcessor.apvts, "Lowpass Freq", lowPassFreqSlider),
    lowPassSlopeSliderAttachment(audioProcessor.apvts, "Lowpass Slope", lowPassSlopeSlider),
    lowPassResonanceQualitySliderAttachment(audioProcessor.apvts, "Lowpass Resonance Q", lowPassResonanceQualitySlider),
    lowPassResonanceSliderAttachment(audioProcessor.apvts, "Lowpass Resonance", lowPassResonanceSlider),
    lateBiasSliderAttachment(audioProcessor.apvts, "Late Bias", lateBiasSlider),
    lateDriveTypeSliderAttachment(audioProcessor.apvts, "Late Distortion Type", lateDriveTypeSlider),
	lateGirthSliderAttachment(audioProcessor.apvts, "Late Girth", lateGirthSlider),
	lateDriveSliderAttachment(audioProcessor.apvts, "Late Drive", lateDriveSlider),
	gainSliderAttachment(audioProcessor.apvts, "Gain", gainSlider),
	mixSliderAttachment(audioProcessor.apvts, "Mix", mixSlider),
	analyserSliderAttachment(audioProcessor.apvts, "Analyser Type", analyserSlider)

{
	//Make all components visible
	for (auto* comp : getComps())
	{
		addAndMakeVisible(comp);
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

void PlasmaAudioProcessorEditor::paint (juce::Graphics& g)
{
    using namespace juce;
    //Background 2e2f31
    //g.fillAll(Colour(46, 47, 49));
	g.fillAll(Colour(20, 20, 20));
	g.drawImageAt(backgroundImage, 0, 0);
	bool clear = true;
	for (auto* comp : getComps())
	{
		if (comp->isMouseButtonDown()) 
		{
			tooltipLabel.setText(comp->getHelpText(), juce::dontSendNotification);
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
/////////////////////////////////////////////////W///////////////////////////////////////////////////////////////////

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
	driveTypeSlider.setBounds(50, 430, 120, 120);
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

