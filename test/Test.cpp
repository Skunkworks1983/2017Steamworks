/*
 * Test.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: s-4036956
 */
#include <gtest/gtest.h>
#include "Test.h"

Test::Test() {
	// TODO Auto-generated constructor stub

}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

//casually doesn't have gtest.h

class MathTest: public ::testing::Test
{
protected:
	int x = 1;
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{

	}
};

TEST_F(MathTest, outputCanBeSet){
	int answer = x + x;
	EXPECT_EQ(2, answer);
};


