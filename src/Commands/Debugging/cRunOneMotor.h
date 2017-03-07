#ifndef cRunOneMotor_H
#define cRunOneMotor_H

#include "../../CommandBase.h"
#include "../../Subsystems/Utilities/cMotor.h"
#include <vector>

class cRunOneMotor : public CommandBase {
private:

	std::vector<cMotor*> m_motors;

	bool m_pressedLastLoop;
	int m_index;
public:
	cRunOneMotor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cRunOneMotor_H
