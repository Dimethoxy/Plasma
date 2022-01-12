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
		setColours(Colour::fromRGBA(18, 20, 20, 255), Colours::white);
	}
	void paintChannel(
		Graphics&,
		Rectangle<float> bounds,
		const Range<float>* levels,
		int numLevels,
		int nextSample) override;
private:
};