#pragma once
#include "engine/graphics/i-mesh-renderer.h"
#include "i-mesh-renderer-core.h"
#include "opengl-mesh.h"
#include "opengl-program.h"

class OpenGLMeshRenderer : public IMeshRenderer, public IMeshRendererCore
{
public:
	OpenGLMeshRenderer();
	std::shared_ptr<MeshBase> CreateMesh() override;
	void DrawAllMeshes() const override;
private:
	std::vector<std::shared_ptr<OpenGLMesh>> m_meshes;
	OpenGLProgram m_program;
	void CreateProgram();
	Matrix4x4 GenerateModelMatrix(const Transform3D& transform) const;
};
