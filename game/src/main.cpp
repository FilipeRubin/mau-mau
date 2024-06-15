#include <engine/core/engine.h>

int main()
{
	Engine engine = Engine();
	if (not engine.Load(EngineConfiguration()))
	{
		return -1;
	}

	engine.Start(std::make_unique<Scene>());
	return 0;
}
