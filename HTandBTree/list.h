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
	~List();
	void Add(TNodeValueType _value);
	void RemoveByValueOnce(TNodeValueType _value);
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
List<TNodeValueType>::~List()
{
	if (head)
	{
		if (head->next != NULL)
		{
			delete head->next;
		}
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
