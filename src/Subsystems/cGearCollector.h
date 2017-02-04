#ifndef SRC_SUBSYSTEM_GEARCOLLECTOR_H
#define SRC_SUBSYSTEM_GEARCOLLECTOR_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cGearCollector: public Subsystem
{
private:
    Servo* m_servo1;

public:
    cGearCollector();
    ~cGearCollector();
    void InitDefaultCommand();

    void setState(bool state);

    void setServoAngle(float angle);
    float getServoAngle();
};

#endif
