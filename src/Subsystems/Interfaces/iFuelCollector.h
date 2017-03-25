/*
 * this class is the interface
 * for the fuel collector. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_
#define SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_
#include <Commands/Subsystem.h>
#include "Subsystems/Utilities/cMotor.h"

class iFuelCollector: public Subsystem
{
public:
    iFuelCollector() : Subsystem("FuelCollector"){};
    virtual void setFlapSetpoint(double setpoint) = 0;
    virtual void setCollectorSpeed(double speed) = 0;

    virtual double getError() = 0;

    virtual void setEnabled(bool enabled) = 0;

    virtual void setFlapSpeed(double speed) = 0;
};



#endif /* SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_ */
