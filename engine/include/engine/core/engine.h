#pragma once
#include "engine-configuration.h"

class Engine
{
public:
	Engine();
	~Engine();
	bool Load(const EngineConfiguration& config);
	void Start();
private:
	class IGameWindowFull* m_window;
	void CreateWindow(const RenderingAPI& renderingAPI);
	void DestroyWindow();
};
