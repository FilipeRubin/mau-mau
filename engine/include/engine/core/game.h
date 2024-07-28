#pragma once
#include "engine/graphics/i-window.h"

class Game
{
public:
	virtual ~Game() = default;
protected:
	virtual void Start() = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual IInput& GetInput() const final;
	virtual IRenderer& GetRenderer() const final;
	virtual IWindow& GetWindow() const final;
private:
	friend class Engine;
	IInput* m_input;
	IRenderer* m_renderer;
	IWindow* m_window;
};
