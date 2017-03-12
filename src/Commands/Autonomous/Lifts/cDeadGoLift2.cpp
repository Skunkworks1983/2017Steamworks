#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/DriveBase/cDriveStraight.h>
#include <Commands/Autonomous/cTurnDegree.h>

AutoBase* AutoBase::goDead2()
{
    AutoBase* commands = new AutoBase();

    commands->AddSequential(new cDriveStraight(7300, 0.35));

    return commands;
}
