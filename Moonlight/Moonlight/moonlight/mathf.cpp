#pragma once

#include "mathf.h"

#include <cmath>

namespace mlt
{
	float lerp(float a, float b, float t)
	{
		return (1.0f - t) * a + b * t;
	}

	float move_towards(float x, float dest, float step)
	{
		if (x < dest)
		{
			return x + fminf(dest - x, fabsf(step));
		}
		else
		{
			return x - fminf(x - dest, fabsf(step));
		}
	}

	float clamp(float x, float low, float high)
	{
		return x < low ? low : (x > high ? high : x);
	}

	float clamp01(float x)
	{
		return clamp(x, 0.0f, 1.0f);
	}

	float radians(float degrees)
	{
		return degrees * (Pi / 180.0f);
	}

	float degrees(float radians)
	{
		return radians * (180.0f / Pi);
	}
}
