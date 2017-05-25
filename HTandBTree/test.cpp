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
TEST(Node, ConstrCopy)
{
	Node<int> *node1 = new Node<int>;
	node1->value = 1;
	Node<int> *node2 = new Node<int>;
	node2->value = 2;
	node2->next = node1;
	Node<int> *node3(node2);
	EXPECT_EQ(node3->next->value, 1);
	delete node1;
	delete node2;
}
TEST(Node, DeleteNInoperator)
{
	Node<int> *node1 = new Node<int>;
	node1->value = 1;
	Node<int> *node2 = node1;
	EXPECT_EQ(node1->value, 1);
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
	ASSERT_EQ(list.head->next->value, 3);
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
TEST(List, ConstrCopyTest)
{
	List<int> list1;
	list1.Add(1);
	list1.Add(2);
	List<int> list2(list1);
	list1.RemoveByValueOnce(2);
	EXPECT_EQ(list2.head->next->value, 2);
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
TEST(HashTable, PutChar)
{
	HTSepChain<char*, int> charin(10);
	charin.put("Mercy", 3);
	charin.put("helloMoto", 4);
	EXPECT_EQ(charin.get("helloMoto"), 4);
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
TEST(AVL, PutLeftAndRight)
{
	AVL<int, int> tree(3, 3);
	tree.Put(2, 2);
	tree.Put(4, 4);
	EXPECT_EQ(tree.root->right->value, 4);
}
TEST(AVL, PutLeftTwice)
{
	AVL<int, int> tree(3, 3);
	tree.Put(2, 2);
	tree.Put(1, 4);
	EXPECT_EQ(tree.root->left->left->value, 4);
}