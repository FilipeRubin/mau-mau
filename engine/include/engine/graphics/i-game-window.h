#pragma once
#include "engine/input/i-input.h"
#include "i-renderer.h"
#include <string>

class IGameWindow
{
public:
	virtual ~IGameWindow() = default;
	virtual IInput& GetInput() const = 0;
	virtual IRenderer& GetRenderer() const = 0;
};
