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

void OpenGLVBO::SetData(const void* data, size_t length) const
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, length, data, GL_STATIC_DRAW);
}
