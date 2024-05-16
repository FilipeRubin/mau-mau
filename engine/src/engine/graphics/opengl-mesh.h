#pragma once
#include "engine/graphics/i-mesh.h"
#include "i-mesh-core.h"

class OpenGLMesh : public IMesh, public IMeshCore
{
public:
	OpenGLMesh();
	~OpenGLMesh();
	void Draw() const override;
	void LoadData(const MeshData& data) override;
private:
	unsigned int m_vbo;
	unsigned int m_vao;
	unsigned int m_ebo;
	unsigned int m_indexCount;
	void CreateVertexAttributes();
	void DeleteBuffers();
	void DrawIndexedGeometry() const;
	void FillVertexBufferData(const std::vector<Vertex>& vertices);
	void FillIndexBufferData(const std::vector<unsigned int>& indices);
	void GenerateBuffers();
};
