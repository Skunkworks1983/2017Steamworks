#pragma once

#include <Commands/Command.h>

class cWait: public frc::Command {
public:
	cWait(float timeout);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float m_timeout;
};
