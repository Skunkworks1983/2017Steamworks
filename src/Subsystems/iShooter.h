/*
 * iShooter.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_ISHOOTER_H_
#define SRC_SUBSYSTEMS_ISHOOTER_H_
#include <Commands/Subsystem.h>

class iShooter: public Subsystem
{
public:
    virtual void setSpeed(float speed) = 0;
    virtual void getSpeed() = 0;
};



#endif /* SRC_SUBSYSTEMS_ISHOOTER_H_ */
