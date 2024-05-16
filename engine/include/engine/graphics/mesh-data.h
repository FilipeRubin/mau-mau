#pragma once
#include "engine/math/vertex.h"
#include <vector>

struct MeshData
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
};
