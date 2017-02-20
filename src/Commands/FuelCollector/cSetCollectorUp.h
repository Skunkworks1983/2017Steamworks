#ifndef cSetCollectorUp_H
#define cSetCollectorUp_H

#include <CommandBase.h>
#include <PIDController.h>

class cSetCollectorUp : public CommandBase {
private:
	PIDController* m_controller;
	bool m_up;
public:
	cSetCollectorUp(bool up); //if not up then down
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cSetCollectorUp_H
