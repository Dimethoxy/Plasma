#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "CustomRotarySlider.h"
#include "ResponseCurveComponent.h"
#include "LoudnessMeterComponent.h"

enum FontSizes
{
    Main,
    Titel,
    Tooltipp
};

class CustomLabel : public juce::Label
{
public:
    CustomLabel(String text, int size, Justification justification, bool underline)
    {
        setFontSize(size);
        setText(text, juce::dontSendNotification);
        setFont(getFont().withHeight(getFontSize()));
        setJustificationType(justification);
    }
    void resize()
    {
        setFont(getFont().withHeight(getScaledFontSize()));
    }
private:
    int fontSize;
    void setFontSize(int size)
    {
        fontSize = size;
    }
    Typeface::Ptr getTypeface() 
    {
        Typeface::Ptr typeface = Typeface::createSystemTypefaceFor(BinaryData::PoppinsMedium_ttf, BinaryData::PoppinsMedium_ttfSize);
        return typeface;
    }
    Font getFont()
    {
        Font font(getTypeface());
        return font;
    }
       
    float getFontSize()
    {
        float factor = 1.0f;//getBounds().getHeight() / 100.0f;
        switch (fontSize)
        {
        case FontSizes::Main:
        {
            return 28.0 * factor;
        }
        case FontSizes::Titel:
        {
            return 42.0 * factor;
        }
        }
    }
    float getScaledFontSize()
    {
        float factor = getBounds().getHeight() / 40.0f;
        switch (fontSize)
        {
        case FontSizes::Main:
        {
            return 28.0 * factor;
        }
        case FontSizes::Titel:
        {
            return 42.0 * factor;
        }
        }
    }
};

class ScaleButton : public juce::TextButton
{

private:
    Typeface::Ptr getCustomTypeface()
    {
        Typeface::Ptr typeface = Typeface::createSystemTypefaceFor(BinaryData::PoppinsMedium_ttf, BinaryData::PoppinsMedium_ttfSize);
        return typeface;
    }
    Font getCustomFont()
    {
        Font font(getCustomTypeface());
        return font;
    }
};

class PlasmaLabel : public juce::Label
{
public:
    PlasmaLabel()
    {
        setText("PLASMA", juce::dontSendNotification);
        setFont(getFont().withHeight(100));
        setJustificationType(Justification::centredTop);
    }
    void setFontSize(int size)
    {
        setFont(getFont().withHeight(size));
    }
private:
    Font getFont()
    {
        Font font(getTypeFace());
        return font;
    }
    Typeface::Ptr getTypeFace()
    {
       Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::SedgwickAveDisplayRegular_ttf, BinaryData::SedgwickAveDisplayRegular_ttfSize);
       return tface;
    }
};

class PlasmaAudioProcessorEditor : public juce::AudioProcessorEditor, 
                                   public Timer,
                                   public Button::Listener
{
public:
    PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
    ~PlasmaAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    void timerCallback() override;
    void buttonClicked(Button* button) override;
private:
    //Scaling
    TextButton scaleUpButton;
    TextButton scaleDownButton;
    TextButton configButton;


    //Audio Processor
    PlasmaAudioProcessor& audioProcessor;

    //Config
    ApplicationProperties applicationProperties;
    PropertiesFile::Options options;
    int scaling = 100; 

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
        lateLabel;

    //Label Vector
    std::vector<CustomLabel*> getLabels();

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
