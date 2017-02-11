#ifndef SRC_SUBSYSTEM_SHOOTER_H
#define SRC_SUBSYSTEM_SHOOTER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cShooter : public Subsystem
{
public:
	 enum ShooterSide
		{
			LEFT, RIGHT
		};
    cShooter(ShooterSide side);
    ~cShooter();
    void InitDefaultCommand();

    void setSpeed(float speed);
    double getSpeed();

    cShooter *getLeft();
    cShooter *getRight();

    void DisablePID();
	void EnablePID();
	void ResetPID();
	bool isPIDEnabled();
	void setSetpoint(float setpoint);
	double PIDGet();
	void setPID(double p, double i, double d);
	double getSetpoint();
	double getError();

private:
    cMotor* m_motor1;
    cMotor* m_motor2;

    cShooter *left = NULL;
    cShooter *right = NULL;

    CANTalon *talon = NULL;
    float setpoint = 0.0;
    ShooterSide side;
};

#endif
