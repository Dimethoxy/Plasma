#pragma once

#include "BaseVisualiser.h"
#include <JuceHeader.h>

class WaveformComponent : public BaseVisualiser
{
public:
  WaveformComponent()
    : BaseVisualiser(2)
  {
    // 1024/4
    setBufferSize(1024);
    setSamplesPerBlock(4);
  }
  void paintChannel(Graphics&,
                    Rectangle<float> bounds,
                    const Range<float>* levels,
                    int numLevels,
                    int nextSample) override;
  void setColor(Colour c);
  void setBackgroundColor(Colour c, Colour f);

private:
  Colour color = Colour(255, 255, 255);
};