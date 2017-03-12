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
    window = new cMotor(9, NeveRest40);
}

void cFuelConveyor::setSpeed(float speed)
{
    m_motor1->setOutput(-1*speed);
    window->setOutput(speed);
}

cFuelConveyor::~cFuelConveyor()
{
    delete m_motor1;
}

