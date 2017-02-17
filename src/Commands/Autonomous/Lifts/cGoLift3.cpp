#include "../AutoBase.h"
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>

AutoBase* AutoBase::goLift3()
{
    AutoBase* goLift3 = new AutoBase();

    goLift3->AddSequential(new cSimpleDriveForward(AUTO_MOVE_FORWARD_FEET, true));
    goLift3->AddSequential(new cTurnDegree(-AUTO_TURN_DEGREES));

    return goLift3;
}
