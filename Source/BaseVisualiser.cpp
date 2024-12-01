#include "BaseVisualiser.h"

struct BaseVisualiser::ChannelInfo
{
  ChannelInfo(BaseVisualiser& o, int bufferSize)
    : owner(o)
  {
    setBufferSize(bufferSize);
    clear();
  }

  void clear() noexcept
  {
    levels.fill({});
    value = {};
    subSample = 0;
  }

  void pushSamples(const float* inputSamples, int num) noexcept
  {
    for (int i = 0; i < num; ++i)
      pushSample(inputSamples[i]);
  }

  void pushSample(float newSample) noexcept
  {
    if (--subSample <= 0) {
      if (++nextSample == levels.size())
        nextSample = 0;

      levels.getReference(nextSample) = value;
      subSample = owner.getSamplesPerBlock();
      value = Range<float>(newSample, newSample);
    } else {
      value = value.getUnionWith(newSample);
    }
  }

  void setBufferSize(int newSize)
  {
    levels.removeRange(newSize, levels.size());
    levels.insertMultiple(-1, {}, newSize - levels.size());

    if (nextSample >= newSize)
      nextSample = 0;
  }

  BaseVisualiser& owner;
  Array<Range<float>> levels;
  Range<float> value;
  std::atomic<int> nextSample{ 0 }, subSample{ 0 };

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChannelInfo)
};

//==============================================================================
BaseVisualiser::BaseVisualiser(int initialNumChannels)
  : numSamples(1024)
  , inputSamplesPerBlock(256)
  , backgroundColour(Colours::black)
  , waveformColour(Colours::white)
{
  setOpaque(true);
  setNumChannels(initialNumChannels);
  setRepaintRate(60);
}

BaseVisualiser::~BaseVisualiser() {}

void
BaseVisualiser::setNumChannels(int numChannels)
{
  channels.clear();

  for (int i = 0; i < numChannels; ++i)
    channels.add(new ChannelInfo(*this, numSamples));
}

void
BaseVisualiser::setBufferSize(int newNumSamples)
{
  numSamples = newNumSamples;

  for (auto* c : channels)
    c->setBufferSize(newNumSamples);
}

void
BaseVisualiser::clear()
{
  for (auto* c : channels)
    c->clear();
}

void
BaseVisualiser::pushBuffer(const float* const* d, int numChannels, int num)
{
  numChannels = jmin(numChannels, channels.size());

  for (int i = 0; i < numChannels; ++i)
    channels.getUnchecked(i)->pushSamples(d[i], num);
}

void
BaseVisualiser::pushBuffer(const AudioBuffer<float>& buffer)
{
  pushBuffer(buffer.getArrayOfReadPointers(),
             buffer.getNumChannels(),
             buffer.getNumSamples());
}

void
BaseVisualiser::pushBuffer(const AudioSourceChannelInfo& buffer)
{
  auto numChannels = jmin(buffer.buffer->getNumChannels(), channels.size());

  for (int i = 0; i < numChannels; ++i)
    channels.getUnchecked(i)->pushSamples(
      buffer.buffer->getReadPointer(i, buffer.startSample), buffer.numSamples);
}

void
BaseVisualiser::pushSample(const float* d, int numChannels)
{
  numChannels = jmin(numChannels, channels.size());

  for (int i = 0; i < numChannels; ++i)
    channels.getUnchecked(i)->pushSample(d[i]);
}

void
BaseVisualiser::setSamplesPerBlock(int newSamplesPerPixel) noexcept
{
  inputSamplesPerBlock = newSamplesPerPixel;
}

void
BaseVisualiser::setRepaintRate(int frequencyInHz)
{
  startTimerHz(frequencyInHz);
}

void
BaseVisualiser::timerCallback()
{
  repaint();
}

void
BaseVisualiser::setColours(Colour bk, Colour wf, Colour fg) noexcept
{
  backgroundColour = bk;
  foregroundColour = fg;
  waveformColour = wf;
  repaint();
}

void
BaseVisualiser::paint(Graphics& g)
{
  g.fillAll(foregroundColour);
  g.setColour(backgroundColour);
  g.fillRoundedRectangle(getLocalBounds().toFloat(), cornerRadius);
  auto r = getLocalBounds().toFloat();
  auto channelHeight = r.getHeight() / (float)channels.size();

  g.setColour(waveformColour);

  for (auto* c : channels)
    paintChannel(g,
                 r.removeFromTop(channelHeight),
                 c->levels.begin(),
                 c->levels.size(),
                 c->nextSample);
}

void
BaseVisualiser::getChannelAsPath(Path& path,
                                 const Range<float>* levels,
                                 int numLevels,
                                 int nextSample)
{
  path.preallocateSpace(4 * numLevels + 8);

  for (int i = 0; i < numLevels; ++i) {
    auto level = -(levels[(nextSample + i) % numLevels].getEnd());

    if (i == 0)
      path.startNewSubPath(0.0f, level);
    else
      path.lineTo((float)i, level);
  }

  for (int i = numLevels; --i >= 0;)
    path.lineTo((float)i, -(levels[(nextSample + i) % numLevels].getStart()));

  path.closeSubPath();
}

void
BaseVisualiser::paintChannel(Graphics& g,
                             Rectangle<float> area,
                             const Range<float>* levels,
                             int numLevels,
                             int nextSample)
{
  Path p;
  getChannelAsPath(p, levels, numLevels, nextSample);

  g.fillPath(p,
             AffineTransform::fromTargetPoints(0.0f,
                                               -1.0f,
                                               area.getX(),
                                               area.getY(),
                                               0.0f,
                                               1.0f,
                                               area.getX(),
                                               area.getBottom(),
                                               (float)numLevels,
                                               -1.0f,
                                               area.getRight(),
                                               area.getY()));
}

void
BaseVisualiser::setCornerRadius(int cornerRadius)
{
  this->cornerRadius = cornerRadius;
}