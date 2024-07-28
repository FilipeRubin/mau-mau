#include "engine/core/game.h"

const IWindow& Game::GetGameWindow() const
{
	return *m_gameWindow;
}

void Game::SetGameWindow(const IWindow* gameWindow)
{
	m_gameWindow = gameWindow;
}
