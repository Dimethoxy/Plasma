#pragma once
#include <JuceHeader.h>

//Math
const float pi = 3.14159265358979323846;
float clamp(float d, float min, float max);

//Enums
enum ChainPositions
{
	HighPass,
    HighPassResonance,
	Peak,
	LowPass,
    LowPassResonance,
};
enum Slope
{
	Slope_12,
	Slope_24,
	Slope_36,
	Slope_48,
    Slope_60,
    Slope_72,
    Slope_84,
    Slope_96
};
enum AnalyserType
{
	Response,
	Waveform,
	Spectrum,
	Stereo
};
enum Distortion
{
	Hardclip,
	Softclip,
	Overdrive,
	Bitcrush,
	Atan,
	Sinus,
	Cosinus,
};

//Chain Settings
struct ChainSettings
{
	float drive{ 10.0f }, girth{ 0.0f }, bias{ 0.0f }, preGain{ 0.0f };
	float lateDrive{ 0.0f }, lateBias{ 0.0f }, lateGirth{ 0.0f }, gain{ 0.0f };
	float peakFreq{ 0 }, peakGain{ 0 }, peakQuality{ 1.0f }, peakStereo{ 0.0f };
	float highPassFreq{ 20.0f }, lowPassFreq{ 20.0f };
	float highPassResonanceQuality{ 1.0 }, highPassResonance{ 0.0 };
	float lowPassResonanceQuality{ 1.0 }, lowPassResonance{ 0.0 };
	float mix{ 100.0f };
	Slope highPassSlope{ Slope::Slope_12 }, lowPassSlope{ Slope::Slope_12 };
	AnalyserType analyserType{ AnalyserType::Response };
	Distortion driveType{ Distortion::Overdrive }, lateDriveType{ Distortion::Overdrive };
};
ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Filters
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//MonoChain
using Filter = juce::dsp::IIR::Filter<float>;
using PassFilter = juce::dsp::ProcessorChain<Filter, Filter, Filter, Filter, Filter, Filter, Filter, Filter >;
using MonoChain = juce::dsp::ProcessorChain<PassFilter, Filter, Filter, PassFilter, Filter>;

//Coefficients
using Coefficients = Filter::CoefficientsPtr;
void updateCoefficients(Coefficients& old, const Coefficients& replacements);

Coefficients makePeakFilter(const ChainSettings& chainSettings, double sampleRate, float offset);
Coefficients makeHighPassResonance(const ChainSettings& chainSettings, double sampleRate);
Coefficients makeLowPassResonance(const ChainSettings& chainSettings, double sampleRate);

template<int Index, typename ChainType, typename CoefficientType>
void update(ChainType& chain, const CoefficientType& coefficients)
{
	updateCoefficients(chain.template get<Index>().coefficients, coefficients[Index]);
	chain.template setBypassed<Index>(false);
}
template<typename ChainType, typename CoefficientType>
void updatePassFilter
(
	ChainType& filter,
	const CoefficientType& filterCoefficients,
	const Slope& filterSlope
)
{
	filter.template setBypassed<0>(true);
	filter.template setBypassed<1>(true);
	filter.template setBypassed<2>(true);
	filter.template setBypassed<3>(true);
	filter.template setBypassed<4>(true);
	filter.template setBypassed<5>(true);
	filter.template setBypassed<6>(true);
	filter.template setBypassed<7>(true);

	switch (filterSlope) {
	case Slope_96: {
		update<7>(filter, filterCoefficients);
	}
	case Slope_84: {
		update<6>(filter, filterCoefficients);
	}
	case Slope_72: {
		update<5>(filter, filterCoefficients);
	}
	case Slope_60: {
		update<4>(filter, filterCoefficients);
	}
	case Slope_48: {
		update<3>(filter, filterCoefficients);
	}
	case Slope_36: {
		update<2>(filter, filterCoefficients);
	}
	case Slope_24: {
		update<1>(filter, filterCoefficients);
	}
	case Slope_12: {
		update<0>(filter, filterCoefficients);
	}
	}
}

inline auto makeHighPassFilter(const ChainSettings& chainSettings, double sampleRate)
{
	return juce::dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(
			chainSettings.highPassFreq,
			sampleRate,
			2 * (chainSettings.highPassSlope + 1));
}
inline auto makeLowPassFilter(const ChainSettings& chainSettings, double sampleRate)
{
	return juce::dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(
		chainSettings.lowPassFreq,
		sampleRate,
		2 * (chainSettings.lowPassSlope + 1));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AudioProcessor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PlasmaAudioProcessor : public juce::AudioProcessor
{
public:
    //==============================================================================
    PlasmaAudioProcessor();
    ~PlasmaAudioProcessor() override;

    //==============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    //==============================================================================

    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    juce::AudioProcessorValueTreeState apvts{ *this, nullptr, "Parameters", createParameterLayout() };

private:
	AudioSampleBuffer cleanBuffer;
    MonoChain leftChain, rightChain;
    //Filters
    void updatePeakFilter(const ChainSettings& chainSettings);
    void updateHighPassResonance(const ChainSettings& chainSettings);
    void updateLowPassResonance(const ChainSettings& chainSettings);
    void updateHighPass(const ChainSettings& chainSettings);
    void updateLowPass(const ChainSettings& chainSettings);
    void updateFilters();

    //Distortion
    template<typename Data, typename Drive, typename Distortion>
    void distort(Data& data, Drive& drive, Distortion& type){
		switch (type){
		case Hardclip:{
			data = clamp(drive * data, -1.0, 1.0);
			break;
		}
		case Softclip:{
			data = (pi / 2) * atan(drive * data);
			break;
		}
		case Overdrive:{
			if (data > 0.0){
				data = clamp(pow(data, 1.0 / ((drive/4) + 0.75)), -1.0, 1.0);
			}
			else{
				data = -clamp(pow(-data, 1.0 / ((drive / 4) + 0.75)), -1.0, 1.0);
			}
			break;
		}
		case Bitcrush:{
			data = (2 * (ceil((data * ((10 / drive) * (10 / drive))) * 0.99) - 0.5)) / ((10 / drive) * (10 / drive));
			break;
		}
		case Atan:{
			data = clamp(2 * atan(drive * data), -1.0, 1.0);
			break;
		}
		case Sinus:{
			data = clamp(sin(drive * data), -1.0, 1.0);
			break;
		}
		case Cosinus:{
			data = clamp(cos(drive * data), -1.0, 1.0);
			break;
		}
		}
    }

 
        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessor);
};