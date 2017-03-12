/*
 * cFuelConveyor.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Nathan
 */

#ifndef SRC_SUBSYSTEMS_CFUELCONVEYOR_H_
#define SRC_SUBSYSTEMS_CFUELCONVEYOR_H_

#include <Subsystems/Interfaces/iFuelConveyor.h>
#include <Subsystems/Utilities/cMotor.h>

class cFuelConveyor: public iFuelConveyor
{
private:
    cMotor* m_motor1;
    cMotor* window;

public:
    cFuelConveyor();
    virtual ~cFuelConveyor();

    void setSpeed(float speed);
};

#endif /* SRC_SUBSYSTEMS_CFUELCONVEYOR_H_ */
