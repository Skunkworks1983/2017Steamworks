#pragma once
#ifndef SRC_SERVICES_CLOGGER_H_
#define SRC_SERVICES_CLOGGER_H_

#include <pthread.h>
#include <cstdbool>
#include <queue>
#include <string>
#include <sys/time.h>

class priority_mutex;

enum ELogLevel {
	LogDebug,
	LogInfo,
	LogWarning,
	LogError,
	LogRecord
};

const std::string ELogLevelStrings[5] = {"LogDebug", "LogInfo", "LogWarning", "LogError", "LogRecord"};

struct LogMessage {
	ELogLevel level;
	std::string message;
	struct timeval time;
};

class Logger {
public:
	static Logger * getLogger();

	bool       		is_empty();
	void       		log(std::string message, ELogLevel logLevel); //"Store" to static messages (blocking)
	bool       		loggerDied;
	LogMessage 		pull_message();
	void       		push_message(LogMessage message);

private:
	Logger();
	static void * write(void * d); //Write to log file (threaded, non-blocking)
	pthread_t logging;

	priority_mutex * threadMutex;

	std::queue<LogMessage> messages;
};

#endif /* SRC_SERVICES_CLOGGER_H_ */
