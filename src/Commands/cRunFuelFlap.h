/*
 * cRunFuelCollector.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_CRUNFUELFLAP_H_
#define SRC_COMMANDS_CRUNFUELFLAP_H_

#include <Commands/Command.h>

class cRunFuelFlap: public frc::Command
{
private:
    float m_speed;

public:
    cRunFuelFlap(float speed, float timeout);
    virtual ~cRunFuelFlap();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CRUNFUELFLAP_H_ */
