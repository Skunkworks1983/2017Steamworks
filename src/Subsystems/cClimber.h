#ifndef SRC_SUBSYSTEM_CLIMBER_H
#define SRC_SUBSYSTEM_CLIMBER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cClimber : public Subsystem
{
private:
    cMotor* m_motor1;
    cMotor* m_motor2;

public:
    cClimber();
    ~cClimber();
    void InitDefaultCommand();

    void setSpeed(float speed);
};

#endif
