#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
	Функция подсчета количества слов,
	начинающихся с заданной приставки (с заданной последовательности букв).

	Булгаков Ярослав
	2 курс 62 группа
*/


// Описание структуры
struct vertex
{
	char data;
	bool flag_end = false; // переменная обозначающая конец слова
	vertex* brother;
	vertex* son;

	vertex(char ch, vertex* b, vertex* s)
	{
		data = ch;
		brother = b;
		son = s;
	}

};

// Функция добавления нового слова в дерево
void AddWord(vertex* &l, string str, int i)
{
	if (l == NULL)
	{
		l = new vertex(str[i], NULL, NULL);
		i++;
		if (i != str.length())
		{
			AddWord(l->son, str, i);
		}
		else
		{
			l->flag_end = true;
		}
	}
	else
	{
		if (l->data == str[i])
		{
			i++;
			if (i != str.length())
			{
				AddWord(l->son, str, i);
			}
			else
			{
				l->flag_end = true;
			}
		}
		else
		{
			AddWord(l->brother, str, i);
		}
	}
}

// Функция считывания дерева из файла
void Read(ifstream &f, vertex* &l)
{
	string str;
	while (!f.eof())
	{
		getline(f, str);
		AddWord(l, str, 0);
	}
}

// Функция подсчета количества слов с нужной приставкой
int Count(vertex* l, int count)
{
	if (l != NULL)
	{
		if (l->brother != NULL)
		{
			count = Count(l->brother, count);
		}
		if (l->son != NULL)
		{
			count = Count(l->son, count);
		}
		if (l->flag_end == true)
		{
			count++;
		}
	}
	return count;
}

// Функция поиска нужной приставки
void Search(vertex* l, string str)
{
	int i = 0;
	int count = 0;
	while (i != str.length() && l != NULL)
	{
		if (str[i] == l->data)
		{
			i++;
			if (i == str.length() && l->flag_end == true)
			{
				count++;
			}
			l = l->son;
		}
		else
		{
			l = l->brother;
		}
	}
	if (i == str.length())
	{
		cout << "Количество слов с заданной приставкой в тексте = " << Count(l, count) << "\n\n";
	}
	else
	{
		cout << "Нет слов с заданной приставкой\n\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream input_file("input.txt");
	if (!input_file)
	{
		cout << "Не удается открыть файл\n";
		return 1;
	}
	vertex* tree = NULL;
	Read(input_file, tree);
	cout << "Введите приставку: ";
	string pref;
	cin >> pref;
	cout << endl;
	Search(tree, pref);
	return 0;
}
