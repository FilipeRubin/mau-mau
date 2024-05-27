#pragma once
#include "engine/math/vertex.h"

class OpenGLVBO
{
public:
	OpenGLVBO();
	~OpenGLVBO();
	void Bind() const;
	void SetData(const Vertex* data, size_t length) const;
private:
	unsigned int m_vbo;
};
