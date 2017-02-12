/*
 * cTurnDegree.h
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CTURNDEGREE_H_
#define SRC_COMMANDS_AUTONOMOUS_CTURNDEGREE_H_

#include <Commands/Command.h>
#include <PIDController.h>
#include <Subsystems/cDriveBase.h>

class cReversingMotorGroup;
class cTurnDegree: public frc::Command
{
private:
    float m_targetAngle;
    PIDController *m_pidController;
    cReversingMotorGroup *m_motorGroupGyro;
    cGyro *m_realNiceGyro;

public:
    cTurnDegree(float targetAngle);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_AUTONOMOUS_CTURNDEGREE_H_ */
