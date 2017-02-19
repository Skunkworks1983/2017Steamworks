/*
 * this class is the interface
 * for the fuel loader. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IFUELLOADER_H_
#define SRC_SUBSYSTEMS_IFUELLOADER_H_
#include <Commands/Subsystem.h>

class iFuelLoader: public Subsystem
{
public:
    iFuelLoader() : Subsystem("FuelLoader"){};
    virtual void setSpeed(float speed) = 0;
};



#endif /* SRC_SUBSYSTEMS_IFUELLOADER_H_ */
