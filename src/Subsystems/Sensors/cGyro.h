/*
 * cGyro.h
 *
 *  Created on: Feb 9, 2017
 *      Author: s-4036956
 */


#ifndef SRC_SUBSYSTEMS_CGYRO_H_
#define SRC_SUBSYSTEMS_CGYRO_H_
#include <PIDController.h>
#include <AHRS.h>
#include <Subsystems/Interfaces/iGyro.h>

class cGyro: public PIDSource
{
private:
    AHRS *m_ahrs;
public:
    cGyro();
    virtual ~cGyro();
    virtual double PIDGet();
};

#endif /* SRC_SUBSYSTEMS_CGYRO_H_ */
