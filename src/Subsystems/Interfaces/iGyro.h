/*
 * iGyro.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_IGYRO_H_
#define SRC_SUBSYSTEMS_IGYRO_H_
#include <PIDSource.h>

class iGyro: public PIDSource
{
public:
    virtual double PIDGet() = 0;
    virtual void initGyro() = 0;
    virtual bool isDead() = 0;
    virtual void zeroYaw() = 0;
    virtual double getAngle() = 0;
};

#endif /* SRC_SUBSYSTEMS_IGYRO_H_ */
