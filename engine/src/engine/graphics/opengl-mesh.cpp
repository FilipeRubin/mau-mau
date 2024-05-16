#include "opengl-mesh.h"
#include <glad/glad.h>

OpenGLMesh::OpenGLMesh() :
	m_vbo(0U),
	m_vao(0U),
	m_ebo(0U),
	m_indexCount(0U)
{
	GenerateBuffers();
}

OpenGLMesh::~OpenGLMesh()
{
	DeleteBuffers();
}

void OpenGLMesh::Draw() const
{
	DrawIndexedGeometry();
}

void OpenGLMesh::LoadData(const MeshData& data)
{
	FillVertexBufferData(data.vertices);
	FillIndexBufferData(data.indices);
	CreateVertexAttributes();
}

void OpenGLMesh::CreateVertexAttributes()
{
	glBindVertexArray(m_vao);
	glVertexAttribPointer(0U, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)0U);
	glVertexAttribPointer(1U, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)12U);
	glVertexAttribPointer(2U, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)20U);
	glEnableVertexAttribArray(0U);
	glEnableVertexAttribArray(1U);
	glEnableVertexAttribArray(2U);
}

void OpenGLMesh::DeleteBuffers()
{
	m_indexCount = 0U;
	glDeleteBuffers(1, &m_vbo);
	glGenVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_ebo);
}

void OpenGLMesh::DrawIndexedGeometry() const
{
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, (const void*)0U);
}

void OpenGLMesh::FillVertexBufferData(const std::vector<Vertex>& vertices)
{
	const size_t bufferLength = vertices.size() * sizeof(Vertex);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, bufferLength, vertices.data(), GL_STATIC_DRAW);
}

void OpenGLMesh::FillIndexBufferData(const std::vector<unsigned int>& indices)
{
	m_indexCount = indices.size();
	const size_t indexBufferLength = m_indexCount * sizeof(unsigned int);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferLength, indices.data(), GL_STATIC_DRAW);
}

void OpenGLMesh::GenerateBuffers()
{
	glGenBuffers(1, &m_vbo);
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_ebo);
}
