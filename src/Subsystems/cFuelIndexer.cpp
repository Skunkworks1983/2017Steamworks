/*
 * The fuel indexer is the subsystem that
 * loads balls individually into the shooter.
 * It is not the belt that rolls them up into
 * the indexer.
 */

#include <RobotMap.h>
#include <Subsystems/cFuelIndexer.h>

cFuelIndexer::cFuelIndexer()
{
    // TODO Auto-generated constructor stub
    m_motor1 = new cMotor(FUELINDEXER_MOTOR1_PORT, BaneBots775);
}

void cFuelIndexer::setSpeed(float speed)
{
    m_motor1->setOutput(-1 * speed);
}

cFuelIndexer::~cFuelIndexer()
{
    // TODO Auto-generated destructor stub
    delete m_motor1;
}

