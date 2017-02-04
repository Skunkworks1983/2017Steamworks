/*
 * cFollowLine.h
 *
 *  Created on: Jan 28, 2017
 *      Author: s-4036956
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CFOLLOWLINE_H_
#define SRC_COMMANDS_AUTONOMOUS_CFOLLOWLINE_H_

#include <Commands/Command.h>

class cFollowLine: public frc::Command
{
public:
    cFollowLine();
    virtual ~cFollowLine();
    //follow dat boi

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_AUTONOMOUS_CFOLLOWLINE_H_ */
