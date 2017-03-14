#include "../AutoBase.h"
#include <RobotMap.h>
#include <Commands/DriveBase/cDriveStraight.h>

AutoBase* AutoBase::goDead2()
{
    AutoBase* commands = new AutoBase();

    if(USE_GYRO) {
    	//spin up shooter
		#ifdef PRACTICE_BOT
    		commands->AddSequential(new cDriveStraight(7250, 0.3));
		#endif

		#ifndef PRACTICE_BOT
    		commands->AddSequential(new cDriveStraight(-7250, 0.2));
		#endif
    	std::cout << "Added cDriveStraight" << std::endl;
    	//shoot balls
    }

    return commands;
}
