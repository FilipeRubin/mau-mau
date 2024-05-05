#include "engine/opengl-game-window.h"
#include <GLFW/glfw3.h>

OpenGLGameWindow::OpenGLGameWindow() :
	m_window(nullptr)
{
}

OpenGLGameWindow::~OpenGLGameWindow()
{
	Destroy(); // Just to make sure
}

void OpenGLGameWindow::Destroy()
{
	glfwDestroyWindow(m_window);
	m_window = nullptr;
	glfwTerminate();
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

	return true;
}
