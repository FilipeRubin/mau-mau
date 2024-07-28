#pragma once
#include "engine/graphics/i-window.h"

class Game
{
public:
	virtual ~Game() = default;
protected:
	virtual const IWindow& GetGameWindow() const final;
private:
	friend class Engine;
	const IWindow* m_gameWindow;
	virtual void Start() = 0;
	virtual void Update(const float& deltaTime) = 0;
	void SetGameWindow(const IWindow* gameWindow);
};
