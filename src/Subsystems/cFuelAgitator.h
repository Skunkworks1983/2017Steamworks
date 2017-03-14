/*
 * cFuelAgitator.h
 *
 *  Created on: Mar 11, 2017
 *      Author: s-2508366
 */

#ifndef SRC_SUBSYSTEMS_CFUELAGITATOR_H_
#define SRC_SUBSYSTEMS_CFUELAGITATOR_H_

#include <Subsystems/Interfaces/iFuelAgitator.h>
#include <Subsystems/Utilities/cMotor.h>

class cFuelAgitator : public iFuelAgitator
{
private:
    cMotor* m_motor1;

public:
    cFuelAgitator();
    virtual ~cFuelAgitator();

    void setSpeed(float speed);
};

#endif /* SRC_SUBSYSTEMS_CFUELAGITATOR_H_ */
