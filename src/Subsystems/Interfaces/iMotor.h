/*
 * this class is the interface
 * for the motor. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IMOTOR_H_
#define SRC_SUBSYSTEMS_IMOTOR_H_
#include <PIDSource.h>
#include <PIDOutput.h>
#include <CANSpeedController.h>

class iMotor: public frc::PIDSource, public frc::PIDOutput
{
public:
    virtual void setBrakeMode(bool brake) = 0;
    virtual void setOutput(float output) = 0;
    virtual void PIDWrite(double output) override = 0;
    virtual double PIDGet() override = 0;
    virtual void setEnabled(bool enabled) = 0;
    virtual bool hasEncoder() = 0;

    virtual frc::CANSpeedController::ControlMode getControlMode() = 0;
    virtual void setControlMode(frc::CANSpeedController::ControlMode mode) = 0;

    virtual void setSetpoint(double value) = 0;

    virtual double getPosition() = 0;

    virtual double getOutput() = 0;
};
#endif /* SRC_SUBSYSTEMS_IMOTOR_H_ */
