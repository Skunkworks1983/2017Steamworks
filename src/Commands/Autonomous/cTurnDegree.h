/*
 * cTurnDegree.h
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CTURNDEGREE_H_
#define SRC_COMMANDS_AUTONOMOUS_CTURNDEGREE_H_

#include <Commands/Command.h>

class cTurnDegree: public frc::Command
{
private:
    float targetAngle;
    float angleRemaining;

public:
    cTurnDegree();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_AUTONOMOUS_CTURNDEGREE_H_ */
