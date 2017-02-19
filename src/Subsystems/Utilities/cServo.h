/*
 * this class is the wrapper
 * for the wpilib servos. we only
 * have four methods, two of which
 * are for the pidcontrollers.
 */

#ifndef SRC_SUBSYSTEMS_COMPONENTS_CSERVO_H_
#define SRC_SUBSYSTEMS_COMPONENTS_CSERVO_H_

#include <Subsystems/Interfaces/iServo.h>
#include "WPILib.h"

class cServo : public iServo
{
private:
    Servo* m_servo;

public:
    cServo(int port);
    virtual ~cServo();

    void setAngle(float angle);
    float getAngle();

    void PIDWrite(double angle) override;
    double PIDGet() override;
};

#endif /* SRC_SUBSYSTEMS_COMPONENTS_CSERVO_H_ */
