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

    float m_p;
    float m_i;
    float m_d;

    bool m_manualEnabled = false;

public:
    /*Servo* m_servoYaw;
    Servo* m_servoPitch;*/

    cTurret();
    ~cTurret();

    void setManualEnabled(bool state);
    bool isManualEnabled();

    float getHeading();

    void setSpeed(float speed);
    void setOrientation(float heading);
    void rotate(float degrees);

    cMotor* getTurretMotor();

    void setSetpoint(int ticks);
    void setEnabled(bool enabled);
};

#endif
