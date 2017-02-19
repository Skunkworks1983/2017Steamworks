/*
 * cMotor.h
 *
 *  Created on: Jan 17, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_CMOTOR_H_
#define SRC_SUBSYSTEMS_CMOTOR_H_
#include <CANTalon.h>
#include <CANSpeedController.h>
#include <PIDSource.h>
#include <PIDOutput.h>
#include <Subsystems/Interfaces/iMotor.h>

enum eMotorType
{
    BaneBots775,/*ayylmao*/ NeveRest40, CIM
};

class cMotor: public iMotor
{
private:
    CANTalon m_motor;
    bool m_hasEncoder;
    eMotorType m_motorType;
    frc::CANSpeedController::ControlMode m_pidType;
public:
    cMotor(int port, eMotorType motorType, bool hasEncoder = false, frc::CANSpeedController::ControlMode pidType =
            frc::CANSpeedController::kPosition);
    virtual ~cMotor();
    void setBrakeMode(bool brake);
    void setOutput(float output);
    void PIDWrite(double output) override;
    double PIDGet() override;
    void setEnabled(bool enabled);
    bool hasEncoder();

    frc::CANSpeedController::ControlMode getControlMode();
    void setControlMode(frc::CANSpeedController::ControlMode mode);

    double getPosition();
};
#endif /* SRC_SUBSYSTEMS_CMOTOR_H_ */
