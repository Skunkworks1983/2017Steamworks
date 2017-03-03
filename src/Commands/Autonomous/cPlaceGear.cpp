#include "AutoBase.h"
#include <Commands/Autonomous/cSimpleDriveForward.h>
#include <Commands/Autonomous/cTurnDegree.h>
#include <Commands/Autonomous/cCenterTape.h>
#include <Commands/Autonomous/cGearPath.h>

AutoBase* AutoBase::placeGear()
{
    AutoBase* placeGear = new AutoBase();
    m_placeGear = new CommandGroup;
    switch (startPosition) {

    case POS_BOILER:
 	   m_placeGear->AddSequential(new cSimpleDriveForward(10, true));
 	   m_placeGear->AddSequential(new cCenterTape());
 	   m_placeGear->AddSequential(new cGearPath());
 	   m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleTapeRobotPivotPoint));
 	   m_placeGear->AddSequential(new cSimpleDriveForward(AutoBase::s_distanceToPivotPoint));
 	   m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleRobotPivotPointPeg));
 	   m_placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PEG_TO_PIVOT_POINT));
 	   break;
    case POS_CENTER:
       m_placeGear->AddSequential(new cCenterTape());
       m_placeGear->AddSequential(new cGearPath());
       m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleTapeRobotPivotPoint));
       m_placeGear->AddSequential(new cSimpleDriveForward(AutoBase::s_distanceToPivotPoint));
       m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleRobotPivotPointPeg));
       m_placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PEG_TO_PIVOT_POINT));
       break;
    case POS_RETRIEVAL:
    	m_placeGear->AddSequential(new cSimpleDriveForward(10, true));
    	m_placeGear->AddSequential(new cCenterTape());
    	m_placeGear->AddSequential(new cGearPath());
    	m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleTapeRobotPivotPoint));
    	m_placeGear->AddSequential(new cSimpleDriveForward(AutoBase::s_distanceToPivotPoint));
    	m_placeGear->AddSequential(new cTurnDegree(AutoBase::s_angleRobotPivotPointPeg));
    	m_placeGear->AddSequential(new cSimpleDriveForward(DISTANCE_FROM_PEG_TO_PIVOT_POINT));
    	break;
       }
    }

    return placeGear;
}
