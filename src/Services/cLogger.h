#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class cLogger
{
private:

public:
    cLogger();
    ~cLogger();

    void Log(std::string message);
    void Log_Debug(std::string message);
    void Log_Warning(std::string message);
    void Log_Fatal(std::string message);
};

#endif
