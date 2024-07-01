#include "opengl-ebo.h"
#include <glad/glad.h>

OpenGLEBO::OpenGLEBO() :
	m_ebo(0U),
	m_length(0U)
{
	glGenBuffers(1, &m_ebo);
}

OpenGLEBO::~OpenGLEBO()
{
	glDeleteBuffers(1, &m_ebo);
}

void OpenGLEBO::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

size_t OpenGLEBO::GetLength() const
{
	return m_length;
}

void OpenGLEBO::SetData(const unsigned int* data, size_t length)
{
	m_length = length;
	const size_t size = length * sizeof(unsigned int);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)size, data, GL_STATIC_DRAW);
}
