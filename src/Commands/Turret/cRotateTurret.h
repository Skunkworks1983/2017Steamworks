/*
 * cRotateTurret.h
 *
 *  Created on: Feb 5, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CROTATETURRET_H_
#define SRC_COMMANDS_CROTATETURRET_H_

#include <Commands/Command.h>

class cRotateTurret: public frc::Command
{
private:

public:
    cRotateTurret(float timeout = 0);
    virtual ~cRotateTurret();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CROTATETURRET_H_ */
