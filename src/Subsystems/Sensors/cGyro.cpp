/*
 * cGyro.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: s-4036956
 */

#include <I2C.h>
#include <Subsystems/Sensors/cGyro.h>

cGyro::cGyro()
{
    // TODO Auto-generated constructor stub
    m_ahrs = new AHRS(SPI::kMXP); /* Alternatives:  SPI::kMXP, I2C::kMXP or SerialPort::kUSB */
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
