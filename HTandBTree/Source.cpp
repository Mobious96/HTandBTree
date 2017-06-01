#include "pair.h"
#include "list.h"
#include "hashtable.h"
#include "BSTree.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void traverse(BNode<char*, char*>* node, int& count)
{
	if (node == NULL)
	{
		return;
	}
	traverse(node->left, count);
	traverse(node->right, count);
	count++;
}

List<TPair<char*, int> > tmp2;
void traverseTOP(BNode<char*, char*>* node)
{
	if (node == NULL)
	{
		return;
	}
	traverseTOP(node->left);
	traverseTOP(node->right);
	Node<TPair<char*, int> > *tmp2_current = tmp2.head;
	bool found = false;
	while (tmp2_current != NULL)
	{
		if (strcmp(tmp2_current->value.key, node->key) == 0)
		{
			//cout << "I've found!" << endl;
			tmp2_current->value.value++;
			found = true;
			break;
		}
		else
		{
			tmp2_current = tmp2_current->next;
		}
	}
	if (!found)
	{
		TPair<char*, int> pairtmp;
		pairtmp.key = node->key;
		pairtmp.value = 1;
		tmp2.Add(pairtmp);
	}
}
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	char *buff; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("text.txt"); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)

	//List<TPair<char, char*> > list;
	TPair<char*, char*> PairBuff;
	HTSepChain<char*, char*> HTable(11);
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		while (!fin.eof())
		{
			buff = new char[20];
			fin >> buff;
	
			cout << buff << endl;
			HTable.put(buff, buff);
			cout << HTable.hash(buff) << endl;

			/*
			PairBuff.value = new char[7];
			fin >> PairBuff.value; // считали слово, переместили указатель
			cout << "buf = " << PairBuff.value;
			list.Add(PairBuff);
			cout << " list head = "<< list.head->value.value << endl; // напечатали это слово
			*/
		}
		//cout << list.head->value.value << endl;
		fin.close(); // закрываем файл
	}
	//cout << HTable.get('a') << endl;
	for (int i = 0; i < HTable.MaxRec; i++)
	{
		if (!HTable.table[i].head) continue;
		int count = 0;
		Node<TPair<char*, char*> > *current = HTable.table[i].head;
		while (current->next != NULL)
		{
			count++;
			current = current->next;
		}
		cout << "[" << i << "] = " << count << endl;
	}

	List<TPair<char*, int> > tmp;
	for (int i = 0; i < HTable.MaxRec; i++)
	{
		if (!HTable.table[i].head) continue;
		int count = 0;
		Node<TPair<char*, char*> > *current = HTable.table[i].head;
		while (current != NULL)
		{
			Node<TPair<char*, int> > *tmp_current = tmp.head;
			bool found = false;
			while (tmp_current != NULL)
			{
				if (strcmp(tmp_current->value.key, current->value.key) == 0)
				{
					//cout << "I've found!" << endl;
					tmp_current->value.value++;
					found = true;
					break;
				}
				else
				{
					tmp_current = tmp_current->next;
				}
			}
			if (!found)
			{
				TPair<char*, int> pairtmp;
				pairtmp.key = current->value.key;
				pairtmp.value = 1;
				tmp.Add(pairtmp);
			}
			count++;
			current = current->next;
		}
		cout << "[" << i << "] = " << count << endl;
	}
	system("pause");
	while (tmp.head != NULL)
	{
		cout << "Top: " << tmp.head->value.key << " colide: " << tmp.head->value.value << " times" << endl;
		tmp.head = tmp.head->next;
	}

	system("pause");
	
	ifstream fin2("text.txt");
	BST<char*, char*> tree;
	if (!fin2.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		while (!fin2.eof())
		{
			buff = new char[20];
			fin2 >> buff;

			cout << buff << endl;
			tree.Put(buff, buff);
		}
		fin2.close(); // закрываем файл
	}
	int count = 0;
	traverse(tree.root, count);
	cout << "Tree: " << count;
	system("pause");
	traverseTOP(tree.root);
	while (tmp2.head != NULL)
	{
		cout << "Top: " << tmp2.head->value.key << " colide: " << tmp2.head->value.value << " times" << endl;
		tmp2.head = tmp2.head->next;
	}
	return 0;
}