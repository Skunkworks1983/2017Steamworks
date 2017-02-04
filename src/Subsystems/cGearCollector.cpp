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


void cGearCollector::setServoAngle(float angle) {
    m_servo1->SetAngle(angle);
}
