#ifndef SRC_SUBSYSTEM_SHOOTER_H
#define SRC_SUBSYSTEM_SHOOTER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"
#include "Subsystems/iShooter.h"

class cShooter : public iShooter
{
private:
    cMotor* m_motor1;
    cMotor* m_motor2;

public:
    cShooter();
    ~cShooter();
    void InitDefaultCommand();

    void setSpeed(float speed);
    double getSpeed();
};

#endif
