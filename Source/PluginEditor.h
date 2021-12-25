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
inline int sqw(float value)
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

//Big Rotary
struct BigRotaryLookAndFeel : juce::LookAndFeel_V4
{
    void drawRotarySlider(juce::Graphics& g,
        int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle,
        float rotaryEndAngle,
        juce::Slider&) override;
	Image knobImage = ImageCache::getFromMemory(BinaryData::Knob_png, BinaryData::Knob_pngSize);
	/*
	Image rotaryBaseImage = ImageCache::getFromMemory(BinaryData::RotaryBase_png, BinaryData::RotaryBase_pngSize);
	const Image indicatorImage[95] = {
	ImageCache::getFromMemory(BinaryData::Indicator_00_png, BinaryData::Indicator_00_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_01_png, BinaryData::Indicator_01_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_02_png, BinaryData::Indicator_02_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_03_png, BinaryData::Indicator_03_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_04_png, BinaryData::Indicator_04_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_05_png, BinaryData::Indicator_05_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_06_png, BinaryData::Indicator_06_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_07_png, BinaryData::Indicator_07_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_08_png, BinaryData::Indicator_08_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_09_png, BinaryData::Indicator_09_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_10_png, BinaryData::Indicator_10_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_11_png, BinaryData::Indicator_11_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_12_png, BinaryData::Indicator_12_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_13_png, BinaryData::Indicator_13_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_14_png, BinaryData::Indicator_14_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_15_png, BinaryData::Indicator_15_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_16_png, BinaryData::Indicator_16_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_17_png, BinaryData::Indicator_17_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_18_png, BinaryData::Indicator_18_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_19_png, BinaryData::Indicator_19_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_20_png, BinaryData::Indicator_20_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_21_png, BinaryData::Indicator_21_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_22_png, BinaryData::Indicator_22_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_23_png, BinaryData::Indicator_23_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_24_png, BinaryData::Indicator_24_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_25_png, BinaryData::Indicator_25_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_26_png, BinaryData::Indicator_26_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_27_png, BinaryData::Indicator_27_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_28_png, BinaryData::Indicator_28_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_29_png, BinaryData::Indicator_29_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_30_png, BinaryData::Indicator_30_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_31_png, BinaryData::Indicator_31_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_32_png, BinaryData::Indicator_32_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_33_png, BinaryData::Indicator_33_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_34_png, BinaryData::Indicator_34_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_35_png, BinaryData::Indicator_35_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_36_png, BinaryData::Indicator_36_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_37_png, BinaryData::Indicator_37_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_38_png, BinaryData::Indicator_38_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_39_png, BinaryData::Indicator_39_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_40_png, BinaryData::Indicator_40_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_41_png, BinaryData::Indicator_41_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_42_png, BinaryData::Indicator_42_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_43_png, BinaryData::Indicator_43_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_44_png, BinaryData::Indicator_44_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_45_png, BinaryData::Indicator_45_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_46_png, BinaryData::Indicator_46_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_47_png, BinaryData::Indicator_47_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_48_png, BinaryData::Indicator_48_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_49_png, BinaryData::Indicator_49_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_50_png, BinaryData::Indicator_50_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_51_png, BinaryData::Indicator_51_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_52_png, BinaryData::Indicator_52_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_53_png, BinaryData::Indicator_53_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_54_png, BinaryData::Indicator_54_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_55_png, BinaryData::Indicator_55_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_56_png, BinaryData::Indicator_56_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_57_png, BinaryData::Indicator_57_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_58_png, BinaryData::Indicator_58_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_59_png, BinaryData::Indicator_59_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_60_png, BinaryData::Indicator_60_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_61_png, BinaryData::Indicator_61_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_62_png, BinaryData::Indicator_62_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_63_png, BinaryData::Indicator_63_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_64_png, BinaryData::Indicator_64_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_65_png, BinaryData::Indicator_65_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_66_png, BinaryData::Indicator_66_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_67_png, BinaryData::Indicator_67_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_68_png, BinaryData::Indicator_68_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_69_png, BinaryData::Indicator_69_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_70_png, BinaryData::Indicator_70_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_71_png, BinaryData::Indicator_71_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_72_png, BinaryData::Indicator_72_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_73_png, BinaryData::Indicator_73_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_74_png, BinaryData::Indicator_74_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_75_png, BinaryData::Indicator_75_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_76_png, BinaryData::Indicator_76_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_77_png, BinaryData::Indicator_77_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_78_png, BinaryData::Indicator_78_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_79_png, BinaryData::Indicator_79_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_80_png, BinaryData::Indicator_80_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_81_png, BinaryData::Indicator_81_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_82_png, BinaryData::Indicator_82_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_83_png, BinaryData::Indicator_83_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_84_png, BinaryData::Indicator_84_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_85_png, BinaryData::Indicator_85_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_86_png, BinaryData::Indicator_86_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_87_png, BinaryData::Indicator_87_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_88_png, BinaryData::Indicator_88_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_89_png, BinaryData::Indicator_89_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_90_png, BinaryData::Indicator_90_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_91_png, BinaryData::Indicator_91_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_92_png, BinaryData::Indicator_92_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_93_png, BinaryData::Indicator_93_pngSize),
	ImageCache::getFromMemory(BinaryData::Indicator_94_png, BinaryData::Indicator_94_pngSize)
	};
	*/


};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sliders
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//RotaryWithLabels
struct CustomRotary : juce::Slider
{   
    //Constructor
    CustomRotary(juce::RangedAudioParameter& rap, const juce::String& unitSuffix, const juce::String& name) :
        juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox),
        param(&rap)
    {
        //Look and Feel
		setTextValueSuffix(unitSuffix);
        setLookAndFeel(&lnf);
		setName(name);
    }

    //Destructor
    ~CustomRotary()
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
    BigRotaryLookAndFeel lnf;
    juce::RangedAudioParameter* param;
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
    CustomRotary 
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
		preGainSlider;
        

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
        gainSliderAttachment;
    std::vector<juce::Component*> getComps();

    //Image Components
    ImageComponent screenImageComponent;
	Image backgroundImage = ImageCache::getFromMemory(BinaryData::Background_png, BinaryData::Background_pngSize);

    //End
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessorEditor);
};
