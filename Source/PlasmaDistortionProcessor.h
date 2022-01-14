#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class PlasmaDistortionProcessor
{
public:
	template<typename Data, typename Drive, typename Distortion>
	void distort(Data& data, Drive& drive, Distortion& type) {
		switch (type) {
		case Hardclip:
		{
			data = clamp(drive * data, -1.0, 1.0);
			break;
		}
		case Softclip:
		{
			data = 1.27 * atan(drive * data);
			break;
		}
		case Scream:
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
		case Bitcrush:
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
		case Root:
		{
			if (data > 0.0) {
				data = clamp(pow(data, 1.0 / ((drive / 4) + 0.75)), -1.0, 1.0);
			}
			else {
				data = -clamp(pow(-data, 1.0 / ((drive / 4) + 0.75)), -1.0, 1.0);
			}
			break;
		}
		case Atan:
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
		case Sine: {
			data = clamp(sin(drive * data), -1.0, 1.0);
			break;
		}
		case Cosine: {
			data = clamp(cos(drive * data), -1.0, 1.0);
			break;
		}
		}
	}
};