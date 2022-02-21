#pragma once

#include <JuceHeader.h>

class WaveformComponent : public AudioVisualiserComponent
{
public:
	WaveformComponent() : AudioVisualiserComponent(2)
	{
		//1024/4
		setBufferSize(1024);
		setSamplesPerBlock(4);
	}
	void paintChannel(
		Graphics&,
		Rectangle<float> bounds,
		const Range<float>* levels,
		int numLevels,
		int nextSample) override;
	void setColor(Colour c);
	void setBackgroundColor(Colour c);
private:
	Colour color = Colour(255, 255, 255);
};