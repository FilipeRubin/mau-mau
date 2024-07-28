#pragma once
#include "engine/graphics/i-window.h"
#include "i-window-core.h"

class IWindowFull : public IWindow, public IWindowCore
{
public:
	virtual ~IWindowFull() = default;
};
