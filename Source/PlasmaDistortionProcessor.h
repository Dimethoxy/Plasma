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
	Crunch,
	Upwards,
	Sine,
	Cosine,
	Plasma,
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
		case Distortion::Crunch:
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
			if (data != 0.0f)
			{
				if (data > 0.0f) {
					data = pow(data, 1.0f / drive);
					data = 1.27f * atan(data);
				}
				else {
					data = pow(-data, 1.0f / drive);
					data = 1.27f * atan(data);
					data = -data;
				}
			}
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
		case Distortion::Upwards: {
			float invertedDrive = (10.0f / drive);
			if (std::abs(data) >= ((invertedDrive - 1) / 9.0f))
			{
				auto signbit = (std::signbit(data) ? -1 : 1);
				data = signbit;
			}
			break;
		}
		case Distortion::Softclip: {
			float threshold1 = 1.0f / 3.0f;
			float threshold2 = 2.0f / 3.0f;

			data *= drive;
			if (data > threshold2)
				data = 1.0f;
			else if (data > threshold1)
				data = 1.0f - powf(2.0f - 3.0f * data, 2.0f) / 3.0f;
			else if (data < -threshold2)
				data = -1.0f;
			else if (data < -threshold1)
				data = -1.0f + powf(2.0f + 3.0f * data, 2.0f) / 3.0f;
			else
				data = 2.0f * data;
			data *= 0.95;
			break;
		}
		case Distortion::Plasma: {
			data = data * (drive * 2);
			float h1 = sin(2 * data);
			float h2 = sin(3 * data);
			float h3 = sin(4 * data);
			data = sin(h1 + h2 + h3 + data);
			break;
		}
		}
	}
}

