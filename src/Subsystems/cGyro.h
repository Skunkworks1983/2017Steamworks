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

class cGyro: public PIDSource
{
private:
    AHRS *m_ahrs;
    const int AHRS_CYCLE_TIMEOUT = 500;
    bool m_dead;
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
