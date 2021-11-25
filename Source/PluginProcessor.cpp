#include "PluginProcessor.h"
#include "PluginEditor.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//JUCE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PlasmaAudioProcessor::PlasmaAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

PlasmaAudioProcessor::~PlasmaAudioProcessor()
{
}

//==============================================================================
const juce::String PlasmaAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PlasmaAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PlasmaAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PlasmaAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PlasmaAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PlasmaAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PlasmaAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PlasmaAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String PlasmaAudioProcessor::getProgramName (int index)
{
    return {};
}

void PlasmaAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================

void PlasmaAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PlasmaAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

//==============================================================================
bool PlasmaAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* PlasmaAudioProcessor::createEditor()
{
	//return new juce::GenericAudioProcessorEditor(*this);
	return new PlasmaAudioProcessorEditor (*this);
}

//==============================================================================
void PlasmaAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
	juce::MemoryOutputStream mos(destData, true);
	apvts.state.writeToStream(mos);
}

void PlasmaAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	auto tree = juce::ValueTree::readFromData(data, sizeInBytes);
	if (tree.isValid())
	{
		apvts.replaceState(tree);
		updateFilters();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Prepare
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new PlasmaAudioProcessor();
}

float PlasmaAudioProcessor::clamp(float d, float min, float max) {
	const float t = d < min ? min : d;
	return t > max ? max : t;
}
void PlasmaAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	juce::dsp::ProcessSpec spec;
	spec.maximumBlockSize = samplesPerBlock;
	spec.numChannels = 1;
	spec.sampleRate = sampleRate;

	leftChain.prepare(spec);
	rightChain.prepare(spec);

	auto chainSettings = getChainSettings(apvts);

	//Filter
	updateFilters();	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ProcessBlock
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlasmaAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    //Get Settings
    auto chainSettings = getChainSettings(apvts);
    float gain = Decibels::decibelsToGain(chainSettings.gain);
    float preGain = Decibels::decibelsToGain(chainSettings.preGain);

    //Distortion Unit
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); sample++)
        {
			//Pre Gain
			channelData[sample] = clamp(channelData[sample] * preGain, -1.0, 1.0);

            //Girth
            channelData[sample] = channelData[sample] *
                ((((float)(rand() % 100)) / 100 * chainSettings.girth) + 1);

            //Drive          
            distort(channelData[sample], chainSettings.drive, chainSettings.driveType);

            //Bias         
            channelData[sample] = clamp(channelData[sample] + chainSettings.bias, -1.0, 1.0);
        }
    }

    //Filter
    updateFilters();

    //DSP
    juce::dsp::AudioBlock<float> block(buffer);

    auto leftBlock = block.getSingleChannelBlock(0);
    auto rightBlock = block.getSingleChannelBlock(1);

    juce::dsp::ProcessContextReplacing<float> leftContext(leftBlock);
    juce::dsp::ProcessContextReplacing<float> rightContext(rightBlock);

    leftChain.process(leftContext);
    rightChain.process(rightContext);

    //Late Stage
    
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		auto* channelData = buffer.getWritePointer(channel);
		for (int sample = 0; sample < buffer.getNumSamples(); sample++)
		{    
            //Drive 
            distort(channelData[sample], chainSettings.lateDrive, chainSettings.lateDriveType);

            //Gain
			channelData[sample] = clamp(channelData[sample] * gain, -1.0, 1.0);
		}

	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AudioProcessorValueTreeState
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

