#include "engine/core/game.h"

const IGameWindow& Game::GetGameWindow() const
{
	return *m_gameWindow;
}
