#pragma once
#include <string>
#include "engine/graphics/i-game-window.h"

class IGameWindowCore : public IGameWindow
{
public:
	virtual ~IGameWindowCore() = default;
	virtual void Destroy() = 0;
	virtual void Process() = 0;
	virtual bool ShouldContinueRunning() const = 0;
	virtual bool TryCreateWindow(int width, int height, const std::string& title) = 0;
};