#pragma once
#include "engine-configuration.h"
#include "game.h"
#include <memory>

class Engine
{
public:
	Engine();
	~Engine();
	bool TryLoad(const EngineConfiguration& config);
	void Start(const std::unique_ptr<Game>&& game);
private:
	class IGameWindowFull* m_window;
	bool TryCreateWindow(const RenderingAPI& renderingAPI);
	void DestroyWindow();
};
