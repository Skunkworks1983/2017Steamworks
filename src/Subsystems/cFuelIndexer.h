/*
 * cFuelIndexer.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_SUBSYSTEMS_CFUELINDEXER_H_
#define SRC_SUBSYSTEMS_CFUELINDEXER_H_

#include <Commands/Subsystem.h>
#include <Subsystems/Interfaces/iFuelIndexer.h>
#include <Subsystems/Utilities/cMotor.h>

class cFuelIndexer: public iFuelIndexer
{
private:
    cMotor* m_motor1;

public:
    cFuelIndexer();
    virtual ~cFuelIndexer();

    void setSpeed(float speed);
};

#endif /* SRC_SUBSYSTEMS_CFUELINDEXER_H_ */
