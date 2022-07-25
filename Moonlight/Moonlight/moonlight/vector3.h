#pragma once

#include <cassert>

namespace mlt
{
	union Vector3
	{
		struct { float x, y, z; };
		struct { float r, g, b; };
		struct { float width, height, depth; };

		float &operator[](size_t i);
	};

	Vector3 operator+(Vector3 a, Vector3 b);
	Vector3 operator-(Vector3 a, Vector3 b);
	Vector3 operator*(Vector3 a, Vector3 b);
	Vector3 operator*(Vector3 v, float s);
	Vector3 operator*(float s, Vector3 v);
	Vector3 cross(Vector3 a, Vector3 b);
	Vector3 normalized(Vector3 v);
	Vector3 normalized_unsafe(Vector3 v);
	Vector3 direction(Vector3 from, Vector3 to);
	float dot(Vector3 a, Vector3 b);
	float length(Vector3 v);
	float distance(Vector3 a, Vector3 b);
};

