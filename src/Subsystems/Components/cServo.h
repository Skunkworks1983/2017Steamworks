/*
 * cServo.h
 *
 *  Created on: Feb 17, 2017
 *      Author: Nathan
 */

#ifndef SRC_SUBSYSTEMS_COMPONENTS_CSERVO_H_
#define SRC_SUBSYSTEMS_COMPONENTS_CSERVO_H_

#include <Subsystems/Components/iServo.h>

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
