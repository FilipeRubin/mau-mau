#include <engine/graphics/opengl-game-window.h>

int main()
{
	IGameWindow* gameWindow = new OpenGLGameWindow();

	const bool windowCreatedSuccessfully = gameWindow->TryCreateWindow(800, 600, "Mau-Mau Online");

	if (windowCreatedSuccessfully)
	{
		gameWindow->GetRenderer().SetBackgroundColor(0.5f, 0.3f, 0.1f, 1.0f);

		MeshData meshData;

		meshData.vertices = 
		{
			{Vector3(-1.0f, -1.0f, 0.0f), Vector2(), Vector3(0.5f, 1.0f, 0.0f)},
			{Vector3( 1.0f, -1.0f, 0.0f), Vector2(), Vector3(0.0f, 0.5f, 1.0f)},
			{Vector3( 1.0f,  1.0f, 0.0f), Vector2(), Vector3(1.0f, 0.0f, 0.5f)},
			{Vector3(-1.0f,  1.0f, 0.0f), Vector2(), Vector3(0.0f, 1.0f, 0.5f)}
		};

		meshData.indices = { 0U, 1U, 2U, 0U, 2U, 3U };

		std::shared_ptr<MeshBase> mesh = gameWindow->GetRenderer().GetMeshRenderer().CreateMesh();
		mesh->LoadData(meshData);

		while (gameWindow->ShouldContinueRunning())
		{
			static float value = 0.0f;
			IInput& input = gameWindow->GetInput();
			mesh->transform.rotation.y = value;
			mesh->transform.position.x = sinf(value);
			mesh->transform.position.y = -cosf(value);
			mesh->transform.position.z = -4.5f - (cosf(value * 0.25f) * 2.0f);
			value += 0.01f;
			gameWindow->Process();
		}
		gameWindow->Destroy();
	}

	delete gameWindow;

	return 0;
}
