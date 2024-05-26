#pragma once
#include "engine/graphics/i-renderer.h"
#include "i-renderer-core.h"
#include "opengl-mesh-renderer.h"

class OpenGLRenderer : public IRenderer, public IRendererCore
{
public:
	void ClearScreen() const override;
	IMeshRenderer& GetMeshRenderer() override;
	void RenderFrame() override;
	void SetBackgroundColor(float r, float g, float b, float a) override;
	bool TryInitialize() override;
private:
	OpenGLMeshRenderer m_meshRenderer;
};
