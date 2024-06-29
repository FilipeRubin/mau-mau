#pragma once
#include "engine-configuration.h"
#include <memory>

class Engine
{
public:
	Engine();
	~Engine();
	bool Load(const EngineConfiguration& config);
	void Start();
private:
	class IGameWindowFull* m_window;
	void DestroyWindow();
	class IGameWindowFull* CreateWindow(const RenderingAPI& renderingAPI);
};
