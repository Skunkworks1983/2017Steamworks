/*
 * cRunFuelAgitator.h
 *
 *  Created on: Mar 11, 2017
 *      Author: s-2508366
 */

#ifndef SRC_COMMANDS_FUELAGITATOR_CRUNFUELAGITATOR_H_
#define SRC_COMMANDS_FUELAGITATOR_CRUNFUELAGITATOR_H_

#include <Commands/Command.h>

class cRunFuelAgitator: public frc::Command
{
public:
    cRunFuelAgitator();
    virtual ~cRunFuelAgitator();

    void Initialize();
    void Execute();
    bool IsFinished();
    void Interrupted();
    void End();
};

#endif /* SRC_COMMANDS_FUELAGITATOR_CRUNFUELAGITATOR_H_ */
