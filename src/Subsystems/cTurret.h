#ifndef SRC_SUBSYSTEM_TURRET_H
#define SRC_SUBSYSTEM_TURRET_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cTurret : public Subsystem
{
private:
    cMotor* motor1;

public:
    cTurret();
    ~cTurret();
    void InitDefaultCommand();

    void setSpeed(float speed);
    void setOrientation(float heading);
    void rotate(float degrees);
};

#endif
