#include "opengl-ebo.h"
#include <glad/glad.h>

OpenGLEBO::OpenGLEBO() :
	m_ebo(0U),
	m_size(0U)
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

size_t OpenGLEBO::GetSize() const
{
	return m_size;
}

void OpenGLEBO::SetData(const unsigned int* data, size_t size)
{
	m_size = size;
	const size_t length = sizeof(unsigned int) * size;
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, length, data, GL_STATIC_DRAW);
}
