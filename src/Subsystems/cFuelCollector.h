#ifndef SRC_SUBSYSTEM_FUELCOLLECTOR_H
#define SRC_SUBSYSTEM_FUELCOLLECTOR_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cFuelCollector : public Subsystem
{
private:
    cMotor* motor1;

public:
    cFuelCollector();
    ~cFuelCollector();
    void InitDefaultCommand();

    void setSpeed(float speed);
};

#endif
