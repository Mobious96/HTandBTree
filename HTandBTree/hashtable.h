#pragma once
#include "pair.h"
#include "list.h"


template<typename Tkey, typename Tvalue>
class HTSepChain
{
public:
	int MaxRec;
	int CurRec;
	List<TPair<Tkey, Tvalue> >* table;

	HTSepChain();
	HTSepChain(int _MaxRec);
	~HTSepChain();
	int hash(Tkey key);
	void put(Tkey key, Tvalue value);
	Tvalue get(Tkey key);
};
template<typename Tkey, typename Tvalue>
HTSepChain<Tkey, Tvalue>::HTSepChain()
{
	table = new List<TPair<Tkey, Tvalue> >;
}
template<typename Tkey, typename Tvalue>
HTSepChain<Tkey, Tvalue>::HTSepChain(int _MaxRec)
{
	MaxRec = _MaxRec;
	table = new List<TPair<Tkey, Tvalue> >[MaxRec];
}
template<typename Tkey, typename Tvalue>
HTSepChain<Tkey, Tvalue>::~HTSepChain()
{
	delete[] table;
}

template<typename Tkey, typename Tvalue>
int HTSepChain<Tkey, Tvalue>::hash(Tkey key)
{
	if (typeid(key) == typeid(int))
	{
		return (int)((int)key % MaxRec);
	}
	try
	{
		if (typeid(key) == typeid(char*))
		{
			throw key;
		}
	}
	catch (char* e_key)
	{
		int length = 0;
		int i = 0;
		while (e_key[i])
		{
			length++;
			i++;
		}
		return length;
	}
	try
	{
		if (typeid(key) == typeid(double))
		{
			throw key;
		}
	}
	catch (double e_key)
	{
		if (e_key < 1)
		{
			return (int)(e_key * 10);
		}
		else
		{
			return (int)(fmod(e_key,10));
		}
	}
}

template<typename Tkey, typename Tvalue>
void HTSepChain<Tkey, Tvalue>::put(Tkey key, Tvalue value)
{
	int h = hash(key);
	TPair<Tkey, Tvalue> Pair(key, value);
	table[h].Add(Pair);
}
template<typename Tkey, typename Tvalue>
Tvalue HTSepChain<Tkey, Tvalue>::get(Tkey _key)
{
	int h = hash(_key);
	Node<TPair<Tkey, Tvalue> >* current = table[h].head;

	while (current != NULL)
	{
		if (current->value.key == _key)
		{
			return current->value.value;
		}
		current = current->next;
	}

}