#include <iostream>
#include "logger.hpp"
#include "console_sink.hpp"
#include "file_sink.hpp"

int main()
{
    Logger &logger = Logger::instance();

    std::shared_ptr<LogSink> console_sink = std::make_shared<ConsoleSink>();
    logger.addSink(console_sink);

    std::shared_ptr<LogSink> file_sink = std::make_shared<FileSink>("../logs/app_log.txt");
    logger.addSink(file_sink);
    
    logger.log(LogLevel::DEBUG, "This is a DEBUG message.");
    logger.log(LogLevel::INFO, "This is an INFO message.");
    logger.log(LogLevel::WARNING, "This is a WARNING message.");
    logger.log(LogLevel::ERROR, "This is an ERROR message.");
    logger.log(LogLevel::CRITICAL, "This is a CRITICAL message.");
    logger.log(LogLevel::FATAL, "This is a FATAL message.");

    std::cout << "**************************" << std::endl;

    logger.setLogLevel(LogLevel::ERROR);
    logger.log(LogLevel::INFO, "This INFO message should not be logged.");
    logger.log(LogLevel::ERROR, "This ERROR message should be logged.");
    logger.setLogLevel(LogLevel::DEBUG);
    logger.log(LogLevel::DEBUG, "Now, DEBUG messages will be logged again.");
    return 0;
}