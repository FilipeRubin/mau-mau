#pragma once
#include "engine/i-input.h"
#include "i-input-core.h"

class OpenGLInput : public IInput, public IInputCore
{
public:
	OpenGLInput();
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
	bool m_keyboardKeysPressed[static_cast<int>(KeyboardKey::LAST) + 1];
	bool m_lastKeyboardKeysPressed[static_cast<int>(KeyboardKey::LAST) + 1];
	bool m_mouseButtonPressed[static_cast<int>(MouseButton::LAST) + 1];
	bool m_lastMouseButtonPressed[static_cast<int>(MouseButton::LAST) + 1];
};