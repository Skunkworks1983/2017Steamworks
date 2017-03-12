/*
 * cMotorGroup.h
 *
 *  Created on: Feb 1, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_CMOTORGROUP_H_
#define SRC_SUBSYSTEMS_CMOTORGROUP_H_

#include <Subsystems/Interfaces/iMotor.h>
#include <Subsystems/Utilities/cMotor.h>
#include <CANSpeedController.h>
#include <vector>

class cMotorGroup: public iMotor
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

    void setPosition(double position);

    frc::CANSpeedController::ControlMode getControlMode() override;
    void setControlMode(frc::CANSpeedController::ControlMode mode) override;

    void setSetpoint(double value) override;

    double getPosition();
};

#endif /* SRC_SUBSYSTEMS_CMOTORGROUP_H_ */
