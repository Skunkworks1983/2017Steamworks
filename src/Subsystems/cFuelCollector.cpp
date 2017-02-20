/*
 * cFuelCollector.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <Subsystems/cFuelCollector.h>
#include <RobotMap.h>

cFuelCollector::cFuelCollector()
{
    m_hopperMotor = new cMotor(FUELCOLLECTOR_MOTOR1_PORT, BaneBots775, true);
}

void cFuelCollector::setFlapAngle(float angle)
{

}

void cFuelCollector::setHopperDrumSpeed(float speed)
{
    m_hopperMotor->setOutput(speed);
}

cFuelCollector::~cFuelCollector()
{
    // TODO Auto-generated destructor stub
    delete m_hopperMotor;
}

cMotor* cFuelCollector::getCollectorMotor() {
	return m_hopperMotor;
}
