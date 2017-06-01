#pragma once
#include "pair.h"

template<typename Tkey, typename Tvalue>
struct BNode
{
	Tkey key;
	Tvalue value;
	BNode* left;
	BNode* right;
	BNode();
	BNode(Tkey _key, Tvalue _value);
	~BNode();
};
template<typename Tkey, typename Tvalue>
BNode<Tkey, Tvalue>::BNode()
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
struct BST
{
	BNode<Tkey, Tvalue>* root;

	BST();
	BST(BNode<Tkey, Tvalue> *_root);
	BST(Tkey key, Tvalue);
	//BST(BST<Tkey, Tvalue>& tree);
	~BST();
	int max(int one, int two);
	void RotateRight(BNode<Tkey, Tvalue>* node);
	void Put(Tkey key, Tvalue value);
	void PutStart(Tkey key, Tvalue value, BNode<Tkey, Tvalue>* node);
	void traverseDEL(BNode<Tkey, Tvalue>* node);
	//void traverseCOPY(BNode<Tkey, Tvalue>* node, BNode<Tkey, Tvalue>* thisnode);
};
template<typename Tkey, typename Tvalue>
BST<Tkey, Tvalue>::BST()
{
	root = NULL;
}
template<typename Tkey, typename Tvalue>
BST<Tkey, Tvalue>::BST(Tkey key, Tvalue value)
{
	root = new BNode<Tkey, Tvalue>;
	root->left = NULL;
	root->right = NULL;
	root->key = key;
	root->value = value;
}
template<typename Tkey, typename Tvalue>
BST<Tkey, Tvalue>::BST(BNode<Tkey, Tvalue> *_root)
{
	root->left = _root->left;
	root->right = _root->right;
	root->value = _root->value;

}
/*
template<typename Tkey, typename Tvalue>
BST<Tkey, Tvalue>::BST(BST<Tkey, Tvalue>& tree)
{
traverseCOPY(tree->root, root);
}
*/
template<typename Tkey, typename Tvalue>
BST<Tkey, Tvalue>::~BST()
{
	/*
	if (root)
	{
	traverseDEL(root);
	}
	*/
}
template<typename Tkey, typename Tvalue>
void BST<Tkey, Tvalue>::traverseDEL(BNode<Tkey, Tvalue>* node)
{
	if (node == NULL)
	{
		return;
	}
	traverseDEL(node->left);
	traverseDEL(node->right);
	delete node;
}
/*
template<typename Tkey, typename Tvalue>
void BST<Tkey, Tvalue>::traverseCOPY(BNode<Tkey, Tvalue>* node, BNode<Tkey, Tvalue>* thisnode)
{
if (node)
{
BNode<Tkey, Tvalue> thisnode = new BNode<Tkey, Tvalue>;
thisnode->value = node->value;

}

traverseCOPY(node->left, thisnode->left);
traverseCOPY(node->right, thisnode->right);
}
*/

template<typename Tkey, typename Tvalue>
int BST<Tkey, Tvalue>::max(int one, int two)
{
	if (one > two)
	{
		return one;
	}
	else
		return two;
}

template<typename Tkey, typename Tvalue>
void BST<Tkey, Tvalue>::Put(Tkey key, Tvalue value)
{
	if (root)
	{
		PutStart(key, value, root);
	}
	else
	{
		root = new BNode<Tkey, Tvalue>(key, value);
	}
}
template<typename Tkey, typename Tvalue>
void BST<Tkey, Tvalue>::PutStart(Tkey key, Tvalue value, BNode<Tkey, Tvalue>* node)
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
void BST<Tkey, Tvalue>::RotateRight(BNode<Tkey, Tvalue>* node)
{
	BNode<Tkey, Tvalue>* tmp = node;
	node = node->left;
	tmp->left = node->right;
	node->right = tmp;
}