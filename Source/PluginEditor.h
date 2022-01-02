#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Math
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int sl(float value)
{
	return round(value * 1.0f);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sliders
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CustomLookAndFeel : juce::LookAndFeel_V4
{
    void drawRotarySlider(juce::Graphics& g,
        int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle,
        float rotaryEndAngle,
        juce::Slider&) override;
};

struct CustomRotarySlider : juce::Slider
{   
    //Constructor
    CustomRotarySlider(juce::RangedAudioParameter& rap, const juce::String& unitSuffix, const juce::String& name) :
        juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox),
        param(&rap)
    {
		setTextValueSuffix(unitSuffix);
        setLookAndFeel(&lnf);
		setName(name);
        setColour(Slider::rotarySliderFillColourId, Colour(255, 0, 0)); 
    }

    //Destructor
    ~CustomRotarySlider()
    {
        setLookAndFeel(nullptr);
    }
    //Misc
	const juce::String name = "Slider";
    void paint(juce::Graphics& g) override;
    juce::Rectangle<int> getSliderBounds() const;
    int getTexHeight() const { return 14; }
    juce::String getDisplayString() const;
private:
    CustomLookAndFeel lnf;
    juce::RangedAudioParameter* param;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Visualizers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct ResponseCurveComponent : juce::Component,
    juce::AudioProcessorParameter::Listener,
    juce::Timer
{
    ResponseCurveComponent(PlasmaAudioProcessor&);
    ~ResponseCurveComponent();

	void parameterValueChanged(int parameterIndex, float newValue) override;
	void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override {};
	void timerCallback() override;
    void update();
    void paint(juce::Graphics& g) override;

private:
	PlasmaAudioProcessor& audioProcessor;
    juce::Atomic<bool> parametersChanged{ false };
    MonoChain monoChain;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AudioProcessorEditor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PlasmaAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
    ~PlasmaAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

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

    //Image Components
    ImageComponent screenImageComponent;
	Image backgroundImage = ImageCache::getFromMemory(BinaryData::Background_png, BinaryData::Background_pngSize);

	//
	Label tooltipLabel;

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
