#pragma once
#include "i-mesh-renderer.h"

class IRenderer
{
public:
	virtual ~IRenderer() = default;
	virtual IMeshRenderer& GetMeshRenderer() = 0;
	virtual void SetBackgroundColor(float r, float g, float b, float a) = 0;
};
