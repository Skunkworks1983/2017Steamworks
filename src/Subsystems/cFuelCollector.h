/*
 * cFuelCollector.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_
#define SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_

#include <Commands/Subsystem.h>
#include "cMotor.h"

class cFuelCollector: public frc::Subsystem
{
private:
    cMotor* m_hopperMotor;
    cMotor* m_collectorFlapMotor;

public:
    cFuelCollector();
    virtual ~cFuelCollector();

    void setCollectorFlapSpeed(float speed);
    void setHopperDrumSpeed(float speed);
};

#endif /* SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_ */
