#include "gtest/gtest.h"
#include "pair.h"
TEST(Pair, GetKey)
{
	int a = 1;
	int b = 2;
	pair<int,int> A(a, b);
	EXPECT_EQ(A.GetKey(), 1);
}