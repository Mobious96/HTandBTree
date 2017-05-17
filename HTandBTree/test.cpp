#include "gtest/gtest.h"
#include "pair.h"
#include "list.h"
#include "hashtable.h"
#include "avl.h"
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
TEST(List, RemoveByValueOnceMiddle)
{
	List<int> list;
	list.Add(1);
	list.Add(3);
	list.Add(4);
	EXPECT_NO_THROW(list.RemoveByValueOnce(3));
}
TEST(List, RemoveByValueOnceFirst)
{
	List<int> list;
	list.Add(1);
	list.Add(3);
	list.Add(4);
	list.RemoveByValueOnce(1);
	EXPECT_EQ(list.head->value, 3);
}
TEST(List, RemoveByValueOnceLast)
{
	List<int> list;
	list.Add(1);
	list.Add(3);
	list.Add(4);
	EXPECT_NO_THROW(list.RemoveByValueOnce(4));
}



TEST(HashTable, TableMaxRec)
{
	HTSepChain<int, int> chain(10);
	EXPECT_EQ(chain.MaxRec,10);
}
TEST(HashTable, Put)
{
	HTSepChain<int, int> chain(10);
	chain.put(2, 3);
	EXPECT_NO_THROW(chain.put(1, 2));
}


TEST(HashTable, PutCheckValueFirst)
{
	HTSepChain<int, int> chain(10);
	chain.put(1, 2);
	chain.put(2, 3);
	EXPECT_EQ(chain.table[1].head->value.value, 2);
}
TEST(HashTable, PutCheckValueSecond)
{
	HTSepChain<int, int> chain(10);
	chain.put(1, 2);
	chain.put(2, 3);
	EXPECT_EQ(chain.table[2].head->value.value, 3);
}
TEST(HashTable, GetFirst)
{
	HTSepChain<int, int> chain(10);
	chain.put(1, 2);
	chain.put(2, 3);
	EXPECT_EQ(chain.get(2), 3);
}
TEST(HashTable, GetFirstIfThereAreTwoRec)
{
	HTSepChain<int, int> chain(10);
	chain.put(1, 2);
	chain.put(2, 3);
	chain.put(2, 4);
	EXPECT_EQ(chain.get(2), 3);
}



TEST(AVL, Init)
{
	AVL<int,int> tree;
	EXPECT_NO_THROW(tree);
}
TEST(AVL, InitValue)
{
	AVL<int, int> tree(1, 3);
	EXPECT_EQ(tree.root->value, 3);
}
TEST(AVL, ConstructorCopy)
{
	AVL<int, int> tree(1, 3);
	AVL<int, int> tree2(tree);
	EXPECT_EQ(tree.root->value, 3);
}
TEST(AVL, Put)
{
	AVL<int, int> tree(2,3);
	EXPECT_NO_THROW(tree.Put(4, 2));
}
TEST(AVL, PutRight)
{
	AVL<int, int> tree(2, 3);
	tree.Put(4, 2);
	EXPECT_EQ(tree.root->right->value, 2);
}
TEST(AVL, PutLeftBitch)
{
	AVL<int, int> tree(2, 3);
	tree.Put(1, 2);
	EXPECT_EQ(tree.root->left->value, 2);
}