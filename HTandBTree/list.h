#pragma once
#include "pair.h"
#include <stdlib.h>

template<class TNodeValue>
struct Node
{
	Node* next;
	TNodeValue value; //need to store here TPair<typename Tkey, typename Tvalue>. Got C2512 error: no appropriate default consturctor available.
	Node();
	Node(TNodeValue _value);
	Node(Node<TNodeValue>& node);
	~Node();
	Node& operator=(Node &node);
};
template<typename TNodeValue>
Node<TNodeValue>::Node()
{
}
template<typename TNodeValue>
Node<TNodeValue>::Node(TNodeValue _value)
{
	next = NULL;
	value = _value;
}

template<typename TNodeValue>
Node<TNodeValue>::Node(Node<TNodeValue>& node)
{
	next = node.next;
	value = node.value;
}

template<typename TNodeValue>
Node<TNodeValue>::~Node()
{
}
template<typename TNodeValue>
Node<TNodeValue>& Node<TNodeValue>::operator=(Node<TNodeValue> &n)
{
	next = n.next;
	value = n.value;
	delete n;
	return *this;
}








template<typename TNodeValueType>
struct List
{
	Node<TNodeValueType>* head;
	List();
	List(TNodeValueType _value);
	List(List<TNodeValueType>& list);
	~List();
	void Add(TNodeValueType _value);
	void AddNode(Node<TNodeValueType>* node);
	void RemoveByValueOnce(TNodeValueType _value);
	Node<TNodeValueType> traverse(Node<TNodeValueType> *node);
};
template <typename TNodeValueType>
List<TNodeValueType>::List()
{
	//head = new Node<TNodeValueType>;
	head = NULL;
}
template <typename TNodeValueType>
List<TNodeValueType>::List(TNodeValueType _value)
{
	head = new Node<TNodeValueType>;
	head->value = _value;
	head->next = NULL;
}
template <typename TNodeValueType>
List<TNodeValueType>::List(List<TNodeValueType>& list)
{

	head = NULL;
	Node<TNodeValueType> *current = list.head;
	while (current != NULL)
	{
		AddNode(current);
		current = current->next;
	}


}

template <typename TNodeValueType>
Node<TNodeValueType> List<TNodeValueType>::traverse(Node<TNodeValueType> *node)
{
	if (node == NULL) return;

}

template <typename TNodeValueType>
List<TNodeValueType>::~List()
{
	if (head != NULL)
	{
		Node<TNodeValueType>* prev = head;
		while (head->next != NULL)
		{
			prev = head;
			head = head->next;
			delete prev;
		}
		delete head;
	}

}
template<typename TNodeValueType>
void List<TNodeValueType>::Add(TNodeValueType _value)
{
	Node<TNodeValueType>* nd = new Node<TNodeValueType>;
	nd->next = NULL;
	nd->value = _value;
	if (head == NULL)
	{
		head = nd;
	}
	else
	{
		Node<TNodeValueType>* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = nd;
	}
}
template<typename TNodeValueType>
void List<TNodeValueType>::AddNode(Node<TNodeValueType>* node)
{
	Node<TNodeValueType>* nd = new Node<TNodeValueType>;
	nd->next = NULL;
	nd->value = node->value;
	if (head == NULL)
	{
		head = nd;
	}
	else
	{
		Node<TNodeValueType>* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = nd;
	}
}
template<typename TNodeValueType>
void List<TNodeValueType>::RemoveByValueOnce(TNodeValueType _value)
{
	if (head != NULL)
	{
		Node<TNodeValueType>* prev = NULL;
		Node<TNodeValueType>* current = head;
		while (current->value != _value)
		{
			prev = current;
			current = current->next;
		};
		if (prev == NULL)
		{
			prev = head;
			head = head->next;
			delete prev;		
			return;
		}
		else
		{
			if (current->next == NULL)
			{
				prev->next = NULL;
				delete current;
				return;
			}
			else
			{
				prev->next = current->next;
				delete current;
				return;
			}
		}

		
	}
}
