/*
 * acquireGear.h
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CACQUIREGEAR_H_
#define SRC_COMMANDS_CACQUIREGEAR_H_

#include <Commands/Command.h>

class cAcquireGear: public frc::Command
{
private:
    bool m_state;

public:
    cAcquireGear(bool state, float timeout = 0);
    virtual ~cAcquireGear();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CACQUIREGEAR_H_ */
