#pragma once
#include "pair.h"
#include <stdlib.h>

template<typename TNodeValue>
struct Node
{
	Node* next;
	TNodeValue value;

	Node()
	{
		next = NULL;
		value = NULL;
	}
};

template<typename TNodeValueType>
struct List
{
	Node<TNodeValueType>* head;
	List();
	List(TNodeValueType _value);
	~List();
	void Add(TNodeValueType _value);
	TNodeValueType GetValue();

};
template <typename TNodeValueType>
List<TNodeValueType>::List()
{
	head = new Node<TNodeValueType>;
	head->next = NULL;
	head->value = NULL;
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
	delete head;
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
TNodeValueType List<TNodeValueType>::GetValue()
{
	return head->value;
}
