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
#include <stdint.h>

enum eMotorType
{
    BaneBots775,NeveRest40, CIM
};

class cMotor: public iMotor
{
private:

    eMotorType m_motorType;
    uint64_t m_timeStall;
    CANTalon m_motor;
    bool m_hasEncoder;
    bool m_disabledEncoder;

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

    //shooter stuff
    double GetSpeed() const;
    void SetSetpoint(double value);
    double GetSetpoint() const;
    virtual void SetPID(double p, double i, double d, double f);
    void Set(double value);
    void reverseSensorDirection();
    void reverseOutput();
    void setFeedbackDevice();
    bool isEnabled() const;
    virtual int getClosedLoopError() const;
    void Reset();
    void Disable();
    void Enable();

    bool hasEncoder();

    frc::CANSpeedController::ControlMode getControlMode();
    void setControlMode(frc::CANSpeedController::ControlMode mode);

    void configForwardLimit(double position);
    void configReverseLimit(double position);

    void setSetpoint(double value);

    double getPosition();

    double getOutput();

};
#endif /* SRC_SUBSYSTEMS_CMOTOR_H_ */
