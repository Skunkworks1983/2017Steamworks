/*
 * iFuelLoader.h
 *
 *  Created on: Feb 12, 2017
 *      Author: s-4036956
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
