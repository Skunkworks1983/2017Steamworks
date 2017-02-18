/*
 * iOI.h
 *
 *  Created on: Feb 16, 2017
 *      Author: s-4036956
 */

#ifndef SRC_SUBSYSTEMS_IOI_H_
#define SRC_SUBSYSTEMS_IOI_H_

#include <OI.h>

class iOI
{
public:
    virtual float getLeftStickY() = 0;
    virtual float getRightStickY() = 0;
};



#endif /* SRC_SUBSYSTEMS_IOI_H_ */
