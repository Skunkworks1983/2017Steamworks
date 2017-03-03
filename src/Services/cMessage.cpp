/*
 * This function controls the Message class.
 * To communicate with the raspberry pi, we send
 * Messages that contain the position of a vision target
 * in a string.
 */

#include <Services/cMessage.h>

cBoilerData::cBoilerData(float x, float y, bool isFound) :
    m_isFound(isFound), m_isFresh(true), m_x(x), m_y(y)
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

bool cBoilerData::isFound()
{
    return m_isFound;
}

bool cBoilerData::isFresh()
{
    return m_isFresh;
}

void cBoilerData::setFresh(bool state)
{
    m_isFresh = state;
}



cLiftData::cLiftData(float x, bool isFound) :
        m_isFound(isFound), m_isFresh(true), m_x(x)
{
    m_isFresh = true;
}

float cLiftData::getX()
{
    return m_x;
}

bool cLiftData::isFound()
{
    return m_isFound;
}

bool cLiftData::isFresh()
{
    return m_isFresh;
}

void cLiftData::setFresh(bool state)
{
    m_isFresh = state;
}
