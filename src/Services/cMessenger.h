/*
 *  This file handles the Messenger system.
 *  We create a socket to talk to the raspberry pi to
 *  from the roborio.
 *
 *  here's how it works:
 *  on the creation of a new instance of a cmessenger,
 *  we create a new thread to listen on it's given port
 *  and ip, and give it the instance to write to.
 *
 *  Written by Nathan Tresham
 */

#ifndef MESSENGER_H
#define MESSENGER_H

#include <HAL/cpp/priority_mutex.h>
#include <iostream>
#include <sys/types.h>
#include <netdb.h>
#include <string>
#include <time.h>
#include <pthread.h>

#include <Services/cMessage.h>
#include <Services/Interfaces/iMessenger.h>

class cMessenger : public iMessenger
{
private:
    int m_sock;
    clock_t m_clock;

    bool m_dead;

    bool m_connected;

    sockaddr_in m_myaddr;
    sockaddr_in m_remaddr;

    cBoilerData* m_lastBoilerData;
    cLiftData* m_lastLiftData;

    pthread_t m_thread;
    priority_mutex* m_threadMutex;
    std::string receiveMessage();
public:
    cMessenger(const char* server, const char* port);
    ~cMessenger();

    static void* update(void* m);

    void sendMessage(std::string message);

    void kill();
    bool isDead();

    cBoilerData* receiveBoilerData();
    cLiftData* receiveLiftData();

    bool isNotTimedOut();
};

#endif
