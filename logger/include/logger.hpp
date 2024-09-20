#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <memory>
#include <mutex>
#include <vector>
#include "log_sink.hpp"

// Handle export/import for cross-platform shared librariesis

#if defined(_WIN32) || defined(_WIN64)
    #ifdef LOGGER_FUNCTIONS_EXPORTS
        #define LOGGER_API __declspec(dllexport)
    #else
        #define LOGGER_API __declspec(dllimport)
    #endif
#elif defined(__linux__) || defined(__APPLE__)
    #ifdef LOGGER_FUNCTIONS_EXPORTS
        #define LOGGER_API __attribute__((visibility("default")))
    #else
        #define LOGGER_API
    #endif
#else
    #define LOGGER_API
#endif

enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    FATAL
};

class Logger
{
public:
    LOGGER_API static Logger &instance();

    LOGGER_API void setLogLevel(LogLevel level);

    LOGGER_API void log(LogLevel level, std::string message);

    LOGGER_API void addSink(std::shared_ptr<LogSink> sink);

private:
    Logger();
    Logger(const Logger &other) = delete;
    Logger(Logger &&other) = delete;
    Logger &operator=(const Logger &other) = delete;
    Logger &operator=(Logger &&other) = delete;

    LogLevel m_currentLogLevel;

    std::vector<std::shared_ptr<LogSink>> m_sinks; 

    static std::unique_ptr<Logger> m_instance;
    static std::mutex m_mutex;
};

#endif //LOGGER_H