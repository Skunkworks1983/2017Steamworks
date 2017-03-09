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
    cMotor* m_motor1;

    bool m_manualEnabled = false;
public:
    cTurret();
    virtual ~cTurret();

    void setManualEnabled(bool state);
    bool isManualEnabled();

    float getHeading();

    double PIDGet();
    double getSetpoint();

    void setSpeed(float speed);
    void setOrientation(float heading);
    void rotate(float degrees);

    cMotor* getTurretMotor();

    void setSetpoint(int ticks);
    void setEnabled(bool enabled);
};

#endif
