/*
 * cSwitchBackFront.h
 *
 *  Created on: Feb 15, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_DRIVEBASE_CSWITCHBACKFRONT_H_
#define SRC_COMMANDS_DRIVEBASE_CSWITCHBACKFRONT_H_

#include <Commands/Command.h>

class cSwitchBackFront: public frc::Command
{
private:

public:
    cSwitchBackFront();
    virtual ~cSwitchBackFront();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_DRIVEBASE_CSWITCHBACKFRONT_H_ */
