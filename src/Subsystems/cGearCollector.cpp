#include "cGearCollector.h"
#include <RobotMap.h>

cGearCollector::cGearCollector() :
        Subsystem("cGearCollector")
{
    m_motor1 = new cMotor(GEARCOLLECTOR_MOTOR1_PORT);
}

cGearCollector::~cGearCollector()
{
    delete m_motor1;
}

void cGearCollector::InitDefaultCommand()
{

}

void cGearCollector::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}
