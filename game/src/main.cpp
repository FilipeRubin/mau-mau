#include <engine/graphics/opengl-game-window.h>

int main()
{
	IGameWindow* gameWindow = new OpenGLGameWindow();

	const bool windowCreatedSuccessfully = gameWindow->TryCreateWindow(800, 600, "Mau-Mau Online");

	if (windowCreatedSuccessfully)
	{
		gameWindow->GetRenderer()->SetBackgroundColor(0.5f, 0.3f, 0.1f, 1.0f);
		while (gameWindow->ShouldContinueRunning())
		{
			IInput& input = *gameWindow->GetInput();
			if (input.IsKeyboardKeyJustPressed(KeyboardKey::A))
			{
				gameWindow->GetRenderer()->SetBackgroundColor(0.1f, 0.8f, 0.4f, 1.0f);
			}
			if (input.IsKeyboardKeyJustPressed(KeyboardKey::D))
			{
				gameWindow->GetRenderer()->SetBackgroundColor(0.4f, 0.5f, 1.0f, 1.0f);
			}
			if (input.IsMouseButtonJustPressed(MouseButton::LEFT))
			{
				gameWindow->GetRenderer()->SetBackgroundColor(0.5f, 0.7f, 0.9f, 1.0f);
			}
			if (input.IsKeyboardKeyJustReleased(KeyboardKey::SPACE))
			{
				gameWindow->GetRenderer()->SetBackgroundColor(0.5f, 0.3f, 0.1f, 1.0f);
			}
			if (input.IsMouseButtonPressed(MouseButton::BUTTON_3))
			{
				gameWindow->GetRenderer()->SetBackgroundColor(0.5f, 0.5f, 0.6f, 1.0f);
			}
			gameWindow->GetRenderer()->ClearScreen();
			gameWindow->Process();
		}
		gameWindow->Destroy();
	}

	delete gameWindow;

	return 0;
}
