/*
 * cRunFuelCollector.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_CRUNFUELFLAP_H_
#define SRC_COMMANDS_CRUNFUELFLAP_H_

#include <Commands/Command.h>
#include <RobotMap.h>

class cRunFuelFlap: public frc::Command
{
private:
    FuelCollectorPosition m_position;

public:
    cRunFuelFlap(FuelCollectorPosition position, float timeout);
    virtual ~cRunFuelFlap();

    void Initialize();
    void Execute();bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CRUNFUELFLAP_H_ */
