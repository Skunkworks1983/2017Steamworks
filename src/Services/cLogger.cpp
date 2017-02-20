#include <HAL/cpp/priority_mutex.h>
#include <RobotMap.h>
#include <Services/cLogger.h>
#include <unistd.h>
#include <cstdint>
#include <fstream>
#include <iostream>

Logger::Logger()
{
    threadMutex = new priority_mutex();
    logging = (pthread_t) NULL;
    int rc = pthread_create(&logging, NULL, write, this);
    if(rc)
    {
        LOG_INFO("Logger failed to create thread");
    }

    std::ifstream baseTest("/U/robotLog");
    if(!baseTest.good())
    {
        std::system("touch /U/robotLog");
    }

    std::string logPre = "/U/robotLog";
    int doesItExist = 1;
    bool found = false;
    int i = 0;
    while(!found)
    {
        std::ifstream robotLog(logPre + "." + std::to_string(i));
        doesItExist = robotLog.peek();
        if(doesItExist == -1)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    char command[1024];
    sprintf(command, "mv %s %s.%d", logPre.c_str(), logPre.c_str(), i);
    std::system(command);
}

Logger * Logger::getLogger()
{
    static Logger * instance = NULL;
    if(instance == NULL)
    {
        instance = new Logger();
    }
    return instance;
}

void Logger::push_message(LogMessage message)
{
    threadMutex->lock();
    messages.push(message);
    threadMutex->unlock();
}

bool Logger::is_empty()
{
    bool isEmpty;
    threadMutex->lock();
    isEmpty = messages.empty();
    threadMutex->unlock();
    return isEmpty;
}

LogMessage Logger::pull_message()
{
    LogMessage tmp;
    threadMutex->lock();
    tmp = messages.front();
    messages.pop();
    threadMutex->unlock();
    return tmp;
}

void Logger::log(std::string message, ELogLevel logLevel)
{
    LogMessage messageObj;
    messageObj.message.assign(message);
    messageObj.level = logLevel;
    struct timeval rawtime;
    gettimeofday(&rawtime, NULL);
    messageObj.time = rawtime;

    push_message(messageObj);
}

void *Logger::write(void * d)
{
    Logger * logger = (Logger*) d;
    while(!logger->loggerDied)
    {
        std::ofstream logFile;
        logFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            std::string logfileName = LOGFILE_NAME;
            logFile.open(logfileName.c_str(), std::ios::app);

            while(!logger->is_empty())
            {
                LogMessage message = logger->pull_message();
                uint64_t timestamp = (message.time.tv_sec * 1000) + (message.time.tv_usec / 1000);

                logFile << "[" << timestamp << "] " << ((const char*) ROBOT_NAME) << " " << ELogLevelStrings[message.level] << " " << message.message
                        << std::endl; //Write to log file
            }

            logFile.close();
        }
        catch(...)
        {
            logger->loggerDied = true;
        } //Not sure what the exact error is, but will not die when no flashdrive
        usleep(100);
    }
    return NULL;
}
