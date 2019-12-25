#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
   Функции вставки задаваемого узла в trie – дерево и вывода дерева (1)

   Акованцев Павел
   2 курс 62 группа

*/


struct vertex
{
	char data;
	bool flag_end = false;
	vertex* brother;
	vertex* son;

	vertex(char ch, vertex* b, vertex* s)
	{
		data = ch;
		brother = b;
		son = s;
	}

};

void Print(vertex* &l, string str)
{
	if (l->brother != NULL)
	{
		Print(l->brother, str);
	}
	if (l->son != NULL)
	{
		Print(l->son, str + l->data);
	}
	if (l->flag_end == true) 
	{
		cout << str << l->data << endl;
	}
}

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


void Read(ifstream &f, vertex* &l)
{
	string str;
	while (!f.eof())
	{
		getline(f, str);
		AddWord(l, str, 0);
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
	cout << "Введите новое слово: ";
	string str;
	cin >> str;
	cout << "\n\n";
	cout << "Исходное дерево: \n";
	Print(tree, "");
	cout << "\n\n";	
	cout << "Дерево с новым словом: \n";
	AddWord(tree, str, 0);
	Print(tree, "");
	return 0;
}