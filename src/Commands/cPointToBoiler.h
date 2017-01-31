#ifndef cPointToBoiler_H
#define cPointToBoiler_H

#include "../CommandBase.h"
#include <PIDSource.h>
#include "../Subsystems/cPidUDP.h"
#include "../Stubsystems/cPIDOutputContainer.h"
#include <PIDController.h>

class cPointToBoiler : public CommandBase {
public:
	cPointToBoiler();
	~cPointToBoiler();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	PIDSource* m_udpInput;
	PIDController* m_controller;
	int m_p;
	int m_i;
	int m_d;

	cPIDOutputContainer* m_pidCont;
};

#endif  // cPointToBoiler_H
