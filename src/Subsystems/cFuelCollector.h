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
#include <Subsystems/Utilities/cMotor.h>
#include <Subsystems/Interfaces/iFuelCollector.h>
#include <PIDController.h>

class cFuelCollector: public iFuelCollector
{
private:
    cMotor* m_collectorMotor;
    cMotor* m_angleMotor;

    PIDController* m_controller;

    float m_p;
    float m_i;
    float m_d;
public:
    cFuelCollector();
    virtual ~cFuelCollector();

    void setFlapSetpoint(double setpoint);
    void setCollectorSpeed(double speed);

    double getFlapSetpoint();
};

#endif /* SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_ */
