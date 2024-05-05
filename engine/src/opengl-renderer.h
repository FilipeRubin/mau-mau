#pragma once
#include "engine/i-renderer.h"
#include "i-renderer-initializer.h"

class OpenGLRenderer : public IRenderer, public IRendererInitializer
{
public:
	void ClearScreen() const override;
	void SetBackgroundColor(float r, float g, float b, float a) override;
	bool TryInitialize() override;
};
