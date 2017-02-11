/*
 * cRunLoader.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_CRUNFUELLOADER_H_
#define SRC_COMMANDS_CRUNFUELLOADER_H_

#include <Commands/Command.h>

class cRunFuelLoader: public frc::Command
{
private:
    float m_speed;

public:
    cRunFuelLoader(float speed, float timeout);
    virtual ~cRunFuelLoader();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CRUNFUELLOADER_H_ */
