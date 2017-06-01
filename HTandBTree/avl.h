#pragma once
#include "pair.h"
#include "BSTree.h"
//template<typename Tkey, typename Tvalue>
//struct BNode
//{
//	Tkey key;
//	Tvalue value;
//	BNode* left;
//	BNode* right;
//	int height;
//	BNode();
//	BNode(Tkey _key, Tvalue _value);
//	~BNode();
//};
//template<typename Tkey, typename Tvalue>
//BNode<Tkey,Tvalue>::BNode()
//{
//	height = 1;
//	left = NULL;
//	right = NULL;
//}
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>::BNode(Tkey _key, Tvalue _value)
//{
//	height = 1;
//	left = NULL;
//	right = NULL;
//	key = _key;
//	value = _value;
//}
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>::~BNode()
//{
//}

//
//template<typename Tkey, typename Tvalue>
//struct AVL
//{
//	BNode<Tkey, Tvalue>* root;
//
//	AVL();
//	//AVL(BNode<Tkey, Tvalue> *_root);
//	AVL(Tkey key, Tvalue value);
//	//AVL(AVL<Tkey, Tvalue>& tree);
//	~AVL();
//	int bfactor(BNode<Tkey, Tvalue>* node);
//	void FixHeight(BNode<Tkey, Tvalue>* node);
//	//int max(int one, int two);
//	BNode<Tkey, Tvalue>* RotateRight(BNode<Tkey, Tvalue>* node);
//	BNode<Tkey, Tvalue>* RotateLeft(BNode<Tkey, Tvalue>* node);
//	//void Put(Tkey key, Tvalue value);
//	//void PutStart(Tkey key, Tvalue value, BNode<Tkey, Tvalue>* node);
//	BNode<Tkey, Tvalue>* insert(BNode<Tkey, Tvalue>* node, Tkey key, Tvalue value);
//	//void traverseDEL(BNode<Tkey, Tvalue>* node);
//	BNode<Tkey, Tvalue>* balance(BNode<Tkey, Tvalue>* node);
//	//void traverseCOPY(BNode<Tkey, Tvalue>* node, BNode<Tkey, Tvalue>* thisnode);
//};
//
//template<typename Tkey, typename Tvalue>
//AVL<Tkey, Tvalue>::AVL()
//{
//	root = NULL;
//}
//template<typename Tkey, typename Tvalue>
//AVL<Tkey,Tvalue>::AVL(Tkey key, Tvalue value)
//{
//	root = new BNode<Tkey, Tvalue>;
//	root->left = NULL;
//	root->right = NULL;
//	root->key = key;
//	root->value = value;
//	root->height = 0;
//}
//template<typename Tkey, typename Tvalue>
//AVL<Tkey, Tvalue>::~AVL()
//{
//}
//template<typename Tkey, typename Tvalue>
//int AVL<Tkey, Tvalue>::bfactor(BNode<Tkey, Tvalue>* node)
//{
//	return node->right->height - node->left->height;
//}
//template<typename Tkey, typename Tvalue>
//void AVL<Tkey, Tvalue>::FixHeight(BNode<Tkey, Tvalue>* node)
//{
//	node->height = (node->left->height > node->right->height ? node->left->height : node->right->height) + 1;
//}
//
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>* AVL<Tkey, Tvalue>::RotateRight(BNode<Tkey, Tvalue>* node)
//{
//	BNode<Tkey, Tvalue>* q = node->left;
//	node->left = q->right;
//	q->right = node;
//	FixHeight(node);
//	FixHeight(q);
//	return q;
//}
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>* AVL<Tkey, Tvalue>::RotateLeft(BNode<Tkey, Tvalue>* node)
//{
//	BNode<Tkey, Tvalue>* p = node->right;
//	node->right = p->left;
//	p->left = node;
//	FixHeight(node);
//	FixHeight(p);
//	return p;
//}
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>* AVL<Tkey, Tvalue>::balance(BNode<Tkey, Tvalue>* p)
//{
//	FixHeight(p);
//	if (bfactor(p) == 2)
//	{
//		if (bfactor(p->right) < 0)
//			p->right = RotateRight(p->right);
//		return RotateLeft(p);
//	}
//	if (bfactor(p) == -2)
//	{
//		if (bfactor(p->left) > 0)
//			p->left = RotateLeft(p->left);
//		return RotateRight(p);
//	}
//	return p;
//}
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>* AVL<Tkey, Tvalue>::insert(BNode<Tkey, Tvalue>* p, Tkey k, Tvalue v)
//{
//	if (!p)
//	{
//		p = new BNode<Tkey, Tvalue>(k, v);
//		return p;
//	}
//	if (k<p->key)
//		p->left = insert(p->left, k, v);
//	else
//		p->right = insert(p->right, k, v);
//	return balance(p);
//}
//








