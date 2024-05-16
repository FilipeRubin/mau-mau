#pragma once

class IMeshCore
{
public:
	virtual ~IMeshCore() = default;
	virtual void Draw() const = 0;
};
