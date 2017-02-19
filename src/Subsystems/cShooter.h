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

    float setpoint = 0.0;

    void setManualEnabled(bool state);
    bool isManualEnabled();
    bool m_manualEnabled = false;

public:
    cShooter(bool speed, bool brake);
    ~cShooter();
    void InitDefaultCommand();

    void setSpeed(float speed);
    double getSpeed();

    void DisablePID();
	void EnablePID();
	void ResetPID();
	bool isPIDEnabled();
	void setSetpoint(float setpoint);
	double PIDGet();
	void setPID(double p, double i, double d, double f);
	double getSetpoint();
	double getError();

};

#endif
