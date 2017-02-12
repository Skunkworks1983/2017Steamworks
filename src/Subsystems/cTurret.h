#ifndef SRC_SUBSYSTEM_TURRET_H
#define SRC_SUBSYSTEM_TURRET_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cTurret: public Subsystem
{
private:
    cMotor* m_motor1;

public:
    Servo* m_servo1; // test servo

    cTurret();
    ~cTurret();
    void InitDefaultCommand();

    void setSpeed(float speed);
    void setOrientation(float heading);
    void rotate(float degrees);
};

#endif
