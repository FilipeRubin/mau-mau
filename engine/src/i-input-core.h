#pragma once
#include "engine/keyboard-key.h"
#include "engine/mouse-button.h"

class IInputCore
{
public:
	virtual ~IInputCore() = default;
	virtual void Process() = 0;
	virtual void UpdateKeyboardKeyState(KeyboardKey key, bool isPressed) = 0;
	virtual void UpdateMouseButtonState(MouseButton button, bool isPressed) = 0;
};
