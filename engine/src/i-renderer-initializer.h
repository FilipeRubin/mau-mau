#pragma once

class IRendererInitializer
{
public:
	virtual ~IRendererInitializer() = default;
	virtual bool TryInitialize() = 0;
};
