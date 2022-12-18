#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

enum Distortion
{
	Hardclip,
	Softclip,
	Saturate,
	Atan,
	Crunch,
	Bitcrush,
	Extreme,
	Scream,
	Sine,
	Cosine,
	Weird,
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
			float bitDepth = 10.0f - drive;
			float exponent = bitDepth - 1;
			float possibleValues = pow(2, exponent);
			float quantized = (data + 1.0f) * possibleValues;
			quantized = round(quantized);
			data = (quantized / possibleValues) - 1.0f;
			break;
		}

		case Distortion::Saturate:
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
		case Distortion::Extreme: {
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
		case Distortion::Weird: {
			data = data * (drive * 2);
			float h1 = sin(2 * data);
			float h2 = sin(3 * data);
			float h3 = sin(4 * data);
			data = sin(h1 + h2 + h3 + data);
			break;
		}
		case Distortion::Scream: {
			auto temp = data;
			auto normalizedDrive = (drive - 1) / 10.0f;

			if (data > 0.0) {
				data = clamp(pow(data, 1.0 / ((drive / 4) + 0.75)), -1.0, 1.0);
			}
			else {
				data = -clamp(pow(-data, 1.0 / ((drive / 4) + 0.75)), -1.0, 1.0);
			}


			if (data <= -0.5)
			{
				auto offset = 3.0;
				temp = 4 * data + offset;
			}
			else if (data > -0.5 && data < 0.5)
			{
				temp = -2 * data;
			}
			else
			{
				auto offset = -3.0;
				temp = 4 * data + offset;
			}

			data = (temp * normalizedDrive) + (data * (1 - normalizedDrive));


			break;

		}
		}
	}
}

