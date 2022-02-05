#include "ShapercurveComponent.h"


ShapercurveComponent::ShapercurveComponent(PlasmaAudioProcessor& p, int stage) : audioProcessor(p)
{
	//Listen to parameter changes
	const auto& params = audioProcessor.getParameters();
	for (auto param : params)
	{
		param->addListener(this);
	}
	startTimer(60);
	this->stage = stage;
}

ShapercurveComponent::~ShapercurveComponent()
{
	const auto& params = audioProcessor.getParameters();
	for (auto param : params)
	{
		param->removeListener(this);
	}
}

void ShapercurveComponent::parameterValueChanged(int parameterIndex, float newValue)
{
	parametersChanged.set(true);
}

void ShapercurveComponent::timerCallback()
{
	if (parametersChanged.compareAndSetBool(false, true))
	{
		repaint();
	}
}

void ShapercurveComponent::paint(juce::Graphics& g)
{
	using namespace juce;

	//Get Chain Settings
	auto chainSettings = getChainSettings(audioProcessor.apvts);

	//bounds
	auto bounds = getBounds();
	auto lineSize = bounds.getHeight() / 100;

	//Screen
	auto x = 0;
	auto y = 0;
	auto w = bounds.getWidth();
	auto h = bounds.getHeight();

	//Info
	float drive = 2.0;
	Distortion type = Distortion::Hardclip;
	float bias = 0.0;
	float girth = 0.0;
	switch (stage)
	{
	case 0:
	{
		type = chainSettings.driveType;
		drive = chainSettings.drive;
		bias = chainSettings.bias;
		girth = chainSettings.girth;
		break;
	}
	case 1:
	{
		type = chainSettings.lateDriveType;
		drive = chainSettings.lateDrive;
		bias = chainSettings.lateBias;
		girth = chainSettings.lateGirth;
		break;
	}
	}
	float sampleSize = 2.0 / w;

	//Draw
	std::vector<double> samples;
	samples.resize(w);
	for (int i = 0; i < w; ++i)
	{
		//Write
		samples[i] = i * sampleSize - 1;

		//Distort
		DistortionProcessor::distort(samples[i], drive, type);

		//Girth
		samples[i] = samples[i] *
			((((float)(rand() % 100)) / 100 * girth) + 1);

		//Bias
		if (samples[i] > 0)
		{
			samples[i] += samples[i] * bias;
		}
		else if (samples[i] < 0)
		{
			samples[i] -= samples[i] * bias;
		}
	}
	Path shaperCurve;
	const double outputMin = y + h;
	const double outputMax = y;
	auto map = [outputMin, outputMax](double input)
	{
		return jmap(input, -1.0, 1.0, outputMin, outputMax);
	};

	shaperCurve.startNewSubPath(x, map(samples.front()));
	for (size_t i = 1; i < samples.size(); ++i)
	{
		shaperCurve.lineTo(x + i, map(samples[i]));
	}
	if (true)
	{
		g.setColour(color);
		g.drawRect(x, y, w, h, 2.0 * lineSize);
		g.strokePath(shaperCurve, PathStrokeType(1.5 * lineSize));
	}
}

void ShapercurveComponent::setColor(Colour c)
{
	color = c;
}