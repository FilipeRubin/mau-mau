#pragma once
#include "engine/i-input.h"
#include "i-input-core.h"
#include <list>

class OpenGLInput : public IInput, public IInputCore
{
public:
	OpenGLInput(struct GLFWwindow* window);
	~OpenGLInput();
	bool IsKeyboardKeyJustPressed(KeyboardKey key) const override;
	bool IsKeyboardKeyJustReleased(KeyboardKey key) const override;
	bool IsKeyboardKeyPressed(KeyboardKey key) const override;
	bool IsMouseButtonJustPressed(MouseButton button) const override;
	bool IsMouseButtonJustReleased(MouseButton button) const override;
	bool IsMouseButtonPressed(MouseButton button) const override;
	void Process() override;
	void UpdateKeyboardKeyState(KeyboardKey key, bool isPressed) override;
	void UpdateMouseButtonState(MouseButton button, bool isPressed) override;
private:
	static std::list<OpenGLInput*> s_instances;
	bool m_keyboardKeysPressed[static_cast<int>(KeyboardKey::LAST) + 1];
	bool m_lastKeyboardKeysPressed[static_cast<int>(KeyboardKey::LAST) + 1];
	bool m_mouseButtonPressed[static_cast<int>(MouseButton::LAST) + 1];
	bool m_lastMouseButtonPressed[static_cast<int>(MouseButton::LAST) + 1];
	friend void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};