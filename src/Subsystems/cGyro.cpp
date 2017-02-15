/*
 * cGyro.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: s-4036956
 */

#include <I2C.h>
#include <Subsystems/cGyro.h>

cGyro::cGyro()
{
    // TODO Auto-generated constructor stub
    //m_ahrs = new AHRS(SPI::kMXP); /* Alternatives:  SPI::kMXP, I2C::kMXP or SerialPort::kUSB */
}

cGyro::~cGyro()
{
    delete m_ahrs;
    // TODO Auto-generated destructor stub
}

double cGyro::PIDGet()
{
    return m_ahrs->GetRoll();
}

void cGyro::zeroYaw() {
	m_ahrs->ZeroYaw();
}

void cGyro::initGyro() {
	LOG_INFO("Initializing Gyro");

	if (m_ahrs == NULL) {
		try {
			//ahrsDead = false;

			m_ahrs = new AHRS(I2C::Port::kMXP);
			int counter = 0;
			while (!m_ahrs->IsConnected()) {
				counter++;
				if (counter > AHRS_CYCLE_TIMEOUT) {
					//LOG_ERROR("AHRS NOT CONNECTED");
					m_dead = true;
					break;
				}
			}
			counter = 0;
			while (m_ahrs->IsCalibrating()) {
				if (counter++ % 5 == 0) {
					//LOG_INFO("Counter %d", counter);
				}
				if (counter > 20000) {
					break;
				}
			}
			LOG_INFO("Is the AHRS connected? %s",
					(m_ahrs->IsConnected() ? "Yes\n" : "no\n"));
		} catch (std::exception * ex) {
			LOG_ERROR("Error instantiating navX MXP: %s \t", ex->what());

			m_dead = true;
		}
	}
}

bool cGyro::isDead() {
	return m_dead;
}

double cGyro::getAngle() {
	return m_ahrs->GetAngle();
}
