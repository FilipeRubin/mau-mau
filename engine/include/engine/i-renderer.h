#pragma once

class IRenderer
{
public:
	virtual ~IRenderer() = default;
	virtual void ClearScreen() const = 0;
	virtual void SetBackgroundColor(float r, float g, float b, float a) = 0;
};
