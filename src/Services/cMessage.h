#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class cBoilerData {
private:
    int m_x, m_y;

public:
    cBoilerData(int x, int y);

    int getX();
    int getY();
};


class cLiftData {
private:
    int m_x;

public:
    cLiftData(int x);

    int getX();
};

#endif
