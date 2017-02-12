/*
 * iDriveBase.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_IDRIVEBASE_H_
#define SRC_SUBSYSTEMS_IDRIVEBASE_H_
#include <Commands/Subsystem.h>

class iDriveBase: public Subsystem
{
public:
virtual void resetEncoder() = 0;
virtual void setLeftSpeed(double speed) = 0;
virtual void setRightSpeed(double speed) = 0;
virtual void setBrakeMode(bool brake) = 0;
virtual void setEnabled(bool enabled) = 0;
};

#endif /* SRC_SUBSYSTEMS_IDRIVEBASE_H_ */
