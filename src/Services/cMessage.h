#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class cBoilerData {
private:
    float m_x, m_y;

public:
    cBoilerData(float x, float y);

    float getX();
    float getY();
};


class cLiftData {
private:
    float m_x;

public:
    cLiftData(float x);

    float getX();
};

#endif
