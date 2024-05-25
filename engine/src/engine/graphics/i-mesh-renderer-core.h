#pragma once

class IMeshRendererCore
{
public:
	virtual ~IMeshRendererCore() = default;
	virtual void DrawAllMeshes() const = 0;
};
