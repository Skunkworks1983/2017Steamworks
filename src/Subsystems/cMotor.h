/*
 * cMotor.h
 *
 *  Created on: Jan 17, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_CMOTOR_H_
#define SRC_SUBSYSTEMS_CMOTOR_H_
#include <CANTalon.h>
#include <PIDSource.h>
#include <PIDOutput.h>

class cMotor: public PIDSource, public PIDOutput
{
private:
    CANTalon m_motor;
public:
    cMotor(int port);
    virtual ~cMotor();
    void setBrakeMode(bool brake);
    void setOutput(float output);
    void PIDWrite(double output) override;
    double PIDGet() override;
    void setEnabled(bool enabled);
};
#endif /* SRC_SUBSYSTEMS_CMOTOR_H_ */
