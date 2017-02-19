/*
 * iGearCollector.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_IGEARCOLLECTOR_H_
#define SRC_SUBSYSTEMS_IGEARCOLLECTOR_H_
#include <Commands/Subsystem.h>

class iGearCollector : public Subsystem
{
public:
    iGearCollector() : Subsystem("GearCollector"){};

    virtual void setFlapState(bool open) = 0;
    virtual void setServoAngle(float angle) = 0;
};



#endif /* SRC_SUBSYSTEMS_IGEARCOLLECTOR_H_ */
