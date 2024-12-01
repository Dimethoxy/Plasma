#include <JuceHeader.h>

class BaseVisualiser
  : public Component
  , private Timer
{
public:
  /** Creates a visualiser with the given number of channels. */
  BaseVisualiser(int initialNumChannels);

  /** Destructor. */
  ~BaseVisualiser() override;

  /** Changes the number of channels that the visualiser stores. */
  void setNumChannels(int numChannels);

  /** Changes the number of samples that the visualiser keeps in its history.
      Note that this value refers to the number of averaged sample blocks, and
     each block is calculated as the peak of a number of incoming audio samples.
     To set the number of incoming samples per block, use setSamplesPerBlock().
   */
  void setBufferSize(int bufferSize);

  /** */
  void setSamplesPerBlock(int newNumInputSamplesPerBlock) noexcept;

  /** */
  int getSamplesPerBlock() const noexcept { return inputSamplesPerBlock; }

  /** Clears the contents of the buffers. */
  void clear();

  /** Pushes a buffer of channels data.
      The number of channels provided here is expected to match the number of
     channels that this BaseVisualiser has been told to use.
  */
  void pushBuffer(const AudioBuffer<float>& bufferToPush);

  /** Pushes a buffer of channels data.
      The number of channels provided here is expected to match the number of
     channels that this BaseVisualiser has been told to use.
  */
  void pushBuffer(const AudioSourceChannelInfo& bufferToPush);

  /** Pushes a buffer of channels data.
      The number of channels provided here is expected to match the number of
     channels that this BaseVisualiser has been told to use.
  */
  void pushBuffer(const float* const* channelData,
                  int numChannels,
                  int numSamples);

  /** Pushes a single sample (per channel).
      The number of channels provided here is expected to match the number of
     channels that this BaseVisualiser has been told to use.
  */
  void pushSample(const float* samplesForEachChannel, int numChannels);

  /** Sets the colours used to paint the */
  void setColours(Colour backgroundColour,
                  Colour waveformColour,
                  Colour foregroundColour) noexcept;

  /** Sets the frequency at which the component repaints itself. */
  void setRepaintRate(int frequencyInHz);

  /** Draws a channel of audio data in the given bounds.
      The default implementation just calls getChannelAsPath() and fits this
     into the given area. You may want to override this to draw things
     differently.
  */
  virtual void paintChannel(Graphics&,
                            Rectangle<float> bounds,
                            const Range<float>* levels,
                            int numLevels,
                            int nextSample);

  /** Creates a path which contains the waveform shape of a given set of range
     data. The path is normalised so that -1 and +1 are its upper and lower
     bounds, and it goes from 0 to numLevels on the X axis.
  */
  void getChannelAsPath(Path& result,
                        const Range<float>* levels,
                        int numLevels,
                        int nextSample);

  void setForegroundColor(Colour c);
  //==============================================================================
  /** @internal */
  void paint(Graphics&) override;
  void setCornerRadius(int cornerRadius);

private:
  struct ChannelInfo;

  OwnedArray<ChannelInfo> channels;
  int numSamples, inputSamplesPerBlock;
  Colour backgroundColour, foregroundColour, waveformColour;

  void timerCallback() override;
  int cornerRadius;
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BaseVisualiser)
};
