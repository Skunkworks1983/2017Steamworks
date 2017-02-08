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

/*
  _ _   _                         _          _
 (_) | ( )                       | |        | |
  _| |_|/ ___    __ _ _ __   __ _| | ___  __| |
 | | __| / __|  / _` | '_ \ / _` | |/ _ \/ _` |
 | | |_  \__ \ | (_| | | | | (_| | |  __/ (_| |
 |_|\__| |___/  \__,_|_| |_|\__, |_|\___|\__,_|
                             __/ |
                            |___/
 */

class cFuelCollector: public frc::Subsystem
{
private:
    cMotor* m_hopperMotor;
    Servo* m_collectorFlapServo;

public:
    cFuelCollector();
    virtual ~cFuelCollector();

    void setCollectorFlapAngle(float angle);
    void setHopperDrumSpeed(float speed);
};

#endif /* SRC_SUBSYSTEMS_CFUELCOLLECTOR_H_ */
