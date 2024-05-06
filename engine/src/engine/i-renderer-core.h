#pragma once

class IRendererCore
{
public:
	virtual ~IRendererCore() = default;
	virtual bool TryInitialize() = 0;
};
