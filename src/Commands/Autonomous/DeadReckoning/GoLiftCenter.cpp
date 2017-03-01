#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>

//Places a gear on the lift when we start on the second (center) position.
//we have to start aligned with the thingy

AutoBase* AutoBase::goLiftCenter()
{
    AutoBase* commands = new AutoBase();

    commands->AddSequential(new cSimpleDriveForward(DISTANCE_WALL_TO_BASE_LINE));

    return commands;
}
