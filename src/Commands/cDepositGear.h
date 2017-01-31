/*
 * depositGear.h
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CDEPOSITGEAR_H_
#define SRC_COMMANDS_CDEPOSITGEAR_H_

#include <Commands/Command.h>

class cDepositGear: public frc::Command
{
public:
    cDepositGear();
    virtual ~cDepositGear();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CDEPOSITGEAR_H_ */
