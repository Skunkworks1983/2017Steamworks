/*
 * assignTargetBoiler.h
 *
 *  Created on: Jan 26, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CASSIGNTARGETBOILER_H_
#define SRC_COMMANDS_CASSIGNTARGETBOILER_H_

#include <Commands/Command.h>
#include <RobotMap.h>

class cAssignTargetBoiler: public frc::Command
{
private:
    eShootingPosition m_position;

public:
    cAssignTargetBoiler(eShootingPosition position);
    virtual ~cAssignTargetBoiler();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CASSIGNTARGETBOILER_H_ */
