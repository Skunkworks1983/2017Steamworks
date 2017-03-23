#ifndef cRunFuelCollector_H
#define cRunFuelCollector_H

#include <CommandBase.h>

class cRunFloorCollector : public CommandBase {
private:
	double m_speed;
public:
	cRunFloorCollector(double m_speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cRunFuelCollector_H
