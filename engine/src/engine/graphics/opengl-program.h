#pragma once
#include "opengl-shader.h"
#include "engine/math/matrix4x4.h"

class OpenGLProgram
{
public:
	OpenGLProgram();
	~OpenGLProgram();
	void AttachShader(const OpenGLShader& shader) const;
	void Link() const;
	void UniformMatrix4x4(const std::string& name, const Matrix4x4& value) const;
	void Use() const;
private:
	unsigned int m_program;
};
