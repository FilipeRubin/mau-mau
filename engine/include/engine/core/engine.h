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
	class IWindowFull* m_window;
	bool TryLoadAPI(const RenderingAPI& renderingAPI);
	void Unload();
};
