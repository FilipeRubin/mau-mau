#include "engine/io/file-source-io.h"
#include <sstream>

FileSourceIO::FileSourceIO() :
    m_fileStream()
{
}

FileSourceIO::FileSourceIO(const std::string& fileName) :
    m_fileStream(fileName, std::ios::in | std::ios::out)
{
}

FileSourceIO::~FileSourceIO()
{
    m_fileStream.close();
}

void FileSourceIO::Close()
{
    m_fileStream.close();
}

void FileSourceIO::Open(const std::string& fileName)
{
    if (m_fileStream.is_open())
        m_fileStream.close();
    m_fileStream.open(fileName, std::ios::in | std::ios::out);
}

bool FileSourceIO::TryRead(std::string& result)
{
    if (not m_fileStream.is_open())
    {
        return false;
    }

    result.clear();

    m_fileStream.clear();
    m_fileStream.seekg(0, std::ios::beg);

    std::string line;
    while (std::getline(m_fileStream, line))
    {
        result += (line + '\n');
    }

    return true;
}

bool FileSourceIO::TryWrite(const std::string& content)
{
    if (not m_fileStream.is_open())
    {
        return false;
    }

    m_fileStream << content;

    return true;
}