//
//template<typename Tkey, typename Tvalue>
//AVL<Tkey, Tvalue>::AVL()
//{
//	root = NULL;
//}
//template<typename Tkey, typename Tvalue>
//AVL<Tkey,Tvalue>::AVL(Tkey key, Tvalue value)
//{
//	root = new BNode<Tkey, Tvalue>;
//	root->left = NULL;
//	root->right = NULL;
//	root->key = key;
//	root->value = value;
//	root->height = 0;
//}
//template<typename Tkey, typename Tvalue>
//AVL<Tkey,Tvalue>::AVL(BNode<Tkey,Tvalue> *_root)
//{
//	root->left = _root->left;
//	root->right = _root->right;
//	root->value = _root->value;
//	root->height = _root->height;
//}
///*
//template<typename Tkey, typename Tvalue>
//AVL<Tkey, Tvalue>::AVL(AVL<Tkey, Tvalue>& tree)
//{
//	traverseCOPY(tree->root, root);
//}
//*/
//template<typename Tkey, typename Tvalue>
//AVL<Tkey, Tvalue>::~AVL()
//{
//	/*
//	if (root)
//	{
//		traverseDEL(root);
//	}
//	*/
//}
//template<typename Tkey, typename Tvalue>
//void AVL<Tkey, Tvalue>::traverseDEL(BNode<Tkey, Tvalue>* node)
//{
//	if (node == NULL)
//	{
//		return;
//	}
//	traverseDEL(node->left);
//	traverseDEL(node->right);
//	delete node;
//}
///*
//template<typename Tkey, typename Tvalue>
//void AVL<Tkey, Tvalue>::traverseCOPY(BNode<Tkey, Tvalue>* node, BNode<Tkey, Tvalue>* thisnode)
//{
//		if (node)
//		{
//			BNode<Tkey, Tvalue> thisnode = new BNode<Tkey, Tvalue>;
//			thisnode->value = node->value;
//			//Надо с собой нести прев, чтобы указывать на уже новосозданный объект, у которого память выделена.
//			//Иначе пизда.
//		}
//
//	traverseCOPY(node->left, thisnode->left);
//	traverseCOPY(node->right, thisnode->right);
//}
//*/
//template<typename Tkey, typename Tvalue>
//int AVL<Tkey, Tvalue>::Balance(BNode<Tkey, Tvalue>* node)
//{
//	if ((node->right != NULL) && (node->left != NULL))
//	{
//		return node->right->height - node->left->height;
//	}
//	else
//	{
//		if ((node->right != NULL) && (node->left == NULL))
//		{
//			return node->right->height;
//		}
//		else
//		{
//			if ((node->right == NULL) && (node->left != NULL))
//			{
//				return node->left->height;
//			}
//		}
//	}
//
//}
//template<typename Tkey, typename Tvalue>
//void AVL<Tkey,Tvalue>::FixHeight(BNode<Tkey,Tvalue>* node)
//{
//
//	if ((node->right != NULL) && (node->left != NULL))
//	{
//		node->height = max(node->left->height, node->right->height) + 1;
//	}
//	else
//	{
//		if ((node->right != NULL) && (node->left == NULL))
//		{
//			node->height = node->left->height + 1;
//		}
//		else
//		{
//			if ((node->right == NULL) && (node->left != NULL))
//			{
//				node->height = node->right->height + 1;
//			}
//		}
//	}
//
//}
//template<typename Tkey, typename Tvalue>
//int AVL<Tkey,Tvalue>::max(int one, int two)
//{
//	if (one > two)
//	{
//		return one;
//	}
//	else
//		return two;
//}
//
//template<typename Tkey, typename Tvalue>
//void AVL<Tkey,Tvalue>::Put(Tkey key,Tvalue value)
//{
//	PutStart(key, value, root);
//}
//template<typename Tkey, typename Tvalue>
//void AVL<Tkey, Tvalue>::PutStart(Tkey key, Tvalue value, BNode<Tkey,Tvalue>* node)
//{
//	if (key < node->key)
//	{
//		if (node->left != NULL)
//		{
//			PutStart(key, value, node->left);
//		}
//		else
//		{
//			node->left = new BNode<Tkey, Tvalue>;
//			node->left->key = key;
//			node->left->value = value;
//			node->left->left = NULL;
//			node->left->right = NULL;
//			node->left->height = 0;
//			DoBalance(node->left);
//		}
//	}
//	else
//	{
//		if (node->right != NULL)
//		{
//			PutStart(key, value, node->right);
//		}
//		else
//		{
//			node->right = new BNode<Tkey, Tvalue>;
//			node->right->key = key;
//			node->right->value = value;
//			node->right->left = NULL;
//			node->right->right = NULL;
//			node->right->height = 0;
//			DoBalance(node->right);
//		}
//	}
//
//}
//
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>* AVL<Tkey,Tvalue>::RotateRight(BNode<Tkey, Tvalue>* node)
//{
//	BNode<Tkey, Tvalue>* tmp = node->left;
//	node->left = tmp->right;
//	tmp->right = node;
//	FixHeight(node);
//	FixHeight(tmp);
//	return tmp;
//}
//template<typename Tkey, typename Tvalue>
//BNode<Tkey, Tvalue>* AVL<Tkey, Tvalue>::RotateLeft(BNode<Tkey, Tvalue>* node)
//{
//	BNode<Tkey, Tvalue>* tmp = node->right;
//	node->right = tmp->left;
//	tmp->left = node;
//	FixHeight(node);
//	FixHeight(tmp);
//	return tmp;
//}
//template<typename Tkey, typename Tvalue>
//void AVL<Tkey, Tvalue>::DoBalance(BNode<Tkey, Tvalue>* node)
//{
//	FixHeight(node);
//	if (Balance(node) == 2)
//	{
//		if (Balance(node->right) < 0)
//		{
//			node->right = RotateRight(node->right);
//		}
//		RotateLeft(node);
//	}
//	if (Balance(node) == -2)
//	{
//		if (Balance(node->left) > 0)
//		{
//			node->left = RotateLeft(node->left);
//		}
//		RotateRight(node);
//	}
//}