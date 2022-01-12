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
		g.strokePath(p, PathStrokeType(2.0), AffineTransform::fromTargetPoints(0.0f, -1.0f, area.getX(), area.getY(),
			0.0f, 1.0f, area.getX(), area.getBottom(),
			(float)numLevels, -1.0f, area.getRight(), area.getY()));
	}
}

