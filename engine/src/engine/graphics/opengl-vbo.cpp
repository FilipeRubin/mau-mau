#include "opengl-vbo.h"
#include <glad/glad.h>

OpenGLVBO::OpenGLVBO() :
	m_vbo(0U)
{
	glGenBuffers(1, &m_vbo);
}

OpenGLVBO::~OpenGLVBO()
{
	glDeleteBuffers(1, &m_vbo);
}

void OpenGLVBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void OpenGLVBO::SetData(const Vertex* data, size_t length) const
{
	Bind();
	const size_t size = length * sizeof(Vertex);
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)size, data, GL_STATIC_DRAW);
}
