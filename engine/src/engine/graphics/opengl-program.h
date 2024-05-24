#pragma once
#include "opengl-shader.h"

class OpenGLProgram
{
public:
	OpenGLProgram();
	~OpenGLProgram();
	void AttachShader(const OpenGLShader& shader) const;
	void Link() const;
private:
	unsigned int m_program;
};
