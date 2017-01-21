/*
 * cRunTankDrive.h
 *
 *  Created on: Jan 16, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CRUNTANKDRIVE_H_
#define SRC_COMMANDS_CRUNTANKDRIVE_H_
#include <CommandBase.h>
#include <cstdbool>
//program initiates tank drive. Makes robot move when joystick move in a w ay that resembles a tank so cool
class cRunTankDrive: public CommandBase {
private:
	bool driveState = true; //m_

public:
	cRunTankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_CRUNTANKDRIVE_H_ */
