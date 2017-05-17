#include "pair.h"
#include "list.h"
#include <stdio.h>
#include <iostream>
using namespace std;
void asdmain()
{
	
	
	TPair<int, int> a(1, 2);
	Node<TPair<int, int> > node(a);
	cout << node.value.value;

	//Пишу тесты, заливаю. Пишу лист, тесты, заливаю. 1 час максимум. Потом ХТ, потом деревья.
	//
//	List<int> list;
//	list.Add(2);
//	cout << list.head->value;
	cout << "ha";
}