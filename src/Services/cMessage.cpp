/*
 * This function controls the Message class.
 * To communicate with the raspberry pi, we send
 * Messages that contain the position of a vision target
 * in a string.
 */

#include <Services/cMessage.h>

cBoilerData::cBoilerData(float x, float y) : m_x(x), m_y(y) {

}


float cBoilerData::getX() {
    return m_x;
}


float cBoilerData::getY() {
    return m_y;
}



cLiftData::cLiftData(float x) : m_x(x) {

}


float cLiftData::getX() {
    return m_x;
}


