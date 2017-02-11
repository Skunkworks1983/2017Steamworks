/*
 * spinUpShooter.h
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CSPINUPSHOOTER_H_
#define SRC_COMMANDS_CSPINUPSHOOTER_H_

#include <Commands/Command.h>

class cSpinUpShooter: public frc::Command
{
public:
    cSpinUpShooter();
    virtual ~cSpinUpShooter();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CSPINUPSHOOTER_H_ */
