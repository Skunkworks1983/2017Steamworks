/*
 * this file is the header for the
 * mock fuel collector. we use this for
 * unit testing & receiving values that
 * are fake
 */

#ifndef SRC_SUBSYSTEMS_MOCKFUELCOLLECTOR_H
#define SRC_SUBSYSTEMS_MOCKFUELCOLLECTOR_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iFuelCollector.h>

class cMockFuelCollector : public iFuelCollector {
public:
    MOCK_METHOD1(setFlapAngle, void(float angle));
    MOCK_METHOD1(setHopperDrumSpeed, void(float speed));
};

#endif
