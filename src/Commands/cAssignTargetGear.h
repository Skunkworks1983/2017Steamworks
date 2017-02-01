/*
 * assignTargetGear.h
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CASSIGNTARGETGEAR_H_
#define SRC_COMMANDS_CASSIGNTARGETGEAR_H_

#include <Commands/Command.h>

class cAssignTargetGear: public frc::Command
{
public:
    cAssignTargetGear();
    virtual ~cAssignTargetGear();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CASSIGNTARGETGEAR_H_ */
