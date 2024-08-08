#include "PluginProcessor.h"
#include "PluginEditor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JUCE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PlasmaAudioProcessor::PlasmaAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
  : AudioProcessor(
      BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    )
#endif
{
}

PlasmaAudioProcessor::~PlasmaAudioProcessor() {}

//==============================================================================
const juce::String
PlasmaAudioProcessor::getName() const
{
  return JucePlugin_Name;
}

bool
PlasmaAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool
PlasmaAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool
PlasmaAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double
PlasmaAudioProcessor::getTailLengthSeconds() const
{
  return 0.0;
}

int
PlasmaAudioProcessor::getNumPrograms()
{
  return 1; // NB: some hosts don't cope very well if you tell them there are 0
            // programs,
  // so this should be at least 1, even if you're not really implementing
  // programs.
}

int
PlasmaAudioProcessor::getCurrentProgram()
{
  return 0;
}

void
PlasmaAudioProcessor::setCurrentProgram(int index)
{
}

const juce::String
PlasmaAudioProcessor::getProgramName(int index)
{
  return {};
}

void
PlasmaAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}

//==============================================================================

void
PlasmaAudioProcessor::releaseResources()
{
  // When playback stops, you can use this as an opportunity to free up any
  // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool
PlasmaAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
  juce::ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  // Some plugin hosts, such as certain GarageBand versions, will only
  // load plugins that support stereo bus layouts.
  if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
    return false;

    // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif

  return true;
#endif
}
#endif

//==============================================================================
bool
PlasmaAudioProcessor::hasEditor() const
{
  return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor*
PlasmaAudioProcessor::createEditor()
{
  // return new juce::GenericAudioProcessorEditor(*this);
  return new PlasmaAudioProcessorEditor(*this);
}

//==============================================================================
void
PlasmaAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
  juce::MemoryOutputStream mos(destData, true);
  apvts.state.writeToStream(mos);
}

void
PlasmaAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
  auto tree = juce::ValueTree::readFromData(data, sizeInBytes);
  if (tree.isValid()) {
    apvts.replaceState(tree);
    updateFilters();
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepare
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

juce::AudioProcessor* JUCE_CALLTYPE
createPluginFilter()
{
  return new PlasmaAudioProcessor();
}

void
PlasmaAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
  juce::dsp::ProcessSpec spec;
  spec.maximumBlockSize = samplesPerBlock;
  spec.numChannels = 1;
  spec.sampleRate = sampleRate;

  leftChain.prepare(spec);
  rightChain.prepare(spec);

  // Filter
  updateFilters();

  // Allocate Clean Buffer
  cleanBuffer.setSize(getNumInputChannels(), samplesPerBlock);

  // Waveform
  waveformComponent.clear();

  // Trigger VersionManager
  versionManager.triggerAsyncUpdate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ProcessBlock
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
PlasmaAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                   juce::MidiBuffer& midiMessages)
{
  juce::ScopedNoDenormals noDenormals;
  auto totalNumInputChannels = getTotalNumInputChannels();
  auto totalNumOutputChannels = getTotalNumOutputChannels();

  for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    buffer.clear(i, 0, buffer.getNumSamples());
  float gain, preGain;
  // Get Settings
  auto chainSettings = getChainSettings(apvts);
  if (chainSettings.preGain > -32.f) {
    preGain = Decibels::decibelsToGain(chainSettings.preGain);
  } else {
    preGain = 0.0f;
  }
  if (chainSettings.gain > -32.f) {
    gain = Decibels::decibelsToGain(chainSettings.gain);
  } else {
    gain = 0.f;
  }
  float mixWet = chainSettings.mix / 100;
  float mixDry = (100.0 - chainSettings.mix) / 100;
  // bool killswitch = false;

  // Clean
  AudioSampleBuffer tmpBuffer(cleanBuffer.getArrayOfWritePointers(),
                              buffer.getNumChannels(),
                              buffer.getNumSamples());
  for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    tmpBuffer.copyFrom(ch, 0, buffer, ch, 0, buffer.getNumSamples());

  // Clean RMS
  auto leftRms = buffer.getRMSLevel(0, 0, buffer.getNumSamples());
  auto rightRms = buffer.getRMSLevel(1, 0, buffer.getNumSamples());

  // Distortion Unit
  std::vector<int> randoms(buffer.getNumSamples());
  for (int& n : randoms)
    n = rand();
  for (int channel = 0; channel < 2; ++channel) {
    auto* channelData = buffer.getWritePointer(channel);

    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
      if (channelData[sample] != 0.0) {
        // Pre Gain
        channelData[sample] =
          DistortionProcessor::clamp(channelData[sample] * preGain, -1.0, 1.0);

        // Girth
        if (chainSettings.girth >= 0.0f)
          channelData[sample] =
            channelData[sample] *
            ((((float)(rand() % 100)) / 100 * chainSettings.girth) + 1);
        else {
          channelData[sample] =
            channelData[sample] *
            ((((float)(randoms[sample] % 100)) / 100 * -chainSettings.girth) +
             1);
        }

        // Drive
        DistortionProcessor::distort(
          channelData[sample], chainSettings.drive, chainSettings.driveType);

        // Bias
        // channelData[sample] = clamp(channelData[sample] +
        // chainSettings.bias, -1.0, 1.0);
        if (channelData[sample] > 0) {
          channelData[sample] += channelData[sample] * chainSettings.bias;
        } else if (channelData[sample] < 0) {
          channelData[sample] -= channelData[sample] * chainSettings.bias;
        }
      }
    }
  }

  // DSP
  juce::dsp::AudioBlock<float> block(buffer);

  // Filter
  updateFilters();
  auto threshold = 0.0f;
  if (leftRms != threshold) {
    auto leftBlock = block.getSingleChannelBlock(0);
    juce::dsp::ProcessContextReplacing<float> leftContext(leftBlock);
    leftChain.process(leftContext);
  } else {
    auto data = buffer.getWritePointer(0);
    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
      data[sample] = 0.0f;
    }
  }

  if (rightRms != threshold) {
    auto rightBlock = block.getSingleChannelBlock(1);
    juce::dsp::ProcessContextReplacing<float> rightContext(rightBlock);
    rightChain.process(rightContext);
  } else {
    auto data = buffer.getWritePointer(1);
    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
      data[sample] = 0.0f;
    }
  }

  // Late Stage
  for (int& n : randoms)
    n = rand();
  for (int channel = 0; channel < totalNumInputChannels; ++channel) {
    auto* channelData = buffer.getWritePointer(channel);
    auto* cleanData = tmpBuffer.getWritePointer(channel);
    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
      if (channelData[sample] != 0.0) {
        // Reduce Loudness
        channelData[sample] =
          DistortionProcessor::clamp(channelData[sample], -1, 1);

        // Girth
        if (chainSettings.lateGirth >= 0.0f)
          channelData[sample] =
            channelData[sample] *
            ((((float)(rand() % 100)) / 100 * chainSettings.lateGirth) + 1);
        else {
          channelData[sample] =
            channelData[sample] * ((((float)(randoms[sample] % 100)) / 100 *
                                    -chainSettings.lateGirth) +
                                   1);
        }

        // Drive
        DistortionProcessor::distort(channelData[sample],
                                     chainSettings.lateDrive,
                                     chainSettings.lateDriveType);

        // Bias
        if (channelData[sample] > 0) {
          channelData[sample] += channelData[sample] * chainSettings.lateBias;
        } else if (channelData[sample] < 0) {
          channelData[sample] -= channelData[sample] * chainSettings.lateBias;
        }
        // Mix
        channelData[sample] =
          cleanData[sample] * mixDry + channelData[sample] * mixWet;

        // Reduce Loudness for Waveform Analyser
        channelData[sample] =
          0.5 * DistortionProcessor::clamp(channelData[sample], -1, 1);
      }
    }
  }

  // Update Waveform Analyser
  waveformComponent.pushBuffer(buffer);
  for (int channel = 0; channel < totalNumInputChannels; ++channel) {
    auto* channelData = buffer.getWritePointer(channel);
    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
      // Gain
      channelData[sample] = channelData[sample] * gain * 2;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AudioProcessorValueTreeState
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

juce::AudioProcessorValueTreeState::ParameterLayout
PlasmaAudioProcessor::createParameterLayout()
{
  juce::AudioProcessorValueTreeState::ParameterLayout layout;

  // Pre Gain
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Pre Gain",
    "Pre Gain",
    juce::NormalisableRange<float>(-32.0f, 32.0f, 0.2f, 1.0f),
    0.0f));
  // Drive
  juce::StringArray distortionArray;
  distortionArray.add("Hard Clip");
  distortionArray.add("Soft Clip");
  distortionArray.add("Saturate");
  distortionArray.add("Atan");
  distortionArray.add("Crunch");
  distortionArray.add("Bitcrush");
  distortionArray.add("Extreme");
  distortionArray.add("Scream");
  distortionArray.add("Sine");
  distortionArray.add("Cosine");
  distortionArray.add("Harmonic");
  distortionArray.add("Weird");
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Drive",
    "Drive",
    juce::NormalisableRange<float>(1.0f, 11.0f, 0.01f, 0.5f),
    0.0f));
  layout.add(std::make_unique<juce::AudioParameterChoice>(
    "Distortion Type", "Distortion Type", distortionArray, 0));
  // Girth
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Girth",
    "Girth",
    juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f, 1.0f),
    0.0f));
  // Bias
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Bias",
    "Bias",
    juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f, 1.0f),
    0.0f));
  // Peak
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Peak Stereo",
    "Peak Stereo",
    juce::NormalisableRange<float>(0.0f, 100.0f, 0.1f, 1.0f),
    0.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Peak Freq",
    "Peak Freq",
    juce::NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 0.18),
    450.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Peak Gain",
    "Peak Gain",
    juce::NormalisableRange<float>(-48.0f, 48.0f, 0.1f, 1.0f),
    0.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Peak Q",
    "Peak Q",
    juce::NormalisableRange<float>(0.1f, 5.0f, 0.01f, 1.0f),
    1.0f));
  // Dual Peak
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Dual Peak Width",
    "Dual Peak Width",
    juce::NormalisableRange<float>(0.0f, 1000.0f, 0.1f, 1.0f),
    300.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Dual Peak Freq",
    "Dual Peak Freq",
    juce::NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 0.18),
    450.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Dual Peak Gain",
    "Dual Peak Gain",
    juce::NormalisableRange<float>(-48.0f, 48.0f, 0.1f, 1.0f),
    0.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Dual Peak Q",
    "Dual Peak Q",
    juce::NormalisableRange<float>(0.1f, 5.0f, 0.01f, 1.0f),
    1.0f));
  // Slope Array
  juce::StringArray slopeArray;
  for (int i = 0; i < 8; i++) {
    juce::String str;
    str << (12 + i * 12);
    str << " db/Oct";
    slopeArray.add(str);
  }
  slopeArray.add("Bypass");
  // Highpass
  layout.add(std::make_unique<juce::AudioParameterChoice>(
    "Highpass Slope", "Highpass Slope", slopeArray, 0));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Highpass Freq",
    "Highpass Freq",
    juce::NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 0.18f),
    20.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Highpass Resonance",
    "Highpass Resonance",
    juce::NormalisableRange<float>(0.0f, 64.0f, 0.1f, 1.0f),
    0.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Highpass Resonance Q",
    "Highpass Resonance Q",
    juce::NormalisableRange<float>(0.1f, 5.0f, 0.01f, 1.0f),
    1.0f));
  // Lowpass
  layout.add(std::make_unique<juce::AudioParameterChoice>(
    "Lowpass Slope", "Lowpass Slope", slopeArray, 0));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Lowpass Freq",
    "Lowpass Freq",
    juce::NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 0.18f),
    20000.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Lowpass Resonance",
    "Lowpass Resonance",
    juce::NormalisableRange<float>(0.0f, 64.0f, 0.1f, 1.0f),
    0.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Lowpass Resonance Q",
    "Lowpass Resonance Q",
    juce::NormalisableRange<float>(0.1f, 5.0f, 0.01f, 1.0f),
    1.0f));
  // Late Drive
  layout.add(std::make_unique<juce::AudioParameterChoice>(
    "Late Distortion Type", "Late Distortion Type", distortionArray, 0));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Late Drive",
    "Late Drive",
    juce::NormalisableRange<float>(1.0f, 11.0f, 0.01f, 0.5f),
    0.0f));
  // Late Girth
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Late Girth",
    "Late Girth",
    juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f, 1.0f),
    0.0f));
  // Late Bias
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Late Bias",
    "Late Bias",
    juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f, 1.0f),
    0.0f));
  // Gain
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Gain",
    "Gain",
    juce::NormalisableRange<float>(-32.0f, 32.0f, 0.2f, 1.0f),
    0.0f));
  // Mix
  layout.add(std::make_unique<juce::AudioParameterFloat>(
    "Mix",
    "Mix",
    juce::NormalisableRange<float>(0.0f, 100.0f, 0.01f, 1.0f),
    100.0f));
  // Analyser
  juce::StringArray analyserArray;
  for (int i = 0; i < 5; i++) {
    juce::String str;
    str << "Type ";
    str << i;
    analyserArray.add(str);
  }
  layout.add(std::make_unique<juce::AudioParameterChoice>(
    "Analyser Type", "Analyser Type", analyserArray, 0));
  return layout;
}

