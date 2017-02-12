/*
 * cMotorGroup.h
 *
 *  Created on: Feb 1, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_CMOTORGROUP_H_
#define SRC_SUBSYSTEMS_CMOTORGROUP_H_

#include <Subsystems/cMotor.h>
#include <vector>
#include "iMotor.h"
#include "Subsystems/iMotorGroup.h"

class cMotorGroup: public iMotorGroup
{
private:
    std::vector<iMotor*> m_motorList;
public:
    cMotorGroup(std::vector<iMotor*> motorList); //or you could call it motorSquad ~(.^.)~
    virtual ~cMotorGroup();
    void setBrakeMode(bool brake) override;
    void setOutput(float output) override;
    void PIDWrite(double output) override;
    double PIDGet() override;
    void setEnabled(bool enabled) override;
    bool hasEncoder();
    std::vector<iMotor*> GetMotorList();
};

#endif /* SRC_SUBSYSTEMS_CMOTORGROUP_H_ */
