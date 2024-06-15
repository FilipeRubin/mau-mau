#include "opengl-vao.h"
#include <glad/glad.h>

OpenGLVAO::OpenGLVAO() :
	m_vao(0U)
{
	glGenVertexArrays(1, &m_vao);
}

OpenGLVAO::~OpenGLVAO()
{
	glDeleteVertexArrays(1, &m_vao);
}

void OpenGLVAO::Bind() const
{
	glBindVertexArray(m_vao);
}

void OpenGLVAO::SetVertexAttribute(const OpenGLVertexAttribute& attribute) const
{
	glVertexAttribPointer(
		attribute.index,
		attribute.elementCount,
		GL_FLOAT, GL_FALSE,
		attribute.stride,
		static_cast<const void*>(&attribute.offset));
	glEnableVertexAttribArray(attribute.index);
}
