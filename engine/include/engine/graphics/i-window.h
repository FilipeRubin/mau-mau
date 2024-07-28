#pragma once
#include "engine/input/i-input.h"
#include "i-renderer.h"
#include <string>

class IWindow
{
public:
	virtual ~IWindow() = default;
	virtual IInput& GetInput() const = 0;
	virtual IRenderer& GetRenderer() const = 0;
};
