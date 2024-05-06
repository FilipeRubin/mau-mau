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
			if (gameWindow->GetInput()->IsKeyboardKeyJustPressed(KeyboardKey::A))
			{
				gameWindow->GetRenderer()->SetBackgroundColor(0.1f, 0.8f, 0.4f, 1.0f);
			}
			else if (gameWindow->GetInput()->IsKeyboardKeyJustPressed(KeyboardKey::D))
			{
				gameWindow->GetRenderer()->SetBackgroundColor(0.4f, 0.5f, 1.0f, 1.0f);
			}
			gameWindow->GetRenderer()->ClearScreen();
			gameWindow->Process();
		}
		gameWindow->Destroy();
	}

	delete gameWindow;

	return 0;
}
