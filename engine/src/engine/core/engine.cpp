#include "engine/core/engine.h"
#include "../graphics/opengl-game-window.h"

Engine::Engine() :
	m_window(nullptr)
{
}

Engine::~Engine()
{
	DestroyWindow();
}

bool Engine::Load(const EngineConfiguration& config)
{
	CreateWindow(config.renderingAPI);

	if (m_window == nullptr)
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

void Engine::Start(const std::unique_ptr<Game>&& game)
{
	IGameWindowCore& window = *m_window;

	game->m_gameWindow = m_window;
	game->Start();
	while (window.ShouldContinueRunning())
	{
		game->Update(0.0f);
		window.Process();
	}

	window.Destroy();

	DestroyWindow();
}

void Engine::CreateWindow(const RenderingAPI& renderingAPI)
{
	if (m_window != nullptr)
	{
		DestroyWindow();
	}
	m_window = new OpenGLGameWindow();
}

void Engine::DestroyWindow()
{
	delete m_window;
	m_window = nullptr;
}
