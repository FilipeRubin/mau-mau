#include "engine/graphics/opengl-game-window.h"
#include "../input/opengl-input.h"
#include "opengl-renderer.h"
#include <GLFW/glfw3.h>

OpenGLGameWindow::OpenGLGameWindow() :
	m_input(nullptr),
	m_renderer(nullptr),
	m_window(nullptr)
{
}

OpenGLGameWindow::~OpenGLGameWindow()
{
	Destroy(); // Just to make sure
}

void OpenGLGameWindow::Destroy()
{
	delete m_input;
	delete m_renderer;
	m_renderer = nullptr;
	glfwDestroyWindow(m_window);
	m_window = nullptr;
	glfwTerminate();
}

IInput* OpenGLGameWindow::GetInput() const
{
	return m_input;
}

IRenderer* OpenGLGameWindow::GetRenderer() const
{
	return m_renderer;
}

void OpenGLGameWindow::Process()
{
	dynamic_cast<IInputCore*>(m_input)->Process();
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

bool OpenGLGameWindow::ShouldContinueRunning() const
{
	return !glfwWindowShouldClose(m_window);
}

bool OpenGLGameWindow::TryCreateWindow(int width, int height, const std::string& title)
{
	if (glfwInit() != GLFW_TRUE)
		return false;
	m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (m_window == nullptr)
	{
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_window);

	m_input = new OpenGLInput(m_window);
	m_renderer = new OpenGLRenderer();

	const bool rendererInitializedSuccessfully = dynamic_cast<IRendererCore*>(m_renderer)->TryInitialize();

	if (not rendererInitializedSuccessfully)
	{
		Destroy();
		return false;
	}

	return true;
}
