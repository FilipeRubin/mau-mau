#pragma once

class OpenGLVBO
{
public:
	OpenGLVBO();
	~OpenGLVBO();
	void Bind() const;
	void SetData(const void* data, size_t length) const;
private:
	unsigned int m_vbo;
};
