#include "WaveformComponent.h"

void WaveformComponent::paintChannel(
	Graphics& g,
	Rectangle<float> area,
	const Range<float>* levels,
	int numLevels,
	int nextSample)
{
	Path p;
	getChannelAsPath(p, levels, numLevels, nextSample);
	if (isVisible())
	{
		g.setColour(color);
		g.strokePath(
			p,
			PathStrokeType((getHeight() / 300.f)),
			AffineTransform::fromTargetPoints(
				0.0f,
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
				area.getY())
		);
	}
}

void WaveformComponent::setColor(Colour c)
{
	color = c;
}

void WaveformComponent::setBackgroundColor(Colour c)
{
	setColours(c, c);
}