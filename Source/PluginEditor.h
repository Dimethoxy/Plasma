#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Math
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int sq(float value)
{
	return round(value * 50.0f);
}
inline int sl(float value)
{
	return round(value * 1.0f);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sliders
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//LookAndFeel
struct LookAndFeel : juce::LookAndFeel_V4
{
    void drawRotarySlider(juce::Graphics&,
        int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle,
        float rotaryEndAngle,
        juce::Slider&) override { };
};

//RotaryWithLabels
struct RotarySliderWithLabels : juce::Slider
{
    RotarySliderWithLabels(juce::RangedAudioParameter& rap, const juce::String& unitSuffix) :
        juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox),
        param(&rap),
        suffix(unitSuffix)
    {
        //setLookAndFeel(&lnf);
    }
    ~RotarySliderWithLabels()
    {
        setLookAndFeel(nullptr);
    }
    void paint(juce::Graphics& g) override;
    juce::Rectangle<int> getSliderBounds() const;
    int getTexHeight() const { return 14; }
    juce::String getDisplayString() const;
private:
    juce::RangedAudioParameter* param;
    juce::String suffix;
};

struct CustomRotarySlider : juce::Slider
{
    CustomRotarySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
        juce::Slider::TextEntryBoxPosition::NoTextBox)
    {

    }
};

struct CustomSlider : juce::Slider
{
	CustomSlider() : juce::Slider(juce::Slider::SliderStyle::LinearVertical,
		juce::Slider::TextEntryBoxPosition::NoTextBox)
	{

	}
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

    //Slider Components
    CustomRotarySlider highPassFreqSlider, lowPassFreqSlider, peakFreqSlider;
    CustomRotarySlider biasSlider, lateBiasSlider, driveTypeSlider, lateDriveTypeSlider;
    CustomRotarySlider highPassResonanceSlider, lowPassResonanceSlider, peakGainSlider;
    CustomRotarySlider highPassResonanceQualitySlider, lowPassResonanceQualitySlider, peakQualitySlider;
    CustomRotarySlider highPassSlopeSlider, lowPassSlopeSlider;
    CustomSlider gainSlider, driveSlider, girthSlider, lateGirthSlider, lateDriveSlider, preGainSlider;

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
        gainSliderAttachment;
    std::vector<juce::Component*> getComps();

    //Image Components
    ImageComponent screenImageComponent;

    //Math
	

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
