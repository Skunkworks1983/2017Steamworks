/*
 * cFuelAgitator.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: s-2508366
 */

#include <Subsystems/cFuelAgitator.h>
#include <RobotMap.h>

cFuelAgitator::cFuelAgitator()
{
    // TODO Auto-generated constructor stub
    m_motor1 = new cMotor(FUELAGITATOR_MOTOR1_PORT, NeveRest40);
}

void cFuelAgitator::setSpeed(float speed)
{
    m_motor1->setOutput(speed);
}

cFuelAgitator::~cFuelAgitator()
{
    // TODO Auto-generated destructor stub
    delete m_motor1;
}

