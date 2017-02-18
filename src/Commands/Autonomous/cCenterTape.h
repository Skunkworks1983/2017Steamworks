/*
 * cCenterTape.h
 *
 *  Created on: Feb 14, 2017
 *      Author: Mike
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CCENTERTAPE_H_
#define SRC_COMMANDS_AUTONOMOUS_CCENTERTAPE_H_
#include <Commands/Command.h>
#include <PIDController.h>
#include <Subsystems/cDriveBase.h>
#include <RobotMap.h>
#include <CommandBase.h>
#include <Services/cMessage.h>

class cCenterTape : public frc::Command, PIDSource, PIDOutput
{
private:
	PIDController *m_pidController;
	cReversingMotorGroup *m_motorGroupGyro;
	cGyro *m_superGoodGyro;
public:
	cCenterTape();
	virtual ~cCenterTape();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double PIDGet();
	void PIDWrite(double output);
    cLiftData* m_data;

};

#endif /* SRC_COMMANDS_AUTONOMOUS_CCENTERTAPE_H_ */
