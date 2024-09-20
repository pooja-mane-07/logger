#ifndef CONSOLE_SINK_HPP
#define CONSOLE_SINK_HPP

#include <iostream>
#include "log_sink.hpp"

class ConsoleSink : public LogSink
{
public:
    void log(const std::string &message) override
    {
        std::cout << message << std::endl;
    }
};

#endif // CONSOLE_SINK_HPP