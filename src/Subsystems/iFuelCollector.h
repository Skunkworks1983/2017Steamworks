/*
 * iFuelCollector.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_
#define SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_
#include <Commands/Subsystem.h>

class iFuelCollector: public Subsystem
{
public:
    iFuelCollector() : Subsystem("FuelCollector"){};
    virtual void setCollectorFlapAngle(float angle) = 0;
    virtual void setHopperDrumSpeed(float speed) = 0;
};



#endif /* SRC_SUBSYSTEMS_IFUELCOLLECTOR_H_ */
