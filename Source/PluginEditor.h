#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "CustomRotarySlider.h"
#include "ResponseCurveComponent.h"
#include "LoudnessMeterComponent.h"
class CustomLabel : public juce::Label
{
public:
    CustomLabel(String text, float size, Justification justification, bool underline)
    {
        Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::PoppinsMedium_ttf, BinaryData::PoppinsMedium_ttfSize);
        Font popFont(tface);
        //popFont.setUnderline(underline);
        //popFont.setExtraKerningFactor(1);
        setText(text, juce::dontSendNotification);
        setFont(popFont.withHeight(size));
        setJustificationType(justification);
    }    
};

class PlasmaLabel : public juce::Label
{
public:
    PlasmaLabel()
    {
        Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::SedgwickAveDisplayRegular_ttf , BinaryData::SedgwickAveDisplayRegular_ttfSize);
        Font font(tface);
        setText("PLASMA", juce::dontSendNotification);
        setFont(font.withHeight(100.0));
        setJustificationType(Justification::centredTop);
    }
};

class PlasmaAudioProcessorEditor : public juce::AudioProcessorEditor, public Timer
{
public:
    PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
    ~PlasmaAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    void timerCallback() override;
private:
    //Audio Processor
    PlasmaAudioProcessor& audioProcessor;	

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
		mixSlider,
		analyserSlider;
        

    //Response Curve Component
    ResponseCurveComponent responseCurveComponent;

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
        lateLabel;

    //Label Vector
    std::vector<CustomLabel*> getLabels();

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
