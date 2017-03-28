#ifndef cSetCollectorSpeed_H
#define cSetCollectorSpeed_H

#include <CommandBase.h>

class cSetCollectorSpeed : public CommandBase {
private:
	double m_speed;
public:
	cSetCollectorSpeed(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cSetCollectorSpeed_H
