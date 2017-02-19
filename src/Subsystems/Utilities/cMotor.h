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

enum MotorType
{
    BaneBots775, NeveRest40, CIM
};

class cMotor: public iMotor
{
private:
    CANTalon m_motor;
    bool m_hasEncoder;
    MotorType m_motorType;
public:
    cMotor(int port, MotorType motorType, bool hasEncoder = false);
    virtual ~cMotor();
    void setBrakeMode(bool brake);
    void setOutput(float output);
    void PIDWrite(double output) override;
    double PIDGet() override;
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

    CANSpeedController::ControlMode getControlMode();
    void setControlMode(CANSpeedController::ControlMode mode);

    double getPosition();

};
#endif /* SRC_SUBSYSTEMS_CMOTOR_H_ */
