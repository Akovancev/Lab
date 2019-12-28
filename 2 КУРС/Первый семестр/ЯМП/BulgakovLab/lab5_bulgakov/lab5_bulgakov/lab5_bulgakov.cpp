#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
   Сформировать список L, включив в него по одному разу     (16.25а)
   элементы, которые входят хотя бы в один из списков L1 и L2

   Булгаков Ярослав
   2 курс 62 группа

*/

// описание структуры
struct Node
{
	int data;
	Node* next;

	Node(int q, Node* n) // метод структуры (нужен для инициализации)
	{
		data = q;
		next = n;
	}
};

// Функция считывания списка из файла
Node* ReadFromFile(ifstream &f)
{
	if (f.eof())
	{
		return NULL;
	}
	int e;
	f >> e;
	Node* temp = new Node(e, NULL);
	Node* temp1 = NULL;
	Node* result = temp;
	while (!f.eof())
	{
		temp1 = temp;
		f >> e;
		temp = new Node(e, NULL);
		temp1->next = temp;
	}
	return result;
}

// Функция проверки, входит ли элемент q в очередь l
bool Check(Node* &l, int q)
{
	bool found = false;
	while (l != NULL && !found)
	{
		if (l->data == q)
		{
			found = true;
		}
		else
		{
			l = l->next;
		}
	}
	return found;
}

// Функция формирования нового списка по заданному условию
Node* NewNode(Node* l1, Node* &l2)
{
	while (l2 != NULL)
	{
		Node* copy = l1; // Копируем список l1
		/*
			Проверяем каждый элемент из списка l2 на то,
			есть ли он в списке l1 или нет
			с помощью функции Check
		*/
		if (!Check(copy, l2->data))
		{
			Node* temp = new Node(l2->data, l1); // Если нет то добавляем этот элемент в начало списка l1
			l1 = temp;
		}
		l2 = l2->next; // Если есть то переходим к следующему элементу списка l2
	}
	return l1;
}

// Функция вывода списка на экран
void Print(Node* &l)
{
	while (l != NULL)
	{
		cout << l->data << " ";
		l = l->next;
	}
}

int main()
{
	setlocale(0, "");
	ifstream in_1("in1.txt");
	if (!in_1)
	{
		cout << "Не удается открыть файл\n";
		return 1;
	}
	ifstream in_2("in2.txt");
	if (!in_2)
	{
		cout << "Не удается открыть файл\n";
		return 1;
	}

	Node* L1 = ReadFromFile(in_1);
	Node* L2 = ReadFromFile(in_2);
	Node* L = NewNode(L1, L2);
	Print(L);

	return 0;
}


