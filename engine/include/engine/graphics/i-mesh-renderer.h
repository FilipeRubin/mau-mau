#pragma once
#include "i-mesh.h"
#include <memory>

class IMeshRenderer
{
public:
	virtual ~IMeshRenderer() = default;
	virtual std::shared_ptr<IMesh> CreateMesh() = 0;
};
