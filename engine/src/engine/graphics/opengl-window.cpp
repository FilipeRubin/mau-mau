#include "opengl-window.h"
#include "../input/opengl-input.h"
#include "opengl-renderer.h"
#include <GLFW/glfw3.h>

OpenGLWindow::OpenGLWindow() :
	m_input(nullptr),
	m_renderer(nullptr),
	m_window(nullptr)
{
}

OpenGLWindow::~OpenGLWindow()
{
	Destroy(); // Just to make sure
}

void OpenGLWindow::Destroy()
{
	delete m_input;
	m_input = nullptr;
	delete m_renderer;
	m_renderer = nullptr;
	glfwDestroyWindow(m_window);
	m_window = nullptr;
	glfwTerminate();
}

IInput* OpenGLWindow::GetInput() const
{
	return m_input;
}

IRenderer* OpenGLWindow::GetRenderer() const
{
	return m_renderer;
}

void OpenGLWindow::Process()
{
	dynamic_cast<IInputCore*>(m_input)->Process();
	dynamic_cast<IRendererCore*>(m_renderer)->ClearScreen();
	dynamic_cast<IRendererCore*>(m_renderer)->RenderFrame();
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

bool OpenGLWindow::ShouldContinueRunning() const
{
	return !glfwWindowShouldClose(m_window);
}

bool OpenGLWindow::TryCreateWindow(int width, int height, const std::string& title)
{
	if (not TryInitialize(width, height, title.c_str()))
	{
		return false;
	}

	if (not TryCreateInput())
	{
		Destroy();
		return false;
	}

	if (not TryCreateRenderer())
	{
		Destroy();
		return false;
	}

	return true;
}

bool OpenGLWindow::TryInitialize(int width, int height, const char* title)
{
	if (glfwInit() != GLFW_TRUE)
		return false;
	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (m_window == nullptr)
	{
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_window);
	return true;
}

bool OpenGLWindow::TryCreateInput()
{
	return m_input = new OpenGLInput(m_window);
}

bool OpenGLWindow::TryCreateRenderer()
{
	m_renderer = new OpenGLRenderer();
	if (not dynamic_cast<IRendererCore*>(m_renderer)->TryInitialize())
	{
		delete m_renderer;
		return false;
	}
	return true;
}
