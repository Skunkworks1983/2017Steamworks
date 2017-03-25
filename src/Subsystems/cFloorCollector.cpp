/*
 * cFuelCollector.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#include <RobotMap.h>
#include <Subsystems/cFloorCollector.h>

cFloorCollector::cFloorCollector()
{
    m_collectorMotor = new cMotor(FUELCOLLECTOR_COLLECTOR_PORT, BaneBots775);
    m_angleMotor = new cMotor(FUELCOLLECTOR_ANGLE_PORT, BaneBots775, true);

    m_collectorMotor->setBrakeMode(true);

    m_p = 1./1250;
    m_i = 1./10000000;
    m_d = 1./950;

    m_controller = new PIDController(m_p, m_i, m_d, m_angleMotor, m_angleMotor);

    m_controller->SetOutputRange(-1, 1);
}

void cFloorCollector::setCollectorSpeed(double speed) {
	m_collectorMotor->setOutput(speed);
}

void cFloorCollector::setFlapSetpoint(double setpoint)
{
	m_controller->SetSetpoint(setpoint);
}

cFloorCollector::~cFloorCollector()
{
    delete m_collectorMotor;
    delete m_angleMotor;
}

double cFloorCollector::getError() {
	return m_controller->GetError();
}

void cFloorCollector::setEnabled(bool enabled) {
	if(enabled) {
		m_controller->Enable();
	} else {
		m_controller->Disable();
	}
}

void cFloorCollector::setFlapSpeed(double speed) {
	if(!m_controller->IsEnabled()) {
		m_angleMotor->setOutput(speed);
	}
}
