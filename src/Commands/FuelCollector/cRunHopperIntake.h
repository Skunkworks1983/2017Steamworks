/*
 * cRunHopperIntake.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_CRUNHOPPERINTAKE_H_
#define SRC_COMMANDS_CRUNHOPPERINTAKE_H_

#include <Commands/Command.h>

class cRunHopperIntake: public frc::Command
{
private:
    float m_speed;

public:
    cRunHopperIntake(float speed, float timeout);
    virtual ~cRunHopperIntake();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CRUNHOPPERINTAKE_H_ */
