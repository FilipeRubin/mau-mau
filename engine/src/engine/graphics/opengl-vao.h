#pragma once
#include "opengl-vertex-attribute.h"
#include <vector>

class OpenGLVAO
{
public:
	OpenGLVAO();
	~OpenGLVAO();
	void Bind() const;
	void SetVertexAttribute(const OpenGLVertexAttribute& attribute) const;
private:
	unsigned int m_vao;
};
