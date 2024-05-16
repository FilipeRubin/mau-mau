#pragma once
#include "engine/math/transform3d.h"
#include "mesh-data.h"

class IMesh
{
public:
	virtual ~IMesh() = default;
	virtual void LoadData(const MeshData& data) = 0;
};
