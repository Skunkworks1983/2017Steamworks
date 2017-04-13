/*
 * cConditionalWiggle.h
 *
 *  Created on: Mar 31, 2017
 *      Author: S-2508366
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CCONDITIONALWIGGLE_H_
#define SRC_COMMANDS_AUTONOMOUS_CCONDITIONALWIGGLE_H_

#include <Commands/Command.h>

class cConditionalWiggle: public frc::Command
{
private:


public:
    CommandGroup* m_commands;

    cConditionalWiggle();
    virtual ~cConditionalWiggle();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_AUTONOMOUS_CCONDITIONALWIGGLE_H_ */
