#pragma once
#include "engine/graphics/i-game-window.h"
#include "i-game-window-core.h"

class IGameWindowFull : public IGameWindow, public IGameWindowCore
{
public:
	virtual ~IGameWindowFull() = default;
};