ChainSettings
getChainSettings(juce::AudioProcessorValueTreeState& apvts)
{
  ChainSettings settings;
  // Distortion Unit
  settings.preGain = apvts.getRawParameterValue("Pre Gain")->load();
  settings.drive = apvts.getRawParameterValue("Drive")->load();
  settings.girth = apvts.getRawParameterValue("Girth")->load();
  settings.bias = apvts.getRawParameterValue("Bias")->load();
  settings.driveType = static_cast<Distortion>(
    apvts.getRawParameterValue("Distortion Type")->load());
  // Peak
  settings.peakStereo = apvts.getRawParameterValue("Peak Stereo")->load();
  settings.peakFreq = apvts.getRawParameterValue("Peak Freq")->load();
  settings.peakGain = apvts.getRawParameterValue("Peak Gain")->load();
  settings.peakQuality = apvts.getRawParameterValue("Peak Q")->load();
  // Dual Peak
  settings.dualPeakWidth =
    apvts.getRawParameterValue("Dual Peak Width")->load();
  settings.dualPeakFreq = apvts.getRawParameterValue("Dual Peak Freq")->load();
  settings.dualPeakGain = apvts.getRawParameterValue("Dual Peak Gain")->load();
  settings.dualPeakQuality = apvts.getRawParameterValue("Dual Peak Q")->load();
  // Highpass
  settings.highPassFreq = apvts.getRawParameterValue("Highpass Freq")->load();
  settings.highPassResonance =
    apvts.getRawParameterValue("Highpass Resonance")->load();
  settings.highPassResonanceQuality =
    apvts.getRawParameterValue("Highpass Resonance Q")->load();
  settings.highPassSlope =
    static_cast<Slope>(apvts.getRawParameterValue("Highpass Slope")->load());
  // Lowpass
  settings.lowPassFreq = apvts.getRawParameterValue("Lowpass Freq")->load();
  settings.lowPassResonance =
    apvts.getRawParameterValue("Lowpass Resonance")->load();
  settings.lowPassResonanceQuality =
    apvts.getRawParameterValue("Lowpass Resonance Q")->load();
  settings.lowPassSlope =
    static_cast<Slope>(apvts.getRawParameterValue("Lowpass Slope")->load());

  // Late
  settings.lateDriveType = static_cast<Distortion>(
    apvts.getRawParameterValue("Late Distortion Type")->load());
  settings.lateDrive = apvts.getRawParameterValue("Late Drive")->load();
  settings.lateGirth = apvts.getRawParameterValue("Late Girth")->load();
  settings.lateBias = apvts.getRawParameterValue("Late Bias")->load();
  settings.gain = apvts.getRawParameterValue("Gain")->load();
  // Mix
  settings.mix = apvts.getRawParameterValue("Mix")->load();
  // Analyser
  settings.analyserType = static_cast<AnalyserType>(
    apvts.getRawParameterValue("Analyser Type")->load());
  return settings;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Filters
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
PlasmaAudioProcessor::updateFilters()
{
  auto chainSettings = getChainSettings(apvts);
  updateHighPass(chainSettings);
  updateHighPassResonance(chainSettings);
  updatePeakFilter(chainSettings);
  updateDualPeakFilter(chainSettings);
  updateLowPass(chainSettings);
  updateLowPassResonance(chainSettings);
}
Coefficients
makePeakFilter(const ChainSettings& chainSettings,
               double sampleRate,
               float offset)
{
  return juce::dsp::IIR::Coefficients<float>::makePeakFilter(
    sampleRate,
    DistortionProcessor::clamp(chainSettings.peakFreq + offset, 20, 20000),
    chainSettings.peakQuality,
    juce::Decibels::decibelsToGain(chainSettings.peakGain));
}
Coefficients
makeDualPeakFilter(const ChainSettings& chainSettings,
                   double sampleRate,
                   float offset)
{
  return juce::dsp::IIR::Coefficients<float>::makePeakFilter(
    sampleRate,
    DistortionProcessor::clamp(chainSettings.dualPeakFreq + offset, 20, 20000),
    chainSettings.dualPeakQuality,
    juce::Decibels::decibelsToGain(chainSettings.dualPeakGain));
}
Coefficients
makeLowPassResonance(const ChainSettings& chainSettings, double sampleRate)
{
  auto gain = (chainSettings.lowPassSlope == Slope::None)
                ? 0.0f
                : chainSettings.lowPassResonance;
  return juce::dsp::IIR::Coefficients<float>::makePeakFilter(
    sampleRate,
    chainSettings.lowPassFreq,
    chainSettings.lowPassResonanceQuality,
    juce::Decibels::decibelsToGain(gain));
}
Coefficients
makeHighPassResonance(const ChainSettings& chainSettings, double sampleRate)
{
  auto gain = (chainSettings.highPassSlope == Slope::None)
                ? 0.0f
                : chainSettings.highPassResonance;
  return juce::dsp::IIR::Coefficients<float>::makePeakFilter(
    sampleRate,
    chainSettings.highPassFreq,
    chainSettings.highPassResonanceQuality,
    juce::Decibels::decibelsToGain(gain));
}
void
PlasmaAudioProcessor::updatePeakFilter(const ChainSettings& chainSettings)
{
  auto peakCoefficientsL =
    makePeakFilter(chainSettings, getSampleRate(), chainSettings.peakStereo);
  auto peakCoefficientsR =
    makePeakFilter(chainSettings, getSampleRate(), -chainSettings.peakStereo);
  updateCoefficients(leftChain.get<ChainPositions::Peak>().coefficients,
                     *peakCoefficientsL);
  updateCoefficients(rightChain.get<ChainPositions::Peak>().coefficients,
                     *peakCoefficientsR);
}

void
PlasmaAudioProcessor::updateDualPeakFilter(const ChainSettings& chainSettings)
{
  auto dualPeakWidth = chainSettings.dualPeakWidth;
  auto dualPeakFreq = chainSettings.dualPeakFreq;

  auto logFreq = juce::mapFromLog10(dualPeakFreq, 20.0f, 20000.0f);
  auto logWidth = juce::mapFromLog10(dualPeakWidth / 100.0f, 20.0f, 20000.0f);

  auto logFreqA = logFreq - 0.1f;
  auto logFreqB = logFreq + 0.1f;

  auto freqA = juce::mapToLog10(logFreqA, 20.0f, 20000.0f);
  auto freqB = juce::mapToLog10(logFreqB, 20.0f, 20000.0f);

  auto offsetA = freqA - dualPeakFreq;
  auto offsetB = freqB - dualPeakFreq;

  auto peakCoefficientsA =
    makeDualPeakFilter(chainSettings, getSampleRate(), offsetA);
  auto peakCoefficientsB =
    makeDualPeakFilter(chainSettings, getSampleRate(), offsetB);

  updateCoefficients(leftChain.get<ChainPositions::DualPeakA>().coefficients,
                     *peakCoefficientsA);
  updateCoefficients(rightChain.get<ChainPositions::DualPeakA>().coefficients,
                     *peakCoefficientsA);

  updateCoefficients(leftChain.get<ChainPositions::DualPeakB>().coefficients,
                     *peakCoefficientsB);
  updateCoefficients(rightChain.get<ChainPositions::DualPeakB>().coefficients,
                     *peakCoefficientsB);
}

void
PlasmaAudioProcessor::updateHighPassResonance(
  const ChainSettings& chainSettings)
{
  auto gain = (chainSettings.highPassSlope == Slope::None)
                ? 0.0f
                : chainSettings.highPassResonance;
  auto peakCoefficients = juce::dsp::IIR::Coefficients<float>::makePeakFilter(
    getSampleRate(),
    chainSettings.highPassFreq,
    chainSettings.highPassResonanceQuality,
    juce::Decibels::decibelsToGain(gain));

  updateCoefficients(
    leftChain.get<ChainPositions::HighPassResonance>().coefficients,
    *peakCoefficients);
  updateCoefficients(
    rightChain.get<ChainPositions::HighPassResonance>().coefficients,
    *peakCoefficients);
}

void
PlasmaAudioProcessor::updateLowPassResonance(const ChainSettings& chainSettings)
{
  auto gain = (chainSettings.lowPassSlope == Slope::None)
                ? 0.0f
                : chainSettings.lowPassResonance;
  auto peakCoefficients = juce::dsp::IIR::Coefficients<float>::makePeakFilter(
    getSampleRate(),
    chainSettings.lowPassFreq,
    chainSettings.lowPassResonanceQuality,
    juce::Decibels::decibelsToGain(gain));

  updateCoefficients(
    leftChain.get<ChainPositions::LowPassResonance>().coefficients,
    *peakCoefficients);
  updateCoefficients(
    rightChain.get<ChainPositions::LowPassResonance>().coefficients,
    *peakCoefficients);
}

void
PlasmaAudioProcessor::updateHighPass(const ChainSettings& chainSettings)
{
  auto highPassCoefficients =
    makeHighPassFilter(chainSettings, getSampleRate());

  auto& leftHighPass = leftChain.get<ChainPositions::HighPass>();
  updatePassFilter(
    leftHighPass, highPassCoefficients, chainSettings.highPassSlope);

  auto& rightHighPass = rightChain.get<ChainPositions::HighPass>();
  updatePassFilter(
    rightHighPass, highPassCoefficients, chainSettings.highPassSlope);
}

void
PlasmaAudioProcessor::updateLowPass(const ChainSettings& chainSettings)
{
  auto lowPassCoefficients = makeLowPassFilter(chainSettings, getSampleRate());

  auto& leftLowPass = leftChain.get<ChainPositions::LowPass>();
  updatePassFilter(
    leftLowPass, lowPassCoefficients, chainSettings.lowPassSlope);

  auto& rightLowPass = rightChain.get<ChainPositions::LowPass>();
  updatePassFilter(
    rightLowPass, lowPassCoefficients, chainSettings.lowPassSlope);
}

void
updateCoefficients(Coefficients& old, const Coefficients& replacements)
{
  *old = *replacements;
}
