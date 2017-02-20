/*
 * this class is the interface
 * for the fuel indexer. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IFuelIndexer_H_
#define SRC_SUBSYSTEMS_IFuelIndexer_H_
#include <Commands/Subsystem.h>

class iFuelIndexer: public Subsystem
{
public:
    iFuelIndexer() : Subsystem("FuelIndexer"){};
    virtual void setSpeed(float speed) = 0;
};



#endif /* SRC_SUBSYSTEMS_IFuelIndexer_H_ */
