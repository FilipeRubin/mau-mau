#pragma once
#include "i-source-io.h"
#include <fstream>

class FileSourceIO : public ISourceIO
{
public:
	FileSourceIO();
	FileSourceIO(const std::string& fileName);
	~FileSourceIO();
	void Open(const std::string& fileName);
	bool TryRead(std::string& result) override;
	bool TryWrite(const std::string& content) override;
private:
	std::fstream m_fileStream;
};
