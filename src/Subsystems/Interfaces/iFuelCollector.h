/*
 * this class is the interface
 * for the fuel collector. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_
#define SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_
#include <Commands/Subsystem.h>

class iFuelCollector: public Subsystem
{
public:
    iFuelCollector() : Subsystem("FuelCollector"){};
    virtual void setFlapAngle(float angle) = 0;
    virtual void setHopperDrumSpeed(float speed) = 0;
};



#endif /* SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_ */
