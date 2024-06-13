#pragma once
#include <string>

class IGameWindowCore
{
public:
	virtual ~IGameWindowCore() = default;
	virtual void Destroy() = 0;
	virtual void Process() = 0;
	virtual bool ShouldContinueRunning() const = 0;
	virtual bool TryCreateWindow(int width, int height, const std::string& title) = 0;
};