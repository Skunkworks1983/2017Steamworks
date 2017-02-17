/*
 * cManualTurretControl.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_TURRET_CMANUALTURRETCONTROL_H_
#define SRC_COMMANDS_TURRET_CMANUALTURRETCONTROL_H_

#include <Commands/Command.h>

class cManualTurretControl: public frc::Command
{
private:

public:
    cManualTurretControl();
    virtual ~cManualTurretControl();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_TURRET_CMANUALTURRETCONTROL_H_ */
