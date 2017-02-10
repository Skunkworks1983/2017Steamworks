/*
 * MockTest.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: Thomas

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class Interface
{
public:
	virtual ~Interface() {}
	virtual int method(int param) = 0;
};

class MockInterface: public Interface
{
public:
	MOCK_METHOD1(method, int(int param));
};

void testFunction(MockInterface* interface)
{
	interface->method(1);
}

TEST(MockTest, mockDetectsCall)
{
	MockInterface interface;
	EXPECT_CALL(interface, method(::testing::_)).Times(1);
	testFunction(&interface);
}
 */
