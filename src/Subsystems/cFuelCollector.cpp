/*
 * cFuelCollector.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <Subsystems/cFuelCollector.h>
#include <RobotMap.h>

cFuelCollector::cFuelCollector() :
        Subsystem("cFuelCollector")
{
    // TODO Auto-generated constructor stub
    m_hopperMotor = new cMotor(FUELCOLLECTOR_MOTOR1_PORT, BaneBots775);
    m_collectorFlapServo = new Servo(FUELCOLLECTOR_MOTOR2_PORT);
}

void cFuelCollector::setCollectorFlapAngle(float angle)
{
    m_collectorFlapServo->SetAngle(angle);
}

void cFuelCollector::setHopperDrumSpeed(float speed)
{
    m_hopperMotor->setOutput(speed);
}

cFuelCollector::~cFuelCollector()
{
    // TODO Auto-generated destructor stub
    delete m_hopperMotor;
    delete m_collectorFlapServo;
}

