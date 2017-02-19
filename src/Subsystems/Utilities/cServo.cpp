/*
 * cServo.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: Nathan
 */

#include <Subsystems/Utilities/cServo.h>

cServo::cServo(int port)
{
    m_servo = new Servo(port);
}

cServo::~cServo()
{

}

void cServo::setAngle(float angle)
{
    m_servo->SetAngle(angle);
}

float cServo::getAngle()
{
    return m_servo->GetAngle();
}

void cServo::PIDWrite(double angle)
{
    setAngle(angle);
}

double cServo::PIDGet()
{
    return getAngle();
}
