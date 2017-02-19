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
    BaneBots775,/*ayylmao*/NeveRest40, CIM
};

class cMotor: public iMotor
{
private:
    CANTalon m_motor;bool m_hasEncoder;
    eMotorType m_motorType;
public:
    cMotor(int port, eMotorType motorType, bool hasEncoder = false, frc::CANSpeedController::ControlMode controlMode =
            frc::CANSpeedController::ControlMode::kPercentVbus);
    virtual ~cMotor();
    void setBrakeMode(bool brake);
    void setOutput(float output);
    void PIDWrite(double output) override;
    double PIDGet() override;
    bool getPIDEnabled();
    void setPIDEnabled(bool enabled);
    void setEnabled(bool enabled);
    bool hasEncoder();

    frc::CANSpeedController::ControlMode getControlMode();
    void setControlMode(frc::CANSpeedController::ControlMode mode);

    void configForwardLimit(double position);
    void configReverseLimit(double position);

    void setSetpoint(double value);

    double getPosition();
};
#endif /* SRC_SUBSYSTEMS_CMOTOR_H_ */
