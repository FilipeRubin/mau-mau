#pragma once

class OpenGLEBO
{
public:
	OpenGLEBO();
	~OpenGLEBO();
	void Bind() const;
	size_t GetSize() const;
	void SetData(const unsigned int* data, size_t size);
private:
	unsigned int m_ebo;
	size_t m_size;
};
