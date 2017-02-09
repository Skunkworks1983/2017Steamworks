#include "cFuelCollector.h"
#include <RobotMap.h>

cFuelCollector::cFuelCollector() :
        Subsystem("cFuelCollector")
{
    m_motor1 = new cMotor(FUELCOLLECTOR_MOTOR1_PORT, BaneBots775);
}

cFuelCollector::~cFuelCollector()
{
    delete m_motor1;
}

void cFuelCollector::InitDefaultCommand()
{

}

void cFuelCollector::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}
