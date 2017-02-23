/*
 * cFuelConveyor.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Nathan
 */

#include <Subsystems/cFuelConveyor.h>
#include <RobotMap.h>

cFuelConveyor::cFuelConveyor()
{
    m_motor1 = new cMotor(FUELCONVEYOR_MOTOR1_PORT, BaneBots775);
}

void cFuelConveyor::setSpeed(float speed)
{
    m_motor1->setOutput(-1*speed);
}

cFuelConveyor::~cFuelConveyor()
{
    delete m_motor1;
}

