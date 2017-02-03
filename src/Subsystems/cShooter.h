#ifndef SRC_SUBSYSTEM_SHOOTER_H
#define SRC_SUBSYSTEM_SHOOTER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cShooter : public Subsystem
{
private:
    cMotor* motor1;
    cMotor* motor2;

public:
    cShooter();
    ~cShooter();
    void InitDefaultCommand();

    void setSpeed(float speed);
};

#endif
