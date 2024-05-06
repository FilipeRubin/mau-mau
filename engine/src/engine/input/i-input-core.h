#pragma once
#include "engine/input/keyboard-key.h"
#include "engine/input/mouse-button.h"

class IInputCore
{
public:
	virtual ~IInputCore() = default;
	virtual void Process() = 0;
	virtual void UpdateKeyboardKeyState(KeyboardKey key, bool isPressed) = 0;
	virtual void UpdateMouseButtonState(MouseButton button, bool isPressed) = 0;
};
