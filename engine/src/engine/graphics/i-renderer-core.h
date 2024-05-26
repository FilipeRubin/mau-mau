#pragma once

class IRendererCore
{
public:
	virtual ~IRendererCore() = default;
	virtual void ClearScreen() const = 0;
	virtual void RenderFrame() = 0;
	virtual bool TryInitialize() = 0;
};
