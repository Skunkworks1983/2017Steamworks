#ifndef cDriveUntilWall_H
#define cDriveUntilWall_H

#include <CommandBase.h>
#include <PIDController.h>

class cDriveUntilWall : public PIDSource, public PIDOutput, public Command {
private:
	PIDController* m_controller;

	float m_p;
	float m_i;
	float m_d;

	double m_speed;
	bool m_isDisabled;

	double m_leftStart;
	double m_rightStart;
public:
	cDriveUntilWall(double speed = 0.25);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	double PIDGet();
	void PIDWrite(double output);
};

#endif  // cDriveUntilWall_H
