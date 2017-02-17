/*
 * cFuelLoader.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_SUBSYSTEMS_CFUELLOADER_H_
#define SRC_SUBSYSTEMS_CFUELLOADER_H_

#include <Commands/Subsystem.h>
#include "cMotor.h"
#include "Subsystems/iFuelLoader.h"

class cFuelLoader: public iFuelLoader
{
private:
    cMotor* m_motor1;

public:
    cFuelLoader();
    virtual ~cFuelLoader();

    void setSpeed(float speed);
};

#endif /* SRC_SUBSYSTEMS_CFUELLOADER_H_ */
