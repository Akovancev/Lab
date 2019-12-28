#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
   Напечатать дерево формулу в виде  (17.13в)
   соответствующей формулы

   Булгаков Ярослав
   2 курс 62 группа

*/


// Описание структуры дерева
struct vertex
{
	char data;
	vertex* left;
	vertex* right;

	vertex(char q, vertex* l, vertex* r)
	{
		data = q;
		left = l;
		right = r;
	}
};

// Префиксное считывание дерево-формулы
vertex* Read(ifstream &f, vertex* g)
{
	char q;
	f >> q;
	if (q >= '0' && q <= '9')
	{
		g = new vertex(q, NULL, NULL);
	}
	else
	{
		g = new vertex(q, NULL, NULL);
		g->left = Read(f, g->left);
		g->right = Read(f, g->right);
	}
	return g;
}

// Функция выводы дерева-формулы в соответсвующей формулы (рекурсивная)
// (это мы решали в классе, если что; даже я к доске выходил на эту задачу)
void Print(vertex* &g)
{
	char q = g->data;
	if (q >= '0' && q <= '9')
	{
		cout << q; // если в текущей верщине цифра, то просто выводим ее
	}
	else
	{
		/*
			 если не цифра, значит это какой-то знак,
			 а следовательно ...
		*/
		cout << "("; // сначала открываем скобку
		Print(g->left); // затем выводим левую часть формулы, с помощью вызова этой же функции от левой ветки
		cout << q; // после печатаем наш знак
		Print(g->right); // затем выводим правую часть формулы, с помощью вызова этой же функции от правой ветки
		cout << ")"; // и закрываем скобку
	}
}

int main()
{
	setlocale(0, "");
	ifstream in_file("in.txt");
	if (!in_file.is_open())
	{
		cout << "Не удается открыть файл" << endl;
		return -1;
	}

	vertex* tree = NULL;
	tree = Read(in_file, tree);
	in_file.close();

	Print(tree);
	return 0;
}
