#ifndef FILE_SINK_HPP
#define FILE_SINK_HPP

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include "log_sink.hpp"

class FileSink : public LogSink
{
public:
    FileSink(const std::string &filePath)
    {
        std::filesystem::path path(filePath);
        auto parentPath = path.parent_path();
        if (!std::filesystem::exists(parentPath))
        {
            std::filesystem::create_directories(parentPath);
        }

        m_fileStream.open(filePath, std::ios::app);
        if (!m_fileStream.is_open())
        {
            throw std::runtime_error("Could not open log file: " + filePath);
        }
    }

    void log(const std::string &message) override
    {
        m_fileStream << message << std::endl;
    }

    ~FileSink()
    {
        if (m_fileStream.is_open())
        {
            m_fileStream.close();
        }
    }

private:
    std::ofstream m_fileStream;
};

#endif // FILE_SINK_HPP