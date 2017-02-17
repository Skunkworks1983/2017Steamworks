#ifndef cRunOneMotor_H
#define cRunOneMotor_H

#include "../../CommandBase.h"
#include "../../Subsystems/cMotor.h"

class cRunOneMotor : public CommandBase {
private:
	cMotor* m_motor1;
	cMotor* m_motor2;
public:
	cRunOneMotor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cRunOneMotor_H
