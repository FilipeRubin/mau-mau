#include <engine/opengl-game-window.h>

int main()
{
	IGameWindow* gameWindow = new OpenGLGameWindow();

	const bool windowCreatedSuccessfully = gameWindow->TryCreateWindow(800, 600, "Mau-Mau Online");

	if (windowCreatedSuccessfully)
	{
		gameWindow->GetRenderer()->SetBackgroundColor(0.5f, 0.3f, 0.1f, 1.0f);
		while (gameWindow->ShouldContinueRunning())
		{
			gameWindow->GetRenderer()->ClearScreen();
			gameWindow->Process();
		}
		gameWindow->Destroy();
	}

	delete gameWindow;

	return 0;
}
