#include "engine/core/game.h"

IInput& Game::GetInput() const
{
    return *m_input;
}

IRenderer& Game::GetRenderer() const
{
    return *m_renderer;
}

IWindow& Game::GetWindow() const
{
    return *m_window;
}
