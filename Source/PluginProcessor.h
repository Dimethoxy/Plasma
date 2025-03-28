#pragma once
#include "./LUFSMeter/Ebu128LoudnessMeter.h"
#include "PlasmaDistortionProcessor.h"
#include "Version.h"
#include "WaveformComponent.h"
#include <JuceHeader.h>
// Math
const float pi = 3.14159265358979323846;

// Enums
enum ChainPositions
{
  HighPass,
  HighPassResonance,
  Peak,
  DualPeakA,
  DualPeakB,
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
  Slope_96,
  None
};
enum AnalyserType
{
  Automatic,
  Waveform,
  Response,
  Shapercurve,
  Options
};

// Chain Settings
struct ChainSettings
{
  float drive{ 10.0f }, girth{ 0.0f }, bias{ 0.0f }, preGain{ 0.0f };
  float lateDrive{ 0.0f }, lateBias{ 0.0f }, lateGirth{ 0.0f }, gain{ 0.0f };
  float peakFreq{ 0 }, peakGain{ 0 }, peakQuality{ 1.0f }, peakStereo{ 0.0f };
  float dualPeakFreq{ 0 }, dualPeakGain{ 0 }, dualPeakQuality{ 1.0f },
    dualPeakWidth{ 300.0f };
  float highPassFreq{ 20.0f }, lowPassFreq{ 20.0f };
  float highPassResonanceQuality{ 1.0 }, highPassResonance{ 0.0 };
  float lowPassResonanceQuality{ 1.0 }, lowPassResonance{ 0.0 };
  float mix{ 100.0f };
  Slope highPassSlope{ Slope::Slope_12 }, lowPassSlope{ Slope::Slope_12 };
  AnalyserType analyserType{ AnalyserType::Response };
  Distortion driveType{ Distortion::Hardclip },
    lateDriveType{ Distortion::Hardclip };
};
ChainSettings
getChainSettings(juce::AudioProcessorValueTreeState& apvts);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Filters
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MonoChain
using Filter = juce::dsp::IIR::Filter<float>;
using PassFilter = juce::dsp::ProcessorChain<Filter,
                                             Filter,
                                             Filter,
                                             Filter,
                                             Filter,
                                             Filter,
                                             Filter,
                                             Filter>;
using MonoChain = juce::dsp::ProcessorChain<PassFilter, // HighPass
                                            Filter,     // HighPass Resonance
                                            Filter,     // Peak
                                            Filter,     // Dual A
                                            Filter,     // Dual B
                                            PassFilter, // LowPass
                                            Filter>;    // LowPass Resonance

// Coefficients
using Coefficients = Filter::CoefficientsPtr;
void
updateCoefficients(Coefficients& old, const Coefficients& replacements);

Coefficients
makePeakFilter(const ChainSettings& chainSettings,
               double sampleRate,
               float offset);
Coefficients
makeDualPeakFilter(const ChainSettings& chainSettings,
                   double sampleRate,
                   float offset);
Coefficients
makeHighPassResonance(const ChainSettings& chainSettings, double sampleRate);
Coefficients
makeLowPassResonance(const ChainSettings& chainSettings, double sampleRate);

template<int Index, typename ChainType, typename CoefficientType>
void
update(ChainType& chain, const CoefficientType& coefficients)
{
  updateCoefficients(chain.template get<Index>().coefficients,
                     coefficients[Index]);
  chain.template setBypassed<Index>(false);
}
template<typename ChainType, typename CoefficientType>
void
updatePassFilter(ChainType& filter,
                 const CoefficientType& filterCoefficients,
                 const Slope& filterSlope)
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
    case None: {
      break;
    }
  }
}

inline auto
makeHighPassFilter(const ChainSettings& chainSettings, double sampleRate)
{
  return juce::dsp::FilterDesign<float>::
    designIIRHighpassHighOrderButterworthMethod(
      chainSettings.highPassFreq,
      sampleRate,
      2 * (chainSettings.highPassSlope + 1));
}
inline auto
makeLowPassFilter(const ChainSettings& chainSettings, double sampleRate)
{
  return juce::dsp::FilterDesign<float>::
    designIIRLowpassHighOrderButterworthMethod(
      chainSettings.lowPassFreq,
      sampleRate,
      2 * (chainSettings.lowPassSlope + 1));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AudioProcessor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PlasmaAudioProcessor : public juce::AudioProcessor
{
public:
  PlasmaAudioProcessor();
  ~PlasmaAudioProcessor() override;
  void prepareToPlay(double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
  bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif
  void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
  juce::AudioProcessorEditor* createEditor() override;
  bool hasEditor() const override;
  const juce::String getName() const override;
  bool acceptsMidi() const override;
  bool producesMidi() const override;
  bool isMidiEffect() const override;
  double getTailLengthSeconds() const override;
  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram(int index) override;
  const juce::String getProgramName(int index) override;
  void changeProgramName(int index, const juce::String& newName) override;
  void getStateInformation(juce::MemoryBlock& destData) override;
  void setStateInformation(const void* data, int sizeInBytes) override;

  //==============================================================================

  static juce::AudioProcessorValueTreeState::ParameterLayout
  createParameterLayout();
  juce::AudioProcessorValueTreeState apvts{ *this,
                                            nullptr,
                                            "Parameters",
                                            createParameterLayout() };

  WaveformComponent waveformComponent;
  VersionManager versionManager;

private:
  // Clean Buffer
  AudioSampleBuffer cleanBuffer;

  // LoudnessMeter
  float rmsLevelLeftIn{ 0.0f }, rmsLevelRight{ 0.0f };
  float rmsLevelLeftOut{ 0.0f }, rmsLevelRightOut{ 0.0f };
  float peakLevelLeftIn{ 0.0f }, peakLevelRightIn{ 0.0f };
  float peakLevelLeftOut{ 0.0f }, peakLevelRightOut{ 0.0f };
  Ebu128LoudnessMeter loudnessMeterIn;
  Ebu128LoudnessMeter loudnessMeterOut;
  float momentaryLoudnessIn{ 0.0f }, momentaryLoudnessOut{ 0.0f };
  float integratedLoudnessIn{ 0.0f }, integratedLoudnessOut{ 0.0f };

  // Filters
  MonoChain leftChain, rightChain;
  void updatePeakFilter(const ChainSettings& chainSettings);
  void updateDualPeakFilter(const ChainSettings& chainSettings);
  void updateHighPassResonance(const ChainSettings& chainSettings);
  void updateLowPassResonance(const ChainSettings& chainSettings);
  void updateHighPass(const ChainSettings& chainSettings);
  void updateLowPass(const ChainSettings& chainSettings);
  void updateFilters();

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlasmaAudioProcessor);
};
