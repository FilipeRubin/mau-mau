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
	m_window = CreateWindow(config.renderingAPI);

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

void Engine::Start()
{
	IGameWindowCore& window = *m_window;

	while (window.ShouldContinueRunning())
	{
		window.Process();
	}

	window.Destroy();

	DestroyWindow();
}

void Engine::DestroyWindow()
{
	delete m_window;
	m_window = nullptr;
}

IGameWindowFull* Engine::CreateWindow(const RenderingAPI& renderingAPI)
{
	switch (renderingAPI)
	{
	case RenderingAPI::OPEN_GL:
		return new OpenGLGameWindow();
		break;
	default:
		return nullptr;
		break;
	}
}
