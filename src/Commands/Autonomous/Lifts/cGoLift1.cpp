#include "../AutoBase.h"
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>

AutoBase* AutoBase::goLift1()
{
    AutoBase* goLift1 = new AutoBase();

    goLift1->AddSequential(new cSimpleDriveForward(AUTO_MOVE_FORWARD_FEET, true));
    goLift1->AddSequential(new cTurnDegree(AUTO_TURN_DEGREES));

    return goLift1;
}
