#pragma once

class IRendererCore
{
public:
	virtual ~IRendererCore() = default;
	virtual void RenderFrame() = 0;
	virtual bool TryInitialize() = 0;
};
