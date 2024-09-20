#ifndef LOGSINK_HPP
#define LOGSINK_HPP

#include <string>

class LogSink
{
public:
    virtual void log(const std::string &message) = 0;
    ~LogSink() = default;
};

#endif // LOGSINK_HPP