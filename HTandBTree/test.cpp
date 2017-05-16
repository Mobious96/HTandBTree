#include "gtest/gtest.h"

TEST(testOne, simpleTest)
{
	int a = 1;
	int b = 2;
	EXPECT_NE(a, b);
}