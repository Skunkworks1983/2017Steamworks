/*
 * iMotor.h
 *
 *  Created on: Feb 4, 2017
 *      Author: paella
 */

#ifndef SRC_SUBSYSTEMS_IMOTOR_H_
#define SRC_SUBSYSTEMS_IMOTOR_H_
#include <PIDSource.h>
#include <PIDOutput.h>
#include <CANSpeedController.h>

class iMotor: public PIDSource, public PIDOutput
{
public:
    virtual void setBrakeMode(bool brake) = 0;
    virtual void setOutput(float output) = 0;
    virtual void PIDWrite(double output) override = 0;
    virtual double PIDGet() override = 0;
    virtual void setEnabled(bool enabled) = 0;
    virtual bool hasEncoder() = 0;

    virtual CANSpeedController::ControlMode getControlMode() = 0;
    virtual void setControlMode(CANSpeedController::ControlMode mode) = 0;

    virtual double getPosition() = 0;
};
#endif /* SRC_SUBSYSTEMS_IMOTOR_H_ */
