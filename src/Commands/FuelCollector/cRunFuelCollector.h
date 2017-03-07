#ifndef cRunFuelCollector_H
#define cRunFuelCollector_H

#include <CommandBase.h>

class cRunFuelCollector : public CommandBase {
private:
	double m_speed;
public:
	cRunFuelCollector(double m_speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cRunFuelCollector_H
