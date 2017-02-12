/*
 * iReversingMotorGroup.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_IREVERSINGMOTORGROUP_H_
#define SRC_SUBSYSTEMS_IREVERSINGMOTORGROUP_H_
#include <Commands/Subsystem.h>

class iReversingMotorGroup: public Subsystem
{
public:
    virtual void setOutput(float output) = 0;
    virtual void PIDWrite(double output) = 0;
};



#endif /* SRC_SUBSYSTEMS_IREVERSINGMOTORGROUP_H_ */
