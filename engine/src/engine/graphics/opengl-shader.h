#pragma once
#include "opengl-shader-type.h"
#include <string>

class OpenGLShader
{
public:
	OpenGLShader(OpenGLShaderType type);
	~OpenGLShader();
	unsigned int GetShaderId() const;
	void SetSource(const char* source) const;
	bool TryCompile() const;
private:
	unsigned int m_shader;
	OpenGLShaderType m_type;
	bool CheckCompileStatus(std::string& out_errorMessage) const;
};
