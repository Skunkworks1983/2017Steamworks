/*
 * This function controls the Message class.
 * To communicate with the raspberry pi, we send
 * Messages that contain the position of a vision target
 * in a string.
 */

#include <Services/cMessage.h>

cBoilerData::cBoilerData(int x, int y) : m_x(x), m_y(y) {

}


int cBoilerData::getX() {
    return m_x;
}


int cBoilerData::getY() {
    return m_y;
}



cLiftData::cLiftData(int x) : m_x(x) {

}


int cLiftData::getX() {
    return m_x;
}


