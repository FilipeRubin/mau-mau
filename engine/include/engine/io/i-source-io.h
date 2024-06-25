#pragma once
#include <string>

class ISourceIO
{
public:
	virtual ~ISourceIO() = default;
	virtual bool TryRead(std::string& result) = 0;
	virtual bool TryWrite(const std::string& content) = 0;
};
