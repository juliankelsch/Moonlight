#include "moonlight/core.h"

#include <iostream>

using namespace mlt;

int main(int argc, char **argv)
{
	Array_List<Vector3> vertices = {};

	vertices.push_back({ 0, 0, 0 });
	vertices.push_back({ 1, 0, 0 });
	vertices.push_back({ 0, 1, 0 });
	vertices.push_back({ 0, 0, 1 });

	for (size_t i = 0; i < vertices.count; i++)
	{
		std::cout << vertices[i].x << " " << vertices[i].y << " " << vertices[i].z << '\n';
	}
}