juce::AudioProcessorValueTreeState::ParameterLayout PlasmaAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
	//Pre Gain
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Pre Gain", "Pre Gain",
			juce::NormalisableRange<float>(-48.0f, 48.0f, 0.01f, 0.5f), 0.0f));
    //Drive
    juce::StringArray distortionArray;
	distortionArray.add("Hardclip");
	distortionArray.add("Softclip");
	distortionArray.add("Overdrive");
	distortionArray.add("Bitcrush");
	distortionArray.add("Atan");
	distortionArray.add("Sinus");
	distortionArray.add("Cosinus");
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Drive", "Drive",
			juce::NormalisableRange<float>(1.0f, 10.0f, 0.01f, 1.0f), 10.0f));
	layout.add(std::make_unique<juce::AudioParameterChoice>
		("Distortion Type", "Distortion Type", distortionArray, 2));
    //Girth
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Girth", "Girth",
			juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f, 1.0f), 0.5f));
	//Bias
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Bias", "Bias",
			juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f, 1.0f), 0.0f));
    //Peak
    layout.add(std::make_unique<juce::AudioParameterFloat>
        ("Peak Freq", "Peak Freq",
        juce::NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 0.5f), 450.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>
        ("Peak Gain", "Peak Gain",
            juce::NormalisableRange<float>(-48.0f, 48.0f, 0.1f, 1.0f), 16.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>
        ("Peak Q", "Peak Q",
            juce::NormalisableRange<float>(0.1f, 5.0f, 0.01f, 0.5f), 1.0f));
    //Slope Array
    juce::StringArray slopeArray;
    for (int i = 0; i < 8; i++) {
        juce::String str;
        str << (12 + i * 12);
        str << " db/Oct";
        slopeArray.add(str);
    }
	//Highpass
	layout.add(std::make_unique<juce::AudioParameterChoice>
		("Highpass Slope", "Highpass Slope", slopeArray, 0));
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Highpass Freq", "Highpass Freq",
			juce::NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 0.5f), 70.0f));
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Highpass Resonance", "Highpass Resonance",
			juce::NormalisableRange<float>(0.0f, 64.0f, 0.1f, 0.5f), 0.0f));
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Highpass Resonance Q", "Highpass Resonance Q",
			juce::NormalisableRange<float>(0.1f, 5.0f, 0.01f, 0.5f), 1.0f));
    //Lowpass
	layout.add(std::make_unique<juce::AudioParameterChoice>
		("Lowpass Slope", "Lowpass Slope", slopeArray, 0));
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Lowpass Freq", "Lowpass Freq",
			juce::NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 0.5f), 8000.0f));
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Lowpass Resonance", "Lowpass Resonance",
			juce::NormalisableRange<float>(0.0f, 64.0f, 0.1f, 0.5f), 0.0f));
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Lowpass Resonance Q", "Lowpass Resonance Q",
			juce::NormalisableRange<float>(0.1f, 5.0f, 0.01f, 0.5f), 1.0f));
	//Late Drive
	layout.add(std::make_unique<juce::AudioParameterChoice>
		("Late Distortion Type", "Late Distortion Type", distortionArray, 0));
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Late Drive", "Late Drive",
			juce::NormalisableRange<float>(1.0f, 10.0f, 0.01f, 1.0f), 10.0f));
	//Late Girth
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Late Girth", "Late Girth",
			juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f, 1.0f), 0.5f));
	//Late Bias
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Late Bias", "Late Bias",
			juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f, 1.0f), 0.0f));
	//Gain
	layout.add(std::make_unique<juce::AudioParameterFloat>
		("Gain", "Gain",
			juce::NormalisableRange<float>(-48.0f, 48.0f, 0.01f, 0.5f), -12.0f));

    return layout;
}

ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts)
{
    ChainSettings settings;
    //Distortion Unit
    settings.preGain = apvts.getRawParameterValue("Pre Gain")->load();
    settings.drive = apvts.getRawParameterValue("Drive")->load();
    settings.girth = apvts.getRawParameterValue("Girth")->load();
    settings.bias = apvts.getRawParameterValue("Bias")->load();
    settings.driveType = static_cast<Distortion>(apvts.getRawParameterValue("Distortion Type")->load());
    //Peak
    settings.peakFreq = apvts.getRawParameterValue("Peak Freq")->load();
    settings.peakGain = apvts.getRawParameterValue("Peak Gain")->load();
    settings.peakQuality = apvts.getRawParameterValue("Peak Q")->load();
    //Highpass
    settings.highPassFreq = apvts.getRawParameterValue("Highpass Freq")->load();
    settings.highPassResonance = apvts.getRawParameterValue("Highpass Resonance")->load();
    settings.highPassResonanceQuality = apvts.getRawParameterValue("Highpass Resonance Q")->load();
    settings.highPassSlope = static_cast<Slope>(apvts.getRawParameterValue("Highpass Slope")->load());
	//Lowpass
	settings.lowPassFreq = apvts.getRawParameterValue("Lowpass Freq")->load();
	settings.lowPassResonance = apvts.getRawParameterValue("Lowpass Resonance")->load();
	settings.lowPassResonanceQuality = apvts.getRawParameterValue("Lowpass Resonance Q")->load();
	settings.lowPassSlope = static_cast<Slope>(apvts.getRawParameterValue("Lowpass Slope")->load());
    //Late
    settings.lateDriveType = static_cast<Distortion>(apvts.getRawParameterValue("Late Distortion Type")->load());
    settings.lateDrive = apvts.getRawParameterValue("Late Drive")->load();
    settings.gain = apvts.getRawParameterValue("Gain")->load();

    return settings;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Filters
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlasmaAudioProcessor::updateFilters()
{
    auto chainSettings = getChainSettings(apvts);
	updateHighPass(chainSettings);
    updateHighPassResonance(chainSettings);
    updatePeakFilter(chainSettings);
	updateLowPass(chainSettings);
    updateLowPassResonance(chainSettings);
}

Coefficients makePeakFilter(const ChainSettings& chainSettings, double sampleRate)
{
	return juce::dsp::IIR::Coefficients<float>::makePeakFilter(sampleRate,
		chainSettings.peakFreq,
		chainSettings.peakQuality,
		juce::Decibels::decibelsToGain(chainSettings.peakGain));
}

void PlasmaAudioProcessor::updatePeakFilter(const ChainSettings& chainSettings)
{
	auto peakCoefficients = makePeakFilter(chainSettings, getSampleRate());
    updateCoefficients(leftChain.get<ChainPositions::Peak>().coefficients, *peakCoefficients);
    updateCoefficients(rightChain.get<ChainPositions::Peak>().coefficients, *peakCoefficients);
}

void PlasmaAudioProcessor::updateHighPassResonance(const ChainSettings& chainSettings)
{
	auto peakCoefficients = juce::dsp::IIR::Coefficients<float>::makePeakFilter(getSampleRate(),
		chainSettings.highPassFreq,
		chainSettings.highPassResonanceQuality,
		juce::Decibels::decibelsToGain(chainSettings.highPassResonance));

	updateCoefficients(leftChain.get<ChainPositions::HighPassResonance>().coefficients, *peakCoefficients);
	updateCoefficients(rightChain.get<ChainPositions::HighPassResonance>().coefficients, *peakCoefficients);
}

void PlasmaAudioProcessor::updateLowPassResonance(const ChainSettings& chainSettings)
{
	auto peakCoefficients = juce::dsp::IIR::Coefficients<float>::makePeakFilter(getSampleRate(),
		chainSettings.lowPassFreq,
		chainSettings.lowPassResonanceQuality,
		juce::Decibels::decibelsToGain(chainSettings.lowPassResonance));

	updateCoefficients(leftChain.get<ChainPositions::LowPassResonance>().coefficients, *peakCoefficients);
	updateCoefficients(rightChain.get<ChainPositions::LowPassResonance>().coefficients, *peakCoefficients);
}

void PlasmaAudioProcessor::updateHighPass(const ChainSettings& chainSettings)
{
	auto highPassCoefficients = makeHighPassFilter(chainSettings, getSampleRate());

	auto& leftHighPass = leftChain.get<ChainPositions::HighPass>();
	updatePassFilter(leftHighPass, highPassCoefficients, chainSettings.highPassSlope);

	auto& rightHighPass = rightChain.get<ChainPositions::HighPass>();
	updatePassFilter(rightHighPass, highPassCoefficients, chainSettings.highPassSlope);
}

void PlasmaAudioProcessor::updateLowPass(const ChainSettings& chainSettings)
{
	auto lowPassCoefficients = makeLowPassFilter(chainSettings, getSampleRate());

	auto& leftLowPass = leftChain.get<ChainPositions::LowPass>();
	updatePassFilter(leftLowPass, lowPassCoefficients, chainSettings.lowPassSlope);

	auto& rightLowPass = rightChain.get<ChainPositions::LowPass>();
	updatePassFilter(rightLowPass, lowPassCoefficients, chainSettings.lowPassSlope);
}

void updateCoefficients(Coefficients& old, const Coefficients& replacements)
{
	*old = *replacements;
}