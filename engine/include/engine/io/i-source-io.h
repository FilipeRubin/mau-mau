#pragma once
#include <string>

class ISourceIO
{
public:
	virtual ~ISourceIO() = default;
	virtual std::string Read() = 0;
	virtual void Write(const std::string& content) = 0;
};
