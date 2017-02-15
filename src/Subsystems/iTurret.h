/*
 * iTurret.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_ITURRET_H_
#define SRC_SUBSYSTEMS_ITURRET_H_
#include <Commands/Subsystem.h>

class iTurret : public Subsystem
{
public:
    iTurret() : Subsystem("Turret"){};
    virtual void setSpeed(float speed) = 0;
    virtual void setOrientation(float heading) = 0;
    virtual void rotate(float degrees) = 0;
};



#endif /* SRC_SUBSYSTEMS_ITURRET_H_ */
