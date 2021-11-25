#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

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


class PlasmaAudioProcessorEditor : public juce::AudioProcessorEditor,
    juce::AudioProcessorParameter::Listener,
    juce::Timer
{
public:
    PlasmaAudioProcessorEditor(PlasmaAudioProcessor&);
    ~PlasmaAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

    void parameterValueChanged(int parameterIndex, float newValue) override;
    void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override {};
    void timerCallback() override;
private:
    PlasmaAudioProcessor& audioProcessor;
    juce::Atomic<bool> parametersChanged { false };

    int sq(float value);
    int sl(float value);

    CustomRotarySlider highPassFreqSlider, lowPassFreqSlider, peakFreqSlider;
    CustomRotarySlider biasSlider, lateBiasSlider, driveTypeSlider, lateDriveTypeSlider;
    CustomRotarySlider highPassResonanceSlider, lowPassResonanceSlider, peakGainSlider;
    CustomRotarySlider highPassResonanceQualitySlider, lowPassResonanceQualitySlider, peakQualitySlider;
    CustomRotarySlider highPassSlopeSlider, lowPassSlopeSlider;

    CustomSlider gainSlider, driveSlider, girthSlider, lateGirthSlider, lateDriveSlider, preGainSlider;

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

    ImageComponent screenImageComponent;

    //Response Curve
    MonoChain monoChain;

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
