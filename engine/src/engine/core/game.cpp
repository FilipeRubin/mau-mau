#include "engine/core/game.h"

const IGameWindow& Game::GetGameWindow() const
{
	return *m_gameWindow;
}

void Game::SetGameWindow(const IGameWindow* gameWindow)
{
	m_gameWindow = gameWindow;
}
