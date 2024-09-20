#include "logger.hpp"

std::unique_ptr<Logger> Logger::m_instance = nullptr;
std::mutex Logger::m_mutex;

Logger::Logger() : m_currentLogLevel(LogLevel::DEBUG) {}

Logger &Logger::instance()
{
    if (m_instance == nullptr)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_instance == nullptr)
        {
            m_instance.reset(new Logger());
        }
    }
    return *m_instance;
}

void Logger::setLogLevel(LogLevel level)
{
    m_currentLogLevel = level;
}

void Logger::addSink(std::shared_ptr<LogSink> sink)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_sinks.push_back(sink);
}

void Logger::log(LogLevel level, std::string message)
{
    if (level >= m_currentLogLevel)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (const auto &sink : m_sinks)
        {
            sink->log(message);
        }
    }
}