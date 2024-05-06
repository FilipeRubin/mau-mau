#include "engine/opengl-game-window.h"
#include "i-input-core.h"
#include "opengl-input.h"
#include "opengl-renderer.h"
#include <GLFW/glfw3.h>

OpenGLGameWindow* OpenGLGameWindow::s_currentInstance = nullptr;

static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	IInputCore& input = *dynamic_cast<IInputCore*>(OpenGLGameWindow::GetCurrentInstance()->GetInput());
	input.UpdateKeyboardKeyState(static_cast<KeyboardKey>(key), action == GLFW_PRESS);
}

static void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	IInputCore& input = *dynamic_cast<IInputCore*>(OpenGLGameWindow::GetCurrentInstance()->GetInput());
	input.UpdateMouseButtonState(static_cast<MouseButton>(button), action == GLFW_PRESS);
}

OpenGLGameWindow* OpenGLGameWindow::GetCurrentInstance()
{
	return s_currentInstance;
}

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
	if (s_currentInstance == this)
		s_currentInstance = nullptr;
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

	m_input = new OpenGLInput();

	glfwSetKeyCallback(m_window, glfw_key_callback);

	m_renderer = new OpenGLRenderer();

	const bool rendererInitializedSuccessfully = dynamic_cast<IRendererCore*>(m_renderer)->TryInitialize();

	if (not rendererInitializedSuccessfully)
	{
		Destroy();
		return false;
	}

	s_currentInstance = this;

	return true;
}
