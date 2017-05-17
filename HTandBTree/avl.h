#pragma once
#include "pair.h"

template<typename Tkey, typename Tvalue>
struct BNode
{
	Tkey key;
	Tvalue value;
	BNode* left;
	BNode* right;
	int height;
	BNode();
	BNode(Tkey _key, Tvalue _value);
	~BNode();
};
template<typename Tkey, typename Tvalue>
BNode<Tkey,Tvalue>::BNode()
{
}
template<typename Tkey, typename Tvalue>
BNode<Tkey, Tvalue>::BNode(Tkey _key, Tvalue _value)
{
	left = NULL;
	right = NULL;
	key = _key;
	value = _value;
}
template<typename Tkey, typename Tvalue>
BNode<Tkey, Tvalue>::~BNode()
{
}


template<typename Tkey, typename Tvalue>
struct AVL
{
	BNode<Tkey, Tvalue>* root;

	AVL();
	AVL(BNode<Tkey, Tvalue> *_root);
	AVL(Tkey key, Tvalue);
	~AVL();
	int Balance(BNode<Tkey, Tvalue>* node);
	void FixHeight(BNode<Tkey, Tvalue>* node);
	int max(int one, int two);
	void RotateRight(BNode<Tkey, Tvalue>* node);
	void Put(Tkey key, Tvalue value);
	void PutStart(Tkey key, Tvalue value, BNode<Tkey, Tvalue>* node);
};
template<typename Tkey, typename Tvalue>
AVL<Tkey, Tvalue>::AVL()
{
	root = NULL;
}
template<typename Tkey, typename Tvalue>
AVL<Tkey,Tvalue>::AVL(Tkey key, Tvalue value)
{
	root = new BNode<Tkey, Tvalue>;
	root->left = NULL;
	root->right = NULL;
	root->key = key;
	root->value = value;
}
template<typename Tkey, typename Tvalue>
AVL<Tkey,Tvalue>::AVL(BNode<Tkey,Tvalue> *_root)
{
	root->left = _root;
}
template<typename Tkey, typename Tvalue>
AVL<Tkey, Tvalue>::~AVL()
{
	if (root)
	{
		if (root->left != NULL)
			delete root->left;
		if (root->right != NULL)
			delete root->right;
	}
}
template<typename Tkey, typename Tvalue>
int AVL<Tkey, Tvalue>::Balance(BNode<Tkey, Tvalue>* node)
{
	return node->left->height - node->right->height;
}
template<typename Tkey, typename Tvalue>
void AVL<Tkey,Tvalue>::FixHeight(BNode<Tkey,Tvalue>* node)
{
	node->height = max(node->left->height, node->right->height) + 1;
}
template<typename Tkey, typename Tvalue>
int AVL<Tkey,Tvalue>::max(int one, int two)
{
	if (one > two)
	{
		return one;
	}
	else
		return two;
}

template<typename Tkey, typename Tvalue>
void AVL<Tkey,Tvalue>::Put(Tkey key,Tvalue value)
{
	PutStart(key, value, root);
}
template<typename Tkey, typename Tvalue>
void AVL<Tkey, Tvalue>::PutStart(Tkey key, Tvalue value, BNode<Tkey,Tvalue>* node)
{
	if (key < node->key)
	{
		if (node->left != NULL)
		{
			PutStart(key, value, node->left);
		}
		else
		{
			node->left = new BNode<Tkey, Tvalue>;
			node->left->key = key;
			node->left->value = value;
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
	else
	{
		if (node->right != NULL)
		{
			PutStart(key, value, node->right);
		}
		else
		{
			node->right = new BNode<Tkey, Tvalue>;
			node->right->key = key;
			node->right->value = value;
			node->right->left = NULL;
			node->right->right = NULL;
		}
	}
}

template<typename Tkey, typename Tvalue>
void AVL<Tkey,Tvalue>::RotateRight(BNode<Tkey, Tvalue>* node)
{
	BNode<Tkey, Tvalue>* tmp = node;
	node = node->left;
	tmp->left = node->right;
	node->right = tmp;
	FixHeight(node);
	FixHeight(node->right);
}
