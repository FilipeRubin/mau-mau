#pragma once
#include "mesh-base.h"
#include <memory>

class IMeshRenderer
{
public:
	virtual ~IMeshRenderer() = default;
	virtual std::shared_ptr<MeshBase> CreateMesh() = 0;
};
