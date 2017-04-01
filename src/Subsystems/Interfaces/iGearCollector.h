/*
 * this class is the interface
 * for the gear collector. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
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
    virtual bool isGearIn() = 0;
};



#endif /* SRC_SUBSYSTEMS_IGEARCOLLECTOR_H_ */
