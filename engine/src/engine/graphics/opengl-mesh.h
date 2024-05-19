#pragma once
#include "engine/graphics/i-mesh.h"
#include "i-mesh-core.h"
#include "opengl-ebo.h"
#include "opengl-vao.h"
#include "opengl-vbo.h"

class OpenGLMesh : public IMesh, public IMeshCore
{
public:
	void Draw() const override;
	void LoadData(const MeshData& data) override;
private:
	OpenGLVBO m_vbo;
	OpenGLVAO m_vao;
	OpenGLEBO m_ebo;
	void SetVertexAttributes() const;
};
