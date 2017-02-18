#ifndef ISERVO_H
#define ISERVO_H

#include "WPILib.h"

class iServo : public PIDSource, public PIDOutput
{
public:
    virtual void setAngle(float angle) = 0;
    virtual float getAngle() = 0;

    virtual void PIDWrite(double output) override = 0;
    virtual double PIDGet() override = 0;
};

#endif
