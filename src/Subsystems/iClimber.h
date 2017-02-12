/*
 * iClimber.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_ICLIMBER_H_
#define SRC_SUBSYSTEMS_ICLIMBER_H_
#include <Commands/Subsystem.h>

class iClimber: public Subsystem
{
public:
virtual void InitDefaultCommand() = 0;
virtual void setSpeed(float speed) = 0;

};



#endif /* SRC_SUBSYSTEMS_ICLIMBER_H_ */