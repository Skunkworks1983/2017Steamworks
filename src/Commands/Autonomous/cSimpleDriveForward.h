/*
 * cSimpleDriveForward.h
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CSIMPLEDRIVEFORWARD_H_
#define SRC_COMMANDS_AUTONOMOUS_CSIMPLEDRIVEFORWARD_H_

#include <Commands/Command.h>
#include <Subsystems/cDriveBase.h>
#include <Subsystems/cMotor.h>
#include <PIDController.h>
#include "Subsystems/cMotorGroup.h"

class cSimpleDriveForward: public frc::Command
{
private:
    PIDController *m_pidController;
    cMotorGroup* motorGroupAll;
    float m_distance;
    bool m_stopAtLine;
public:
    cSimpleDriveForward(float distance, bool stopAtLine = false);
    ~cSimpleDriveForward();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

};

#endif /* SRC_COMMANDS_AUTONOMOUS_CSIMPLEDRIVEFORWARD_H_ */
