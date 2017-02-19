#ifndef SRC_SUBSYSTEM_SHOOTER_H
#define SRC_SUBSYSTEM_SHOOTER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include <Subsystems/Utilities/cMotor.h>
#include <Subsystems/Interfaces/iShooter.h>

class cShooter : public iShooter
{
private:
    cMotor* m_motor1;
    cMotor* m_motor2;

    bool m_manualEnabled = false;

public:
    cShooter();
    ~cShooter();
    void InitDefaultCommand();

    void setSpeed(float speed);
    double getSpeed();

    void setManualEnabled(bool state);
    bool isManualEnabled();
};

#endif
