/*
 * cManualTurretControl.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Nathan
 *
 * This command controls the shooter manually
 * with no input from sensors. When the command
 * is running, we enable the member variable
 * 'm_manualControl' (or something) on the shooter,
 * blocking any other commands from using the shooter.
 *
 * note: this code doesn't take into account anything but
 * the speeds of the motors, so if something breaks,
 * that's on the driver, not us.
 */

#ifndef SRC_COMMANDS_SHOOTER_CMANUALSHOOTERCONTROL_H_
#define SRC_COMMANDS_SHOOTER_CMANUALSHOOTERCONTROL_H_

#include <Commands/Command.h>

class cManualShooterControl: public frc::Command
{
public:
    cManualShooterControl();
    virtual ~cManualShooterControl();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_SHOOTER_CMANUALSHOOTERCONTROL_H_ */
