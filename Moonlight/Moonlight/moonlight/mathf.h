#pragma once

namespace mlt
{
	constexpr float Pi = 3.141592653f;
	constexpr float Tau = 2.0f * Pi;
	constexpr float Two_Pi = Tau;
	constexpr float Half_Pi = Pi / 2.0f;
	constexpr float Quarter_Pi = Pi / 4.0f;

	float lerp(float a, float b, float t);
	float move_towards(float x, float dest, float step);
	float clamp(float x, float low, float high);
	float clamp01(float x);
	float radians(float degrees);
	float degrees(float radians);
}
