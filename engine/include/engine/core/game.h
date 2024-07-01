#pragma once
#include "engine/graphics/i-game-window.h"

class Game
{
public:
	virtual ~Game() = default;
protected:
	const IGameWindow& GetGameWindow() const;
private:
	friend class Engine;
	const IGameWindow* m_gameWindow;
	virtual void Start() = 0;
	virtual void Update(const float& deltaTime) = 0;
};
