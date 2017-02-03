#include "cFuelIndexer.h"
#include <RobotMap.h>

cFuelIndexer::cFuelIndexer() : Subsystem("cFuelIndexer")
{
    motor1 = new cMotor(FUELINDEXER_MOTOR1_PORT);
}

cFuelIndexer::~cFuelIndexer()
{
    delete motor1;
}

void cFuelIndexer::InitDefaultCommand() {

}

void cFuelIndexer::setSpeed(float speed)
{
    motor1->setOutput(speed);
}
