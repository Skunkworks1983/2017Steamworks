/*
 * this class is the interface
 * for the fuel agitator. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_IFUELAGITATOR_H_
#define SRC_SUBSYSTEMS_IFUELAGITATOR_H_
#include <Commands/Subsystem.h>

class iFuelAgitator: public Subsystem
{
public:
    iFuelAgitator() : Subsystem("iFuelAgitator") {};
    virtual void setSpeed(float speed) = 0;
};



#endif /* SRC_SUBSYSTEMS_IFUELAGITATOR_H_ */
