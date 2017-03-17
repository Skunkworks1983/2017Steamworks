/*
 * cGyro.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: s-4036956
 */

#include <I2C.h>
#include <Subsystems/Sensors/cGyro.h>
#include <RobotMap.h>

cGyro::cGyro()
{
	m_ahrs = NULL;
	m_dead = false;
}

cGyro::~cGyro()
{
    delete m_ahrs;
}

double cGyro::PIDGet()
{
    return m_ahrs->GetAngle();
}

void cGyro::zeroYaw() {
	m_ahrs->ZeroYaw();
}

void cGyro::initGyro() {
	LOG_INFO("Initializing Gyro");
	std::cout << "Estoy initeando" << std::endl;
	std::cout << m_dead << " <- ahrs" << std::endl;

	if (m_ahrs == NULL) {
		std::cout << "Inside m_ahrs null" << std::endl;
		try {
			//ahrsDead = false;

			std::cout << "Before construct ahrs" << std::endl;
			m_ahrs = new AHRS(SPI::Port::kMXP);
			int counter = 0;
			std::cout << "Before attempt connect" << std::endl;
			while (!m_ahrs->IsConnected()) {
				counter++;
				if (counter > AHRS_CYCLE_TIMEOUT) {
					//LOG_ERROR("AHRS NOT CONNECTED");
					m_dead = true;
					break;
				}
			}
			counter = 0;
			std::cout << "Before calibration attempt" << std::endl;
			while (m_ahrs->IsCalibrating()) {
				if (counter++ % 5 == 0) {
					//LOG_INFO("Counter %d", counter);
				}
				/*if (counter > 100000) {
					std::cout << "Over 100000" << std::endl;
					break;
				}*/
			}
			std::cout << counter << std::endl;
			std::cout << "Is it dead: " << m_dead << std::endl;
			std::cout << "Is it connected: " << m_ahrs->IsConnected() << std::endl;
			LOG_INFO("Is the AHRS connected? %s",
					(m_ahrs->IsConnected() ? "Yes\n" : "no\n"));
		} catch (std::exception * ex) {
			std::cout << ex->what() << std::endl;
			LOG_ERROR("Error instantiating navX MXP: %s \t", ex->what());

			m_dead = true;
		} catch ( ... ) {
			std::cout << "Error instantiating navX MXP: ..." << std::endl;
			LOG_ERROR("Error instantiating navX MXP: ... \t");

			m_dead = true;
		}
	} else { std::cout << "Its not null" << std::endl; }
}

bool cGyro::isDead() {
	return m_dead;
}

double cGyro::getAngle() {
	return m_ahrs->GetAngle();
}
