#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

enum Distortion
{
	Hardclip,
	Softclip,
	Root,
	Atan,
	Bitcrush,
	Scream,
	Sine,
	Cosine
};
namespace DistortionProcessor
{
	inline float clamp(float d, float min, float max)
	{
		const float t = d < min ? min : d;
		return t > max ? max : t;
	}

	template<typename Data, typename Drive, typename Distortion>
	void distort(Data& data, Drive& drive, Distortion& type) {
		switch (type) {
		case Distortion::Hardclip:
		{
			data = clamp(drive * data, -1.0, 1.0);
			break;
		}
		case Distortion::Softclip:
		{
			data = 1.27 * atan(drive * data);
			break;
		}
		case Distortion::Scream:
		{
			if (data > 0.0) {
				data = pow(data, 1.0f / drive);
				data = 1.27 * atan(data);
			}
			else {
				data = clamp(sin(drive * data), -1.0, 1.0);
				data = clamp(drive * data, -1.0, 1.0);
			};
			break;
		}
		case Distortion::Bitcrush:
		{
			float bitDepth = 11.0 - drive;
			float exponent = bitDepth - 1;
			float possibleValues = pow(2, exponent);
			float quantized = data * possibleValues;
			if (quantized > 0)
			{
				quantized = ceil(quantized);
			}
			else if (quantized < 0)
			{
				quantized = floor(quantized);
			}
			data = quantized / possibleValues;
			break;
		}
		case Distortion::Root:
		{
			if (data > 0.0) {
				data = clamp(pow(data, 1.0 / ((drive / 4) + 0.75)), -1.0, 1.0);
			}
			else {
				data = -clamp(pow(-data, 1.0 / ((drive / 4) + 0.75)), -1.0, 1.0);
			}
			break;
		}
		case Distortion::Atan:
		{
			if (data > 0.0) {
				data = pow(data, 1.0f / drive);
				data = 1.27 * atan(data);
			}
			else {
				data = pow(-data, 1.0f / drive);
				data = 1.27 * atan(data);
				data = -data;
			};
			break;
		}
		case Distortion::Sine: {
			data = clamp(sin(drive * data), -1.0, 1.0);
			break;
		}
		case Distortion::Cosine: {
			data = clamp(cos(drive * data), -1.0, 1.0);
			break;
		}
		}
	}
}
