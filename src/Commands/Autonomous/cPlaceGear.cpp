#include "cAutoBase.h"
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>
#include <Commands/Autonomous/cCenterTape.h>
#include <Commands/Autonomous/cGearPath.h>

cAutoBase* cAutoBase::placeGear()
{
    cAutoBase* placeGear = new cAutoBase();
    m_placeGear = new CommandGroup;
    m_placeGear->AddSequential(new cCenterTape());
    m_placeGear->AddSequential(new cGearPath());
    m_placeGear->AddSequential(new cTurnDegree(cAutoBase::s_angleTapeRobotPivotPoint));
    m_placeGear->AddSequential(new cSimpleDriveForward(cAutoBase::s_distanceToPivotPoint));
    m_placeGear->AddSequential(new cTurnDegree(cAutoBase::s_angleRobotPivotPointGoal));
    m_placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PIVOT_POINT_TO_GOAL));

    return placeGear;
}
