#pragma once

#include "vector3.h"
#include <cmath>

namespace mlt
{
	float &Vector3::operator[](size_t i)
	{
		assert(i < 3);
		return (&x)[i];
	}

	Vector3 operator+(Vector3 a, Vector3 b)
	{
		return {
			a.x + b.x,
			a.y + b.y,
			a.z + b.z
		};
	}

	Vector3 operator-(Vector3 a, Vector3 b)
	{
		return {
			a.x - b.x,
			a.y - b.y,
			a.z - b.z
		};
	}

	Vector3 operator*(Vector3 a, Vector3 b)
	{
		return {
			a.x * b.x,
			a.y * b.y,
			a.z * b.z
		};
	}

	Vector3 operator*(Vector3 v, float s)
	{
		return {
			v.x * s,
			v.y * s,
			v.z * s
		};
	}

	Vector3 operator*(float s, Vector3 v)
	{
		return {
			v.x * s,
			v.y * s,
			v.z * s
		};
	}

	Vector3 cross(Vector3 a, Vector3 b)
	{
		return {
			a.y * b.z - b.y * a.z,
			a.z * b.x - b.z * a.x,
			a.x * b.y - b.x * a.y
		};
	}

	Vector3 normalized(Vector3 v)
	{
		float mag = length(v);
		if (mag != 0.0f)
		{
			return v * (1.0f / mag);
		}
		return v;
	}

	Vector3 normalized_unsafe(Vector3 v)
	{
		float mag = length(v);
		return v * (1.0f / mag);
	}

	float dot(Vector3 a, Vector3 b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	float length(Vector3 v)
	{
		return sqrtf(dot(v, v));
	}

	float distance(Vector3 a, Vector3 b)
	{
		return length(a - b);
	}

	Vector3 direction(Vector3 from, Vector3 to)
	{
		return normalized(to - from);
	}
}

