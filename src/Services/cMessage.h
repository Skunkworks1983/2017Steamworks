#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

// this class holds information for the boiler data.
// we have two members: x & y which are the coordinates of
// boiler on screen, where -1 is the left side of the screen,
// 1 is the right side, and 0 is straight down the center.
class cBoilerData
{
private:
    bool m_isFound;
    bool m_isFresh;
    float m_x;
    float m_y;

public:
    cBoilerData(float x, float y, bool isFound);

    float getX();
    float getY();
    bool isFound();
    bool isFresh(); //freshhhhhh :>
    void setFresh(bool state);
};

// same as boilerdata, except we only include an x value
class cLiftData
{
private:
    bool m_isFound;
    bool m_isFresh;
    float m_x;

public:
    cLiftData(float x, bool isFound);

    float getX();
    bool isFound();
    bool isFresh();
    void setFresh(bool state);
};

#endif
