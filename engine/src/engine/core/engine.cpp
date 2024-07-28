#include "engine/core/engine.h"
#include "../graphics/opengl-window.h"

Engine::Engine() :
	m_window(nullptr)
{
}

Engine::~Engine()
{
	DestroyWindow();
}

bool Engine::TryLoad(const EngineConfiguration& config)
{
	return TryCreateWindow(config.renderingAPI);
}

void Engine::Start(const std::unique_ptr<Game>&& game)
{
	game->SetGameWindow(m_window);
	game->Start();

	while (m_window->ShouldContinueRunning())
	{
		game->Update(0.0f);
		m_window->Process();
	}

	m_window->Destroy();
	DestroyWindow();
}

bool Engine::TryCreateWindow(const RenderingAPI& renderingAPI)
{
	if (m_window != nullptr)
	{
		DestroyWindow();
	}
	m_window = new OpenGLWindow();

	if (not m_window)
	{
		return false;
	}

	if (not m_window->TryCreateWindow(800, 600, "Mau-Mau Engine Game"))
	{
		DestroyWindow();
		return false;
	}

	return true;
}

void Engine::DestroyWindow()
{
	delete m_window;
	m_window = nullptr;
}
