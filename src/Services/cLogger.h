#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <log4cxx/log4cxx.h>
#include <log4cxx/logger.h>

class cLogger
{
private:
    log4cxx::LoggerPtr logger;

public:
    cLogger();
    ~cLogger();

    void Log(std::string message);
    void Log_Debug(std::string message);
    void Log_Warning(std::string message);
    void Log_Fatal(std::string message);
};

#endif
