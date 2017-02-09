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
class cRunTankDrive: public CommandBase
{
private:
    bool driveState = true; //m_

public:
    cRunTankDrive();
    void Initialize();
    void Execute();bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CRUNTANKDRIVE_H_ */
