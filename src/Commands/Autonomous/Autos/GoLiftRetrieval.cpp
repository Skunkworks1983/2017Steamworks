#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/DriveBase/cTurnAngle.h>

AutoBase* AutoBase::goLiftRetrieval() {
	AutoBase* commands = new AutoBase();

	if (AutoBase::getAlliance() == RED) {
		commands->AddSequential(new cTurnAngle(RETRIEVAL_START_FIRST_ANGLE));
	} else {
		commands->AddSequential(new cTurnAngle(-1 * RETRIEVAL_START_FIRST_ANGLE));
	}

	commands->AddSequential(
			new cSimpleDriveForward(RETRIEVAL_START_DRIVE_DISTANCE));

	if (RED) {
		commands->AddSequential(new cTurnAngle(RETRIEVAL_START_SECOND_ANGLE));
	} else {
		commands->AddSequential(new cTurnAngle(-1 * RETRIEVAL_START_SECOND_ANGLE));
	}
	commands->AddSequential(new cSimpleDriveForward(DISTANCE_BASE_LINE_TO_PEG));

	return commands;
}
