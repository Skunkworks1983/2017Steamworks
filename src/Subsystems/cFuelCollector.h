/*
 * cFuelCollector.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_
#define SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "cMotor.h"
#include  "Subsystems/iFuelCollector.h"

class cFuelCollector: public iFuelCollector
{
private:
    cMotor* m_hopperMotor;
    Servo* m_flapServo;

public:
    cFuelCollector();
    virtual ~cFuelCollector();

    void setFlapAngle(float angle);
    void setHopperDrumSpeed(float speed);

    float getFlapAngle();
    float getHopperDrumSpeed();
};

#endif /* SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_ */
