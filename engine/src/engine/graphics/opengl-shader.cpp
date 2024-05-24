#include "opengl-shader.h"
#include <glad/glad.h>
#include <cassert>
#include <iostream>

OpenGLShader::OpenGLShader(OpenGLShaderType type) :
	m_shader(0U),
	m_type(type)
{
	m_shader = glCreateShader(static_cast<unsigned int>(type));
}

OpenGLShader::~OpenGLShader()
{
	glDeleteShader(m_shader);
}

unsigned int OpenGLShader::GetShaderId() const
{
	return m_shader;
}

void OpenGLShader::SetSource(const char* source) const
{
	glShaderSource(m_shader, 1, &source, nullptr);
}

bool OpenGLShader::TryCompile() const
{
	glCompileShader(m_shader);

	std::string errorMessage;
	if (not CheckCompileStatus(errorMessage))
	{
		std::cout << errorMessage << std::endl;
		return false;
	}
	return true;
}

bool OpenGLShader::CheckCompileStatus(std::string& out_errorMessage) const
{
	out_errorMessage.clear();

	int compileStatus;
	glGetShaderiv(m_shader, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus == GL_FALSE)
	{
		int messageLength;
		glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &messageLength);

		out_errorMessage.resize(messageLength);
		glGetShaderInfoLog(m_shader, messageLength, &messageLength, &out_errorMessage[0]);

		return false;
	}
	return true;
}
