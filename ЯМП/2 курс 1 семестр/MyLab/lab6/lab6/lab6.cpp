#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

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
			vertex* temp=new vertex(j, NULL, NULL);
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

int Result(vertex* temp)
{
	while (temp->left != NULL || temp->right != NULL)
	{
		if (temp->left != NULL)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return temp->data;
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
	int q;
	vertex* tree = NULL;
	while (!in_file.eof())
	{
		in_file >> q;
		tree = Add(q, tree);
	}
	in_file.close();
	
	cout << "E = " << Result(tree) << "\n\n";
	return 0;
}
