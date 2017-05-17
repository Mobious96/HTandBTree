#include "gtest/gtest.h"
#include "pair.h"
#include "list.h"
TEST(Pair, GetKey)
{
	int a = 1;
	int b = 2;
	TPair<int, int> A(a, b);
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
TEST(Node, OperatorEqual )
{
	int a = 1;
	int b = 2;
	Node<int> *node1 = new Node<int>;
	node1->value = a;
	Node<int> *node2 = new Node<int>;
	node2->value = b;
	node1 = node2;
	EXPECT_EQ(node1->value, 2);
	delete node1;
}

TEST(List, ConstructorDefaultInt)
{
	EXPECT_NO_THROW(List<int> list);
}
TEST(List, ConstructorInitInt)
{
	ASSERT_NO_THROW(List<int> list(2));
}
TEST(List, ConstructorInitPairs)
{
	TPair<int, int> a(1, 2);
	Node<TPair<int, int> > node(a);
	EXPECT_EQ(node.value.value, 2);
}

TEST(List, GetValueFromHead)
{
	List<int> list(2);
	EXPECT_EQ(list.head->value, 2);
}
TEST(List, Add)
{
	List<int> list;
	list.Add(2);
	EXPECT_EQ(list.head->value, 2);
}
TEST(List, ExpectNoThrowDestructor)
{
	List<int> list;
	list.Add(2);
	list.Add(3);
	EXPECT_NO_THROW(list.Add(4));
}
TEST(List, AddTwice)
{
	List<int> list;
	list.Add(2);
	list.Add(3);
	ASSERT_EQ(list.head->value, 2);
}
TEST(List, WorkWithPairs)
{
	TPair<int, int> a(1, 2);
	List<TPair<int, int> > list(a);
	EXPECT_EQ(list.head->value.value, 2);
}
