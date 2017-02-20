/*
 * this class is the interface
 * for the fuel conveyor. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IFUELCONVEYOR_H_
#define SRC_SUBSYSTEMS_IFUELCONVEYOR_H_
#include <Commands/Subsystem.h>

class iFuelConveyor: public Subsystem
{
public:
    iFuelConveyor() : Subsystem("FuelConveyor"){};

    virtual void setSpeed(float speed) = 0;
};



#endif /* SRC_SUBSYSTEMS_ICLIMBER_H_ */
