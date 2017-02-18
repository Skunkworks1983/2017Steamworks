#ifndef SRC_SUBSYSTEM_GEARCOLLECTOR_H
#define SRC_SUBSYSTEM_GEARCOLLECTOR_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"
#include <Subsystems/Components/cServo.h>
#include "Subsystems/iGearCollector.h"

class cGearCollector: public iGearCollector
{
private:
    iServo* m_servo1;
    iServo* m_servo2;

public:
    cGearCollector();
    ~cGearCollector();
    void InitDefaultCommand();

    void setFlapState(bool open);
    void setServoAngle(float angle);
};

#endif
