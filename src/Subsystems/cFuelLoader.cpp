/*
 * cFuelLoader.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <Subsystems/cFuelLoader.h>
#include <RobotMap.h>

cFuelLoader::cFuelLoader()
{
    // TODO Auto-generated constructor stub
    m_motor1 = new cMotor(FUELLOADER_MOTOR1_PORT, BaneBots775);
}

void cFuelLoader::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}

cFuelLoader::~cFuelLoader()
{
    // TODO Auto-generated destructor stub
    delete m_motor1;
}

