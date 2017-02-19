/*
 * this class is the interface
 * for the shooter. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_ISHOOTER_H_
#define SRC_SUBSYSTEMS_ISHOOTER_H_
#include <Commands/Subsystem.h>

class iShooter: public Subsystem
{
private:
    bool m_manualEnabled = false;

public:
    iShooter() : Subsystem("Shooter"){};
    virtual void setSpeed(float speed) = 0;
    virtual double getSpeed() = 0;

    virtual void setManualEnabled(bool state) = 0;
    virtual bool isManualEnabled() = 0;

    virtual void DisablePID() = 0;
	virtual void EnablePID() = 0;
	virtual void ResetPID() = 0;
	virtual bool isPIDEnabled() = 0;
	virtual void setSetpoint(float setpoint) = 0;
	virtual double PIDGet() = 0;
	virtual void setPID(double p, double i, double d, double f) = 0;
	virtual double getSetpoint() = 0;
	virtual double getError() = 0;

};



#endif /* SRC_SUBSYSTEMS_ISHOOTER_H_ */
