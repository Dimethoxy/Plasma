#pragma once

#include <JuceHeader.h>

namespace Gui
{
	class LoudnessMeterComponent : public Component
	{
	public:
		auto chainSettings = getChainSettings(audioProcessor.apvts);
		void paint(Graphics& g) override
		{
			auto bounds = getLocalBounds().toFloat();
			
			g.setColour(Colours::white);
			g.fillRoundedRectangle(bounds, 5.0f);

			g.setColour(Colours::white);
			const auto scaledX = jmap(level, -60.f, 6.0f, 0.0f, static_cast<float>(getWidth()));
			g.fillRoundedRectangle(bounds.removeFromLeft(scaledX), 5);
		}
		void setLevel(const float value) { level = value; };
	private:
		float level = -60.0f;
	};
}