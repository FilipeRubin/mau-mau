#pragma once
#include "engine-configuration.h"
#include "engine/scene/scene-data.h"
#include <memory>

class Engine
{
public:
	Engine();
	~Engine();
	bool Load(const EngineConfiguration& config);
	void Start(const std::unique_ptr<SceneData>& mainScene);
private:
	class IGameWindowFull* m_window;
	void DestroyWindow();
	class IGameWindowFull* CreateWindow(const RenderingAPI& renderingAPI);
};
