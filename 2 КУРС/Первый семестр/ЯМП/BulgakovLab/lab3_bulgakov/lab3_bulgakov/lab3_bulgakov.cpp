#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
	Определить является ли список L пустым

	Булгаков Ярослав 
	2 курс 62 группа

*/


// Описание структуры (список)
struct Node
{
	int data;
	Node* next;

	Node(int e, Node* l) // Метод структуры
	{
		data = e;
		next = l;
	}
};

// Функция считывания данных из файла
Node* Read_from_file(ifstream &f)
{
	// Пропускаем все пробелы и enter
	while (f.get() == ' ' || f.get() == '\n')
	{
		char x;
		f >> x;
	}
	// если далее символ конца файла то возвращаем NULL
	if (f.eof()) 
	{
		return NULL;
	}
	// иначе записываем все данные из файла в список
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


/* функция проверки является ли список пустым
	возвращает true если пустой,
	false если не пустой
*/
bool isEmpty(Node* l)
{
	return l == NULL;
}

int main()
{
	setlocale(0, "");

	ifstream input_file("input.txt");
	if (!input_file)
	{
		cout << "Не удается открыть файл";
		return 0;
	}


	Node* l = Read_from_file(input_file); // Считываем данные из файла в список l
	input_file.close();


	if (isEmpty(l)) // проверяем список l на пустоту (есть в нем хотя бы один элемент или нет
	{
		cout << "Список L пустой\n\n";
	}
	else
	{
		cout << "Список L не пустой\n\n";
	}

	system("pause");
	return 0;
}
