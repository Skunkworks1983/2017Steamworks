#ifndef SRC_SUBSYSTEM_FUELINDEXER_H
#define SRC_SUBSYSTEM_FUELINDEXER_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <OI.h>
#include "cMotor.h"

class cFuelIndexer : public Subsystem
{
private:
    cMotor* m_motor1;

public:
    cFuelIndexer();
    ~cFuelIndexer();
    void InitDefaultCommand();

    void setSpeed(float speed);
};

#endif
