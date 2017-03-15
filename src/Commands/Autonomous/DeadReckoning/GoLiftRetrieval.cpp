#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>

//Places a gear on the lift when we start on the second (center) position.
//we have to start where the tape marking the key meets the alliance wall.

AutoBase* AutoBase::goLiftRetrieval()
{
    AutoBase* commands = new AutoBase();

    if (RED) {
        commands->AddSequential(new cTurnDegree(RETRIEVAL_START_FIRST_ANGLE));
    } else {
        commands->AddSequential(new cTurnDegree(-1 * RETRIEVAL_START_FIRST_ANGLE));
    }

    commands->AddSequential(new cSimpleDriveForward(RETRIEVAL_START_DRIVE_DISTANCE));

    if (RED) {
        commands->AddSequential(new cTurnDegree(RETRIEVAL_START_SECOND_ANGLE));
    } else {
        commands->AddSequential(new cTurnDegree(-1 * RETRIEVAL_START_SECOND_ANGLE));
    }
    commands->AddSequential(new cSimpleDriveForward(DISTANCE_BASE_LINE_TO_PEG));

    return commands;
}
