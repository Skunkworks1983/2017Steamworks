/*
 * cRunFuelConveyor.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_FUELCONVEYOR_CRUNFUELCONVEYOR_H_
#define SRC_COMMANDS_FUELCONVEYOR_CRUNFUELCONVEYOR_H_

#include <Commands/Command.h>
#include <Subsystems/Utilities/cMotor.h>

class cRunFuelConveyor: public frc::Command
{
private:
	cMotor* m_window;
public:
    cRunFuelConveyor();
    virtual ~cRunFuelConveyor();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_FUELCONVEYOR_CRUNFUELCONVEYOR_H_ */
