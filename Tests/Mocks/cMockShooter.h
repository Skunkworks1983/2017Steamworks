/*
 * this file is the header for the
 * mock shooter. we use this for
 * unit testing & receiving values that
 * are fake
 */

#ifndef SRC_SUBSYSTEMS_MOCKSHOOTER_H
#define SRC_SUBSYSTEMS_MOCKSHOOTER_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Subsystems/Interfaces/iShooter.h>

class cMockShooter : public iShooter {
public:
    MOCK_METHOD1(setSpeed, void(float speed));
    MOCK_METHOD0(getSpeed, double());

    MOCK_METHOD1(setManualEnabled, void(bool state));
    MOCK_METHOD0(isManualEnabled, bool());

    MOCK_METHOD0(ResetPID, void());
    MOCK_METHOD0(EnablePID, void());
    MOCK_METHOD0(isPIDEnabled, bool());
    MOCK_METHOD4(setPID, void(double p, double i, double d, double f));
    MOCK_METHOD0(PIDGet, double());
    MOCK_METHOD0(getError, double());
    MOCK_METHOD1(setSetpoint, void(float setpoint));
    MOCK_METHOD0(getSetpoint, double());
    MOCK_METHOD0(DisablePID, void());
    MOCK_METHOD0(getShooterMotor, cMotor*());

};

#endif
