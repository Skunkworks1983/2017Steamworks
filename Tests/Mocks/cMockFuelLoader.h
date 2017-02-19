/*
 * this file is the header for the
 * mock fuel loader. we use this for
 * unit testing & receiving values that
 * are fake
 */

#ifndef SRC_SUBSYSTEMS_MOCKFUELLOADER_H
#define SRC_SUBSYSTEMS_MOCKFUELLOADER_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iFuelLoader.h>

class cMockFuelLoader : public iFuelLoader {
public:
    MOCK_METHOD1(setSpeed, void(float speed));
};

#endif