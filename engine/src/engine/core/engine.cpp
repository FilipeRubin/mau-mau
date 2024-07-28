#include "engine/core/engine.h"
#include "../graphics/opengl-window.h"

Engine::Engine() :
	m_window(nullptr)
{
}

Engine::~Engine()
{
	Unload();
}

bool Engine::TryLoad(const EngineConfiguration& config)
{
	if (not TryLoadAPI(config.renderingAPI))
	{
		return false;
	}

	if (not m_window->TryCreateWindow(800, 600, "Mau-Mau Engine Game"))
	{
		Unload();
		return false;
	}

	return true;
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
	Unload();
}

bool Engine::TryLoadAPI(const RenderingAPI& renderingAPI)
{
	if (m_window != nullptr) Unload();

	switch (renderingAPI)
	{
	case RenderingAPI::OPEN_GL:
		m_window = new OpenGLWindow();
		break;
	default:
		m_window = nullptr;
	}

	return m_window;
}

void Engine::Unload()
{
	delete m_window;
	m_window = nullptr;
}
