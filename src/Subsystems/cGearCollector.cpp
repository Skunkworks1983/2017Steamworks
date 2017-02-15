#include "cGearCollector.h"
#include <RobotMap.h>

cGearCollector::cGearCollector()
{
    m_servo1 = new Servo(GEARCOLLECTOR_SERVO1_PORT);
}

cGearCollector::~cGearCollector()
{
    delete m_servo1;
}

void cGearCollector::InitDefaultCommand()
{

}

void cGearCollector::setServoAngle(float angle)
{
    m_servo1->SetAngle(angle);
}

float cGearCollector::getServoAngle()
{
    return m_servo1->GetAngle();
}

void cGearCollector::setFlapState(bool isOpen)
{
    m_servo1->SetAngle(isOpen ? GEARCOLLECTOR_OPEN_ANGLE : GEARCOLLECTOR_CLOSE_ANGLE);
}
