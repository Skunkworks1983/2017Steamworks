#include "cGearCollector.h"
#include <RobotMap.h>

cGearCollector::cGearCollector() :
        Subsystem("cGearCollector")
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

void cGearCollector::setState(bool state)
{
    m_servo1->SetAngle(state ? GEARCOLLECTOR_OPEN_ANGLE : GEARCOLLECTOR_CLOSE_ANGLE);
}
