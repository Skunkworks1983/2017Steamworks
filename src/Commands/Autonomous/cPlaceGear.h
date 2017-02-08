/*
 * cPlaceGear.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 */

#ifndef SRC_COMMANDS_AUTONOMOUS_CPLACEGEAR_H_
#define SRC_COMMANDS_AUTONOMOUS_CPLACEGEAR_H_
#include <Commands/CommandGroup.h>
#include "AutoBase.h"

class cPlaceGear : public CommandGroup {
public:
	cPlaceGear();
	virtual ~cPlaceGear();
};

#endif /* SRC_COMMANDS_AUTONOMOUS_CPLACEGEAR_H_ */
