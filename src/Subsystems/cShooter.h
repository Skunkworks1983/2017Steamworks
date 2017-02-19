#ifndef SRC_SUBSYSTEM_SHOOTER_H
#define SRC_SUBSYSTEM_SHOOTER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cShooter : public Subsystem
{
public:
    cShooter(bool speed, bool brake);
    ~cShooter();
    void InitDefaultCommand();

    void setSpeed(float speed);
    double getSpeed();

    void DisablePID();
	void EnablePID(bool speed);
	void ResetPID();
	bool isPIDEnabled();
	void setSetpoint(float setpoint);
	double PIDGet();
	void setPID(double p, double i, double d, double f);
	double getSetpoint();
	double getError();

private:
    cMotor* m_motor1;
    cMotor* m_motor2;

    float setpoint = 0.0;
};

#endif
