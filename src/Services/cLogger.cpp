/*
 * This file interfaces the robot code to the log4cxx.
 * We do this by creating a log on the roborio and then
 * outputting messages to it (message, message type [warn, debug, etc])
 * ez $$
 * Written by Nathan Tresham
 */

#include <Services/cLogger.h>

// Create a new logger instance
cLogger::cLogger()
{

}

cLogger::~cLogger()
{

}

// Log a general message to the log
void cLogger::Log(std::string message)
{

}

// Log a debug message to the log
void cLogger::Log_Debug(std::string message)
{

}

// Log a warning message to the log
void cLogger::Log_Warning(std::string message)
{

}

// Log a fatal message to the log
void cLogger::Log_Fatal(std::string message)
{

}
