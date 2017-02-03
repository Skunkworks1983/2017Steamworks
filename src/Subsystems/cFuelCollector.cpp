#include "cFuelCollector.h"
#include <RobotMap.h>

cFuelCollector::cFuelCollector() : Subsystem("cFuelCollector")
{
    motor1 = new cMotor(FUELCOLLECTOR_MOTOR1_PORT);
}

cFuelCollector::~cFuelCollector()
{
    delete motor1;
}

void cFuelCollector::InitDefaultCommand() {

}

void cFuelCollector::setSpeed(float speed)
{
    motor1->setOutput(speed);
}
