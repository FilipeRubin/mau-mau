#include "opengl-renderer.h"
#include <glad/glad.h>

OpenGLRenderer::~OpenGLRenderer()
{
	Terminate(); // Just in case
}

void OpenGLRenderer::ClearScreen() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}

IMeshRenderer& OpenGLRenderer::GetMeshRenderer()
{
	return *m_meshRenderer;
}

void OpenGLRenderer::RenderFrame()
{
	m_meshRenderer->DrawAllMeshes();
}

bool OpenGLRenderer::TryInitialize()
{
	if (gladLoadGL() != 0)
	{
		m_meshRenderer = new OpenGLMeshRenderer();
		return true;
	}
	return false;
}

void OpenGLRenderer::SetBackgroundColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void OpenGLRenderer::Terminate()
{
	delete m_meshRenderer;
	m_meshRenderer = nullptr;
}
