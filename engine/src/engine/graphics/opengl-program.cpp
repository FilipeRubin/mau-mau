#include "opengl-program.h"
#include <glad/glad.h>

OpenGLProgram::OpenGLProgram() :
	m_program(0U)
{
	m_program = glCreateProgram();
}

OpenGLProgram::~OpenGLProgram()
{
	glDeleteProgram(m_program);
}

void OpenGLProgram::AttachShader(const OpenGLShader& shader) const
{
	glAttachShader(m_program, shader.GetShaderId());
}

void OpenGLProgram::Link() const
{
	glLinkProgram(m_program);
}

void OpenGLProgram::Use() const
{
	glUseProgram(m_program);
}
