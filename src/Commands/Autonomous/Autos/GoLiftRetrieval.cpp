#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/DriveBase/cTurnAngle.h>
#include <Commands/DriveBase/cDriveStraight.h>

AutoBase* AutoBase::goLiftRetrieval() {

	AutoBase* driving = new AutoBase();
	/*if (AutoBase::getAlliance() == RED) {
		driving->AddSequential(new cTurnAngle(RETRIEVAL_START_FIRST_ANGLE));
	} else {
		driving->AddSequential(new cTurnAngle(-1 * RETRIEVAL_START_FIRST_ANGLE));
	}*/

	driving->AddSequential(new cDriveStraight(RETRIEVAL_START_DRIVE_DISTANCE));

	if (AutoBase::getAlliance() == RED) {
		driving->AddSequential(new cTurnAngle(RETRIEVAL_START_SECOND_ANGLE));
	} else {
		driving->AddSequential(new cTurnAngle(-1 * RETRIEVAL_START_SECOND_ANGLE));
	}
	driving->AddSequential(new cDriveStraight(DISTANCE_BASE_LINE_TO_PEG, .25, 0, true));

	return driving;
}
