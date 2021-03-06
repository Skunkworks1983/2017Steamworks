#ifndef cPointToBoiler_H
#define cPointToBoiler_H

#include <CommandBase.h>
#include <PIDSource.h>
#include <Subsystems/Utilities/cPidUDP.h>
#include <Stubsystems/cPIDOutputContainer.h>
#include <PIDController.h>
#include <CANSpeedController.h>

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
	float m_p;
	float m_i;
	float m_d;

	cPIDOutputContainer* m_pidCont;

	frc::CANSpeedController::ControlMode m_start;
};

#endif  // cPointToBoiler_H
