/*
 * this class is the interface
 * for the climber. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_ICLIMBER_H_
#define SRC_SUBSYSTEMS_ICLIMBER_H_
#include <Commands/Subsystem.h>

class iClimber: public Subsystem
{
public:
    iClimber() : Subsystem("Shooter"){};
    virtual void setSpeed(float speed) = 0;

};



#endif /* SRC_SUBSYSTEMS_ICLIMBER_H_ */
