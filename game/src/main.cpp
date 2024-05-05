#include <engine/opengl-game-window.h>

int main()
{
	IGameWindow* gameWindow = new OpenGLGameWindow();

	const bool windowCreatedSuccessfully = gameWindow->TryCreateWindow(800, 600, "Mau-Mau Online");

	if (windowCreatedSuccessfully)
	{
		while (gameWindow->ShouldContinueRunning())
		{
			gameWindow->Process();
		}
		gameWindow->Destroy();
	}

	delete gameWindow;

	return 0;
}