/*
 * this class is the interface
 * for the oi. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IOI_H_
#define SRC_SUBSYSTEMS_IOI_H_

#include <OI.h>

class iOI
{
public:
    virtual float getLeftStickY() = 0;
    virtual float getRightStickY() = 0;

    virtual float getTurretSlider() = 0;
    virtual float getShooterSlider() = 0;
};



#endif /* SRC_SUBSYSTEMS_IOI_H_ */
