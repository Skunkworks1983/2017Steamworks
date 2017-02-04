#include "cFuelIndexer.h"
#include <RobotMap.h>

cFuelIndexer::cFuelIndexer() :
        Subsystem("cFuelIndexer")
{
    m_motor1 = new cMotor(FUELINDEXER_MOTOR1_PORT);
}

cFuelIndexer::~cFuelIndexer()
{
    delete m_motor1;
}

void cFuelIndexer::InitDefaultCommand()
{

}

void cFuelIndexer::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}
