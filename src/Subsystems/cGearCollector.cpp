#include "cGearCollector.h"
#include <RobotMap.h>

cGearCollector::cGearCollector() : Subsystem("cGearCollector")
{
    motor1 = new cMotor(GEARCOLLECTOR_MOTOR1_PORT);
}

cGearCollector::~cGearCollector()
{
    delete motor1;
}

void cGearCollector::InitDefaultCommand() {

}

void cGearCollector::setSpeed(float speed)
{
    motor1->setOutput(speed);
}
