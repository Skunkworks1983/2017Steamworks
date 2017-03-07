/*
 * cShootWhenReady.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_SHOOTER_CSHOOTWHENREADY_H_
#define SRC_COMMANDS_SHOOTER_CSHOOTWHENREADY_H_

#include <Commands/Command.h>

class cShootWhenReady: public frc::Command
{
public:
    cShootWhenReady(float timeout);
    virtual ~cShootWhenReady();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_SHOOTER_CSHOOTWHENREADY_H_ */
