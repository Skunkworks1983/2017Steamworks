#include "AutoBase.h"
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>
#include <Commands/Autonomous/cCenterTape.h>
#include <Commands/Autonomous/cGearPath.h>

AutoBase* AutoBase::placeGear()
{
    AutoBase* placeGear = new AutoBase();
    CommandGroup* m_placeGear = new CommandGroup();
    m_placeGear->AddSequential(new cCenterTape());
    m_placeGear->AddSequential(new cGearPath());
    m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleTapeRobotPivotPoint));
    m_placeGear->AddSequential(new cSimpleDriveForward(AutoBase::s_distanceToPivotPoint));
    m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleRobotPivotPointGoal));
    m_placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PIVOT_POINT_TO_GOAL));

    return placeGear;
}
