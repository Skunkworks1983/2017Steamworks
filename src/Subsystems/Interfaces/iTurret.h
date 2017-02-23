/*
 * this class is the interface
 * for the turret. it's an
 * abstract class because it doesn't
 * do anything and serves as a placeholder
 * for the real deal during unit testing.
 */

#ifndef SRC_SUBSYSTEMS_ITURRET_H_
#define SRC_SUBSYSTEMS_ITURRET_H_
#include <Commands/Subsystem.h>

class iTurret : public Subsystem
{
private:
    bool m_manualEnabled = false;

public:
    iTurret() : Subsystem("Turret"){};
    virtual void setSpeed(float speed) = 0;
    virtual void setOrientation(float heading) = 0;
    virtual void rotate(float degrees) = 0;

    virtual float getHeading() = 0;

    virtual void setManualEnabled(bool state) = 0;
    virtual bool isManualEnabled() = 0;
    virtual cMotor* getTurretMotor() = 0;

    virtual void setEnabled(bool enabled) = 0;
    virtual void setSetpoint(int ticks) = 0;
};

/*
 * cTurret();
    ~cTurret();
    void InitDefaultCommand();

    //void setManualEnabled(bool state);
    //bool isManualEnabled();

    //float getHeading();

    //void setSpeed(float speed);
    //void setOrientation(float heading);
    //void rotate(float degrees);

    //cMotor* getTurretMotor();

    //void setSetpoint(int ticks);
    //void setEnabled(bool enabled);
 */

#endif /* SRC_SUBSYSTEMS_ITURRET_H_ */
