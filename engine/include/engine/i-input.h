#pragma once
#include "keyboard-key.h"
#include "mouse-button.h"

class IInput
{
public:
	virtual ~IInput() = default;
	virtual bool IsKeyboardKeyJustPressed(KeyboardKey key) const = 0;
	virtual bool IsKeyboardKeyJustReleased(KeyboardKey key) const = 0;
	virtual bool IsKeyboardKeyPressed(KeyboardKey key) const = 0;
	virtual bool IsMouseButtonJustPressed(MouseButton button) const = 0;
	virtual bool IsMouseButtonJustReleased(MouseButton button) const = 0;
	virtual bool IsMouseButtonPressed(MouseButton button) const = 0;
};
