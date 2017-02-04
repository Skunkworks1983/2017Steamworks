/*
 * climbRope.h
 *
 *  Created on: Jan 25, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_CCLIMBROPE_H_
#define SRC_COMMANDS_CCLIMBROPE_H_

#include <Commands/Command.h>

class cClimbRope: public frc::Command
{
private:
    float m_speed;

public:
    cClimbRope(float speed, float timeout);
    virtual ~cClimbRope();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CCLIMBROPE_H_ */
