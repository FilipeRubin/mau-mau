#pragma once
#include "i-game-window.h"

class OpenGLGameWindow : public IGameWindow
{
public:
	OpenGLGameWindow();
	~OpenGLGameWindow();
	void Destroy() override;
	IRenderer* GetRenderer() const override;
	void Process() override;
	bool ShouldContinueRunning() const override;
	bool TryCreateWindow(int width, int height, const std::string& title) override;
private:
	IRenderer* m_renderer;
	struct GLFWwindow* m_window;
};
