#ifndef SRC_SUBSYSTEM_TURRET_H
#define SRC_SUBSYSTEM_TURRET_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include <Subsystems/Utilities/cMotor.h>
#include <Subsystems/Interfaces/iTurret.h>

class cTurret : public iTurret
{
private:
    PIDController *m_controller;
    cMotor* m_motor1;

    bool m_manualEnabled = false;

public:
    Servo* m_servoYaw;
    Servo* m_servoPitch;

    cTurret();
    ~cTurret();
    void InitDefaultCommand();

    void setManualEnabled(bool state);
    bool isManualEnabled();

    float getHeading();

    void setSpeed(float speed);
    void setOrientation(float heading);
    void rotate(float degrees);
};

#endif
