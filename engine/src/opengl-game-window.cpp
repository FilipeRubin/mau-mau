#include "engine/opengl-game-window.h"
#include "opengl-renderer.h"
#include <GLFW/glfw3.h>

OpenGLGameWindow::OpenGLGameWindow() :
	m_window(nullptr),
	m_renderer(nullptr)
{
}

OpenGLGameWindow::~OpenGLGameWindow()
{
	Destroy(); // Just to make sure
}

void OpenGLGameWindow::Destroy()
{
	delete m_renderer;
	m_renderer = nullptr;
	glfwDestroyWindow(m_window);
	m_window = nullptr;
	glfwTerminate();
}

IRenderer* OpenGLGameWindow::GetRenderer() const
{
	return m_renderer;
}

void OpenGLGameWindow::Process()
{
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

	m_renderer = new OpenGLRenderer();

	const bool rendererInitializedSuccessfully = dynamic_cast<IRendererInitializer*>(m_renderer)->TryInitialize();

	if (not rendererInitializedSuccessfully)
	{
		Destroy();
		return false;
	}

	return true;
}
