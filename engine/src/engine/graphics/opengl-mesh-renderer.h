#pragma once
#include "engine/graphics/i-mesh-renderer.h"
#include "i-mesh-renderer-core.h"
#include "opengl-mesh.h"

class OpenGLMeshRenderer : public IMeshRenderer, public IMeshRendererCore
{
public:
	std::shared_ptr<IMesh> CreateMesh() override;
	void DrawAllMeshes() const override;
private:
	std::vector<std::shared_ptr<OpenGLMesh>> m_meshes;
};
