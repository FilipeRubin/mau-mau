#pragma once
#include "engine/graphics/i-mesh-renderer.h"
#include "opengl-mesh.h"

class OpenGLMeshRenderer : public IMeshRenderer
{
public:
	std::shared_ptr<IMesh> CreateMesh() override;
private:
	std::vector<std::shared_ptr<OpenGLMesh>> m_meshes;
};
