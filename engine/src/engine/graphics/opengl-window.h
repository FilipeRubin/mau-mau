#pragma once
#include "i-window-full.h"

class OpenGLWindow : public IWindowFull
{
public:
	OpenGLWindow();
	~OpenGLWindow();
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
