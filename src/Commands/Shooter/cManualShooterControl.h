/*
 * cManualShooterControl.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Nathan
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
