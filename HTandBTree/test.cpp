#include "gtest/gtest.h"
#include "pair.h"
#include "list.h"
TEST(Pair, GetKey)
{
	int a = 1;
	int b = 2;
	pair<int,int> A(a, b);
	EXPECT_EQ(A.key, 1);
}

TEST(Node, CanSetAndGetValue)
{
	int a = 1;
	int b = 2;
	Node<int> *node = new Node<int>;
	node->value = a;
	EXPECT_EQ(node->value, 1);
	delete node;
}

TEST(List, ConstructorDefaultInt)
{
	EXPECT_NO_THROW(List<int> list);
}
TEST(List, ConstructorInitInt)
{
	ASSERT_NO_THROW(List<int> list(2));
}
TEST(List, GetValueFromHead)
{
	List<int> list(2);
	EXPECT_EQ(list.GetValue(),2);
}
TEST(List, Add)
{	
	List<int> list;
	list.Add(2);
	EXPECT_EQ(list.GetValue(), 2);
}
TEST(List, AddTwice)
{
	List<int> list;
	list.Add(2);
	list.Add(3);
	ASSERT_EQ(list.GetValue(), 2);
}

