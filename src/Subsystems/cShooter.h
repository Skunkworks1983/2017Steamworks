#ifndef SRC_SUBSYSTEM_SHOOTER_H
#define SRC_SUBSYSTEM_SHOOTER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cShooter : public Subsystem
{
private:
    cMotor* m_motor1;
    cMotor* m_motor2;

    bool m_manualEnabled;

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
