#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>


// this class holds information for the boiler data.
// we have two members: x & y which are the coordinates of
// boiler on screen, where -1 is the left side of the screen,
// 1 is the right side, and 0 is straight down the center.
class cBoilerData {
private:
    float m_x, m_y;

public:
    cBoilerData(float x, float y);

    float getX();
    float getY();
};

// same as boilerdata, except we only include an x value
class cLiftData {
private:
    float m_x;

public:
    cLiftData(float x);

    float getX();
};

#endif
