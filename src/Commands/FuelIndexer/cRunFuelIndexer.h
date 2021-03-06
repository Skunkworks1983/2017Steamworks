/*
 * cRunLoader.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Nathan
 */

#ifndef SRC_COMMANDS_CRUNFuelIndexer_H_
#define SRC_COMMANDS_CRUNFuelIndexer_H_

#include <Commands/Command.h>

class cRunFuelIndexer: public frc::Command
{
public:
    cRunFuelIndexer();
    virtual ~cRunFuelIndexer();

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif /* SRC_COMMANDS_CRUNFuelIndexer_H_ */
