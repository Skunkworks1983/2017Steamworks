#include <Services/cMessenger.h>
#include <Services/cLogger.h>
#include <CommandBase.h>
#include <Subsystems/cTurret.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <RobotMap.h>
#include <time.h>
#include <HAL/cpp/priority_mutex.h>

// Creates a new messenger instance
cMessenger::cMessenger(const char *server, const char *port)
{
    // multithreading
    m_threadMutex = new priority_mutex();
    m_thread = (pthread_t) NULL;

    // this is where it gets a little spooky
    // create a new thread for the messenger, and
    // give it a reference to 'this' so that it knows
    // which messenger it is. also give it update as a routine to run.
#if 0
    if(pthread_create(&m_thread, NULL, this->update, this))
    {
        LOG_INFO("failed to create messenger thread")
    }
#endif
    // Initialize the last known variables
    m_dead = false;
    m_lastBoilerData = new cBoilerData(0, 0, false);
    m_lastLiftData = new cLiftData(0, false);

    // bind to the udp socket
    if((m_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        std::cout << "failed to create socket, errno " << errno << "\n";
        return;
    }

    // create the configuration for our own host port
    memset((char *) &m_myaddr, 0, sizeof(m_myaddr));
    m_myaddr.sin_family = AF_INET;
    m_myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_myaddr.sin_port = htons(std::stoi(port));

    // settings for remote address
    memset((char *) &m_remaddr, 0, sizeof(m_remaddr));
    m_remaddr.sin_family = AF_INET;
    inet_pton(AF_INET, server, &(m_remaddr.sin_addr));
    m_remaddr.sin_port = htons(std::stoi(port));

    int bufLen = 100;
    if(setsockopt(m_sock, SOL_SOCKET, SO_RCVBUF, &bufLen, sizeof(int)) == -1)
    {
        std::cout << "Sock opt err" << "\n";
    }

    // bind to the socket
    if(bind(m_sock, (struct sockaddr *) &m_myaddr, sizeof(m_myaddr)) < 0)
    {
        std::cout << "failed to bind to socket, errno " << errno << "\n";
        return;
    }
}

cMessenger::~cMessenger()
{
    kill();

    delete m_lastBoilerData;
    delete m_lastLiftData;
}

// Sends a string through the socket
void cMessenger::sendMessage(std::string message)
{
    // Send a message to the socket using the connection settings obtained earlier
    if(sendto(m_sock, message.c_str(), message.length() + 1, 0, (struct sockaddr*) &m_remaddr, sizeof(m_remaddr)) == -1)
    {
//        std::cout << "sendto failed, error: " << errno << "\n";
    }
}

// Remember to delete return value
std::string cMessenger::receiveMessage()
{
    char message_buffer[MSG_LEN];
    memset(message_buffer, 0, MSG_LEN);

    // TODO; make messenger receive blocking

    if(recv(m_sock, message_buffer, MSG_LEN, 0) == -1)
    {
        if(errno != EAGAIN && errno != EWOULDBLOCK)
        {
//            std::cout << "recvfrom failed, error: " << errno << "\n";
            return "message failed";
        }
    }

    std::string message_converted(message_buffer);

    m_clock = message_buffer[0] == 0 ? m_clock : clock();

    return message_converted;
}

// get the last known position of the boiler
cBoilerData* cMessenger::receiveBoilerData()
{
    m_threadMutex->lock();

    // ugly. copy the data from m_lastBoilerData to a new value,
    // then return that value
    cBoilerData* lbdata = new cBoilerData(m_lastBoilerData->getX(), m_lastBoilerData->getY(),
            m_lastBoilerData->isFound());

    m_threadMutex->unlock();

    return lbdata;
}

// get the last known position of the lift
cLiftData* cMessenger::receiveLiftData()
{
    m_threadMutex->lock();

    // see: receiveBoilerData
    cLiftData* lldata = new cLiftData(m_lastLiftData->getX(), m_lastLiftData->isFound());

    m_threadMutex->unlock();

    return lldata;
}

// get whether or not we have timed out
// we have timed out if the do not receive
// a message in a certain amount of seconds, as
// declared in robotmap.
bool cMessenger::isNotTimedOut()
{
    return (((float) (clock() - m_clock)) / CLOCKS_PER_SEC) < MESSENGER_TIMEOUT_SECS;
}

// kill the messenger
void cMessenger::kill()
{
    m_dead = true;
}

// check if the messenger is dead
bool cMessenger::isDead()
{
    return m_dead;
}

// this is spooky.
// see: header file for explanation
void* cMessenger::update(void* m)
{
    cMessenger* messenger = (cMessenger*) m;

    while(!messenger->isDead())
    {
        std::string message = messenger->receiveMessage();

        if(message[0] != 0)
        {
            // lock
            messenger->m_threadMutex->lock();

            // parse data
            if(message[0] == std::to_string(BOILER_PI_ID)[0])
            {
                float x, y;
                bool found;

                // erase the id portion of the message, to remove the first space delimiter
                message.erase(0, 2);

                // find whether or not we can see the target
                found = message[0] == '1';
                message.erase(0, 2);

                // cut the first portion of characters from the first space to the second space
                // also check if there is an x value, by looking for a number
                // with a space directly after it
                if(message.find(" ") != std::string::npos)
                {
                    x = atof(message.substr(0, message.find(" ")).c_str());
                }
                else
                {
                    LOG_INFO("received incomplete message (x value)");
                    x = messenger->m_lastBoilerData->getX();
                }

                // erase the x portion of the message
                message.erase(0, message.find(" ") + 1);

                // get the y pos, check if there is a y value
                // we do this by checking if the string is empty, aka
                // there is no y value specified in the string
                if(message[0] != 0)
                {
                    y = atof(message.substr(0, message.length() + 1).c_str());
                }
                else
                {
                    LOG_INFO("received incomplete message (y value)");
                    y = messenger->m_lastBoilerData->getY();
                }

                // check if the member lastboilerdata exists. if it does, then we delete
                // it as to not cause any leaks & set it to null
                if(messenger->m_lastBoilerData != NULL)
                {
                    delete messenger->m_lastBoilerData;
                    messenger->m_lastBoilerData = NULL;
                }

                // edit the new member variable
                messenger->m_lastBoilerData = new cBoilerData(x, y, found);
            }
            else
            {
                if(message[0] == std::to_string(GEAR_PI_ID)[0])
                {
                    float x;
                    bool found;

                    // erase the id portion of the message, to remove the id and first space delimiter
                    message.erase(0, 2);

                    // find whether or not we can see the target
                    found = message[0] == '1';
                    message.erase(0, 2);

                    // cut the first portion of characters from the first space to the second space
                    if(message[0] != 0)
                    {
                        x = atof(message.substr(0, message.length() + 1).c_str());
                    }
                    else
                    {
                        LOG_INFO("received incomplete message (x value)");
                        x = messenger->m_lastLiftData->getX();
                    }

                    // check if the member lastliftdata exists. if it does, then we delete
                    // it as to not cause any leaks & set it to null
                    if(messenger->m_lastLiftData != NULL)
                    {
                        delete messenger->m_lastLiftData;
                        messenger->m_lastLiftData = NULL;
                    }

                    // edit the new member variable
                    messenger->m_lastLiftData = new cLiftData(x, found);
                }
            }

            // unlock
            messenger->m_threadMutex->unlock();
        }
    }

    pthread_exit(NULL);
    return NULL;
}
