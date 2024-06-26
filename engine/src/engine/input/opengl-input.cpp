#include "opengl-input.h"
#include <GLFW/glfw3.h>
#include <string>

std::list<OpenGLInput*> OpenGLInput::s_instances = std::list<OpenGLInput*>();

static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    for (IInputCore* input : OpenGLInput::s_instances)
    {
        input->UpdateKeyboardKeyState(static_cast<KeyboardKey>(key), action == GLFW_PRESS);
    }
}

static void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    for (IInputCore* input : OpenGLInput::s_instances)
    {
        input->UpdateMouseButtonState(static_cast<MouseButton>(button), action == GLFW_PRESS);
    }
}

OpenGLInput::OpenGLInput(struct GLFWwindow* window)
{
    std::memset(m_keyboardKeysPressed, false, sizeof(m_keyboardKeysPressed));
    std::memset(m_lastKeyboardKeysPressed, false, sizeof(m_lastKeyboardKeysPressed));
    std::memset(m_mouseButtonPressed, false, sizeof(m_mouseButtonPressed));
    std::memset(m_lastMouseButtonPressed, false, sizeof(m_lastMouseButtonPressed));
    s_instances.emplace_back(this);
    glfwSetKeyCallback(window, glfw_key_callback);
    glfwSetMouseButtonCallback(window, glfw_mouse_button_callback);
}

OpenGLInput::~OpenGLInput()
{
    s_instances.remove(this);
}

bool OpenGLInput::IsKeyboardKeyJustPressed(KeyboardKey key) const
{
    return m_keyboardKeysPressed[static_cast<int>(key)] and not m_lastKeyboardKeysPressed[static_cast<int>(key)];
}

bool OpenGLInput::IsKeyboardKeyJustReleased(KeyboardKey key) const
{
    return not m_keyboardKeysPressed[static_cast<int>(key)] and m_lastKeyboardKeysPressed[static_cast<int>(key)];
}

bool OpenGLInput::IsKeyboardKeyPressed(KeyboardKey key) const
{
    return m_keyboardKeysPressed[static_cast<int>(key)];
}

bool OpenGLInput::IsMouseButtonJustPressed(MouseButton button) const
{
    return m_mouseButtonPressed[static_cast<int>(button)] and not m_lastMouseButtonPressed[static_cast<int>(button)];
}

bool OpenGLInput::IsMouseButtonJustReleased(MouseButton button) const
{
    return not m_mouseButtonPressed[static_cast<int>(button)] and m_lastMouseButtonPressed[static_cast<int>(button)];
}

bool OpenGLInput::IsMouseButtonPressed(MouseButton button) const
{
    return m_mouseButtonPressed[static_cast<int>(button)];
}

void OpenGLInput::Process()
{
    const size_t keyboardKeysLength = sizeof(m_keyboardKeysPressed) / sizeof(m_keyboardKeysPressed[0]);
    const size_t mouseButtonsLength = sizeof(m_mouseButtonPressed) / sizeof(m_lastMouseButtonPressed[0]);

    std::copy(m_keyboardKeysPressed, m_keyboardKeysPressed + keyboardKeysLength, m_lastKeyboardKeysPressed);
    std::copy(m_mouseButtonPressed, m_mouseButtonPressed + mouseButtonsLength, m_lastMouseButtonPressed);
}

void OpenGLInput::UpdateKeyboardKeyState(KeyboardKey key, bool isPressed)
{
    m_keyboardKeysPressed[static_cast<int>(key)] = isPressed;
}

void OpenGLInput::UpdateMouseButtonState(MouseButton button, bool isPressed)
{
    m_mouseButtonPressed[static_cast<int>(button)] = isPressed;
}
