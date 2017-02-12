/*
 * iMotorGroup.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_IMOTORGROUP_H_
#define SRC_SUBSYSTEMS_IMOTORGROUP_H_
#include <Commands/Subsystem.h>

class iMotorGroup: public Subsystem
{
public:
    virtual void setBrakeMode(bool brake) = 0;
    virtual void setOutput(float output) = 0;
    virtual void PIDWrite(double output) = 0;
    virtual void PIDGet() = 0;
    virtual void setEnabled(bool enabled) = 0;
    virtual void hasEncoder() = 0;
};



#endif /* SRC_SUBSYSTEMS_IMOTORGROUP_H_ */
