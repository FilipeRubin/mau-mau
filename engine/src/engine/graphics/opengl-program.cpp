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

void OpenGLProgram::UniformMatrix4x4(const std::string& name, const Matrix4x4& value) const
{
	int location = glGetUniformLocation(m_program, name.c_str());
	glUniformMatrix4fv(location, 1, GL_TRUE, reinterpret_cast<const float*>(&value));
}

void OpenGLProgram::Use() const
{
	glUseProgram(m_program);
}
