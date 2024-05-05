#pragma once
#include "engine/i-renderer.h"
#include "i-renderer-core.h"

class OpenGLRenderer : public IRenderer, public IRendererCore
{
public:
	void ClearScreen() const override;
	void SetBackgroundColor(float r, float g, float b, float a) override;
	bool TryInitialize() override;
};
