#pragma once
#include "i-game-window.h"

class OpenGLGameWindow : public IGameWindow
{
public:
	OpenGLGameWindow();
	~OpenGLGameWindow();
	void Destroy() override;
	IInput& GetInput() const override;
	IRenderer& GetRenderer() const override;
	void Process() override;
	bool ShouldContinueRunning() const override;
	bool TryCreateWindow(int width, int height, const std::string& title) override;
private:
	IInput* m_input;
	IRenderer* m_renderer;
	struct GLFWwindow* m_window;
};
