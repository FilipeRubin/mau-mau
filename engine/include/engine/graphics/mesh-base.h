#pragma once
#include "engine/math/transform3d.h"
#include "mesh-data.h"

class MeshBase
{
public:
	Transform3D transform;
	virtual ~MeshBase() = default;
	virtual void LoadData(const MeshData& data) = 0;
};
