/*
 * this class is the interface
 * for the drive base. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IDRIVEBASE_H_
#define SRC_SUBSYSTEMS_IDRIVEBASE_H_
#include <Commands/Subsystem.h>
#include <Subsystems/Utilities/cMotorGroup.h>
#include <Subsystems/Utilities/cReversingMotorGroup.h>
#include <Subsystems/Interfaces/iGyro.h>

class iDriveBase: public Subsystem
{
public:
    iDriveBase() : Subsystem("DriveBase"){};
    virtual void resetEncoder() = 0;
    virtual void setLeftSpeed(double speed) = 0;
    virtual void setRightSpeed(double speed) = 0;
    virtual void setBrakeMode(bool brake) = 0;
    virtual void setEnabled(bool enabled) = 0;
    virtual cMotorGroup* getMotorGroupLeft() = 0;
    virtual cMotorGroup* getMotorGroupRight() = 0;
    virtual cMotorGroup* getMotorGroupAll() = 0;
    virtual cReversingMotorGroup* getMotorGroupGyro() = 0;
    virtual iGyro* getGyro() = 0;
    virtual bool CanSeeTape() = 0;
    virtual bool getIsReversed() = 0;
    virtual void setIsReversed(bool isreversed) = 0;
};

#endif /* SRC_SUBSYSTEMS_IDRIVEBASE_H_ */
