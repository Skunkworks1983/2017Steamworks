/*
 * this class is the interface
 * for the gyro. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
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
