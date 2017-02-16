#ifndef SRC_SUBSYSTEM_GEARCOLLECTOR_H
#define SRC_SUBSYSTEM_GEARCOLLECTOR_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"
#include "Subsystems/iGearCollector.h"

class cGearCollector: public iGearCollector
{
private:
    Servo* m_servo1;

public:
    cGearCollector();
    ~cGearCollector();
    void InitDefaultCommand();

    void setFlapState(bool isOpen);

    void setServoAngle(float angle);
    float getServoAngle();
};

#endif
