#pragma once
#include "engine/graphics/i-game-window.h"

class Game
{
public:
	virtual ~Game() = default;
protected:
	virtual const IGameWindow& GetGameWindow() const final;
private:
	friend class Engine;
	const IGameWindow* m_gameWindow;
	virtual void Start() = 0;
	virtual void Update(const float& deltaTime) = 0;
	void SetGameWindow(const IGameWindow* gameWindow);
};
