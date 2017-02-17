/*
 * cManualTurretControl.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Nathan
 *
 * This command controls the turret manually
 * with no input from sensors. When the command
 * is running, we enable the member variable
 * 'm_manualControl' (or something) on the turret,
 * blocking any other commands from using the turret.
 *
 * note: this code doesn't take into account the range of motion
 * of the turret: if wires get yanked out, that's on the driver,
 * not us.
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
