#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/DriveBase/cTurnAngle.h>

AutoBase* AutoBase::goLiftBoiler()
{
    AutoBase* commands = new AutoBase();

    commands->AddSequential(new cSimpleDriveForward(BOILER_START_DRIVE_DISTANCE));

    if (RED) { //TODO
        commands->AddSequential(new cTurnAngle(-1 * BOILER_START_FIRST_ANGLE));
    } else {
        commands->AddSequential(new cTurnAngle(BOILER_START_FIRST_ANGLE));
    }
    commands->AddSequential(new cSimpleDriveForward(DISTANCE_BASE_LINE_TO_PEG));

    return commands;
}
