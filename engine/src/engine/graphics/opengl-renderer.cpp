#include "opengl-renderer.h"
#include <glad/glad.h>

void OpenGLRenderer::ClearScreen() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}

bool OpenGLRenderer::TryInitialize()
{
	return gladLoadGL() != 0;
}

void OpenGLRenderer::SetBackgroundColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}
