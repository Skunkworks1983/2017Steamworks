/*
 * cReversingMotorGroup.h
 *
 *  Created on: Feb 8, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_CREVERSINGMOTORGROUP_H_
#define SRC_SUBSYSTEMS_CREVERSINGMOTORGROUP_H_

#include <Subsystems/cMotorGroup.h>
#include "Subsystems/iReversingMotorGroup.h"

class cReversingMotorGroup: public cMotorGroup
{
private:
    std::vector<bool> m_motorReverse;
public:
    cReversingMotorGroup(std::vector<bool>motorReverse, std::vector<iMotor*> motorList);
    virtual ~cReversingMotorGroup();

    void setOutput(float output) override;
    void PIDWrite(double output) override;
};

#endif /* SRC_SUBSYSTEMS_CREVERSINGMOTORGROUP_H_ */
