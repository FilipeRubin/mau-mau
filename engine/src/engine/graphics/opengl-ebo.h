#pragma once

class OpenGLEBO
{
public:
	OpenGLEBO();
	~OpenGLEBO();
	void Bind() const;
	size_t GetLength() const;
	void SetData(const unsigned int* data, size_t length);
private:
	unsigned int m_ebo;
	size_t m_length;
};
