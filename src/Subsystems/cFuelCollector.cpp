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
    m_collectorMotor = new cMotor(FUELCOLLECTOR_COLLECTOR_PORT, BaneBots775);
    m_angleMotor = new cMotor(FUELCOLLECTOR_ANGLE_PORT, BaneBots775, true);

    m_p = 0;
    m_i = 0;
    m_d = 0;

    m_controller = new PIDController(m_p, m_i, m_d, m_angleMotor, m_angleMotor);

    m_controller->SetOutputRange(-1, 1);
    m_controller->SetSetpoint(FUELCOLLECTOR_MIN_ENC_ANGLE);

    m_controller->Enable();
}

void cFuelCollector::setCollectorSpeed(double speed) {
	m_collectorMotor->setOutput(speed);
}

void cFuelCollector::setFlapSetpoint(double setpoint)
{
	m_controller->SetSetpoint(setpoint);
}

cFuelCollector::~cFuelCollector()
{
    // TODO Auto-generated destructor stub
    delete m_collectorMotor;
    delete m_angleMotor;
}
