#include "pair.h"
#include "list.h"
#include "hashtable.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
	char *buff; // ����� �������������� �������� ������������ �� ����� ������
	ifstream fin("text.txt"); // (����� �� ���������� ��� �����)

	List<TPair<char, char*> > list;
	TPair<char, char*> PairBuff;
	HTSepChain<char, char*> HTable(11);
	if (!fin.is_open()) // ���� ���� �� ������
		cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
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
			fin >> PairBuff.value; // ������� �����, ����������� ���������
			cout << "buf = " << PairBuff.value;
			list.Add(PairBuff);
			cout << " list head = "<< list.head->value.value << endl; // ���������� ��� �����
			*/
		}
		//cout << list.head->value.value << endl;
		fin.close(); // ��������� ����
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