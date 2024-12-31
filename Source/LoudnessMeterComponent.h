#pragma once

#include <JuceHeader.h>

namespace Gui {
class LoudnessMeterComponent : public Component
{
public:
  void paint(Graphics& g) override
  {
    auto bounds = getLocalBounds().toFloat();
    g.setColour(Colours::red);
    g.fillAll();
    g.setColour(Colours::green);
    g.fillRect(
      bounds.withTrimmedTop(bounds.getHeight() * (1.0f - level / -60.0f)));
  }
  void setLevel(const float value) { level = value; };

private:
  float level = -60.0f;
};
}