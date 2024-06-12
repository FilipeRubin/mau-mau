#pragma once
#include "engine-configuration.h"
#include "engine/scene/scene.h"
#include <memory>

class Engine
{
public:
	bool Load(const EngineConfiguration& config);
	void Start(const std::unique_ptr<Scene>& mainScene);
};
