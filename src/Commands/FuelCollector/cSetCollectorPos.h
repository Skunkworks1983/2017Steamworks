#ifndef cSetCollectorUp_H
#define cSetCollectorUp_H

#include <CommandBase.h>
#include <RobotMap.h>

class cSetCollectorPos : public CommandBase {
public:
	cSetCollectorPos(); //if not up then down
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cSetCollectorUp_H
