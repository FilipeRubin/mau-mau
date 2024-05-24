#pragma once
#include "engine/input/i-input.h"
#include "i-renderer.h"
#include <string>

class IGameWindow
{
public:
	virtual ~IGameWindow() = default;
	virtual void Destroy() = 0;
	virtual IInput& GetInput() const = 0;
	virtual IRenderer& GetRenderer() const = 0;
	virtual void Process() = 0;
	virtual bool ShouldContinueRunning() const = 0;
	virtual bool TryCreateWindow(int width, int height, const std::string& title) = 0;
};
