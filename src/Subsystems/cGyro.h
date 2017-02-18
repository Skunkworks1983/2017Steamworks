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
#include <RobotMap.h>
#include "Subsystems/iGyro.h"

class cGyro: public iGyro
{
private:
    const int AHRS_CYCLE_TIMEOUT = 500;
    bool m_dead;
    AHRS* m_ahrs;
public:
    cGyro();
    virtual ~cGyro();
    virtual double PIDGet();
    void initGyro();
    bool isDead();
    void zeroYaw();
    double getAngle();
};

#endif /* SRC_SUBSYSTEMS_CGYRO_H_ */
