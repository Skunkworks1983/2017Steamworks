#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>

AutoBase* AutoBase::goLiftRetrieval()
{
    AutoBase* commands = new AutoBase();

    if(USE_COLOR_SENSOR)
    {
        commands->AddSequential(new cSimpleDriveForward(100, true));
    }
    else
    {
        commands->AddSequential(new cSimpleDriveForward(AUTO_MOVE_FORWARD_FEET, false));
    }

    commands->AddSequential(new cTurnDegree(-AUTO_TURN_DEGREES));

    return commands;
}
