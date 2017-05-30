#include "pair.h"
#include "list.h"
#include "hashtable.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	char *buff; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("text.txt"); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)

	List<TPair<char, char*> > list;
	TPair<char, char*> PairBuff;
	HTSepChain<char, char*> HTable(11);
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		while (!fin.eof())
		{
			buff = new char[20];
			fin >> buff;
			cout << buff << endl;
			HTable.put(buff[0], buff);
			cout << HTable.hash(buff[0]) << endl;

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
	cout << HTable.get('a') << endl;
	for (int i = 0; i < HTable.MaxRec; i++)
	{
		int count = 0;
		Node<TPair<char, char*> > *current = HTable.table[i].head;
		while (current->next != NULL)
		{
			count++;
			current = current->next;
		}
		cout << "[" << i << "] = " << count<<endl;
	}
	system("pause");
	return 0;
}