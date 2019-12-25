/*
   Вычисляет значение дерева (17.13а)

   Акованцев Павел 
   2 курс 62 группа

*/

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;


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

vertex* g = NULL;

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

int Value(vertex* g)
{
	char q = g->data;
	if (q >= '0' && q <= '9')
	{
		return q - '0';
	}
	else
	{
		if (q == '+')
		{
			return Value(g->left) + Value(g->right);
		}
		if (q == '-')
		{
			return Value(g->left) - Value(g->right);
		}
		if (q == '*')
		{
			return Value(g->left) * Value(g->right);
		}
		if (q == '/')
		{
			return Value(g->left) / Value(g->right);
		}
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

	cout << "T = " << Value(tree) << "\n\n";

	return 0;
}
