/*
 * This function controls the Message class.
 * To communicate with the raspberry pi, we send
 * Messages that contain the position of a vision target
 * in a string.
 */

#include <Services/cMessage.h>

cBoilerData::cBoilerData(float x, float y, bool isFound) :
        m_x(x), m_y(y), m_isFound(isFound)
{

}

float cBoilerData::getX()
{
    return m_x;
}

float cBoilerData::getY()
{
    return m_y;
}

bool cBoilerData::isFound() {
    return m_isFound;
}


cLiftData::cLiftData(float x, bool isFound) :
        m_x(x), m_isFound(isFound)
{

}

float cLiftData::getX()
{
    return m_x;
}

bool cLiftData::isFound() {
    return m_isFound;
}
