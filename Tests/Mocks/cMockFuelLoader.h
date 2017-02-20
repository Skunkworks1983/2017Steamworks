/*
 * this file is the header for the
 * mock fuel loader. we use this for
 * unit testing & receiving values that
 * are fake
 */

#ifndef SRC_SUBSYSTEMS_MOCKFuelIndexer_H
#define SRC_SUBSYSTEMS_MOCKFuelIndexer_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iFuelIndexer.h>

class cMockFuelIndexer : public iFuelIndexer {
public:
    MOCK_METHOD1(setSpeed, void(float speed));
};

#endif
