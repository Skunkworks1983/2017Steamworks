/*
 * cGearPath.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Mike
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CGEARPATH_H_
#define SRC_COMMANDS_AUTONOMOUS_CGEARPATH_H_
#include <RobotMap.h>
#include "AutoBase.h"
#include "CommandBase.h"
class cGearPath {
private:

public:
	cGearPath();
	~cGearPath();
	static void FindGearPath();
	void ExecuteGearPath();
};


#endif /* SRC_COMMANDS_AUTONOMOUS_CGEARPATH_H_ */
/*
 * when angle variables are named, the naming structure is like this:
 *
 * angleAlphaBetaGamma
 *  	          Alpha
 *      	     /
 *          	/
 *       	   /
 *       	  /
 *       	 /
 *      Beta/____________Gamma
 *
 */
