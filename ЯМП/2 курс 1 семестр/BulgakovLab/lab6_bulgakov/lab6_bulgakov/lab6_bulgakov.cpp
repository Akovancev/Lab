#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
	Посчитать среднее аричметическое
	всех элементов непустого дерева

	Булгаков Ярослав
	2 курс 62 группа

*/

// Описываем структуру бинарного дерева
struct vertex
{
	int data;
	vertex* left;
	vertex* right;

	vertex(int q, vertex* l, vertex* r)
	{
		data = q;
		left = l;
		right = r;
	}
};

// Функция добавления элемента в дерево
vertex* Add(int j, vertex* f)
{
	if (f == NULL)
	{
		f = new vertex(j, NULL, NULL);
		return f;
	}
	if (f->data > j)
	{
		if (f->left)
		{
			Add(j, f->left);
		}
		else
		{
			vertex* temp = new vertex(j, NULL, NULL);
			f->left = temp;
		}
	}
	else
	{
		if (f->right)
		{
			Add(j, f->right);
		}
		else
		{
			vertex* temp = new vertex(j, NULL, NULL);
			f->right = temp;
		}
	}
	return f;
}

// Функция подсчета суммы элементов дерева (рекурсивная)
int Sum(vertex* g)
{
	if (g == NULL)
	{
		return 0; // если вершина пустая возвращаем 0
	}
	return g->data + Sum(g->left) + Sum(g->right); // к текущей вершине прибавляем значение правой и левой веток
}

// Функция подсчета количества элементов в дереве (рекурсивная)
int Count(vertex* g, int count)
{
	if (g == NULL)
	{
		return 0; // если вершина пустая возвращаем 0
	}
	// если вершина непустая то возвращаем 1 + значение левой и правой веток
	return 1 + Count(g->left, count) + Count(g->right, count);
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

	// Считывание дерева из файла
	int q;
	vertex* tree = NULL;
	while (!in_file.eof())
	{
		in_file >> q;
		tree = Add(q, tree);
	}
	in_file.close();

	// с помощью функций подсчета суммы и количества элементов дерева находим среднее арифметическое
	cout << "Среднее арифметическое = " << Sum(tree) / Count(tree, 0) << "\n\n";
	system("pause");
	return 0;
}
