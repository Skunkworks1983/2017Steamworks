#ifndef cSetTurretSetpoint_H
#define cSetTurretSetpoint_H

#include <CommandBase.h>

class cSetTurretSetpoint : public CommandBase {
private:
	double m_setpoint;
public:
	cSetTurretSetpoint(double setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cSetTurretSetpoint_H
