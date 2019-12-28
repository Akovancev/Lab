#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

bool check_print = false;
stack <int> cycle;

int** Input(int** a, int n, int l)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < l; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = 1;
	}
	return a;
}

void Print()
{
	while (!cycle.empty())
	{
		cout << cycle.top() << " ";
		cycle.pop();
	}
}

bool Dfs(int st, int** a, int* dop, int n)
{
	dop[st] = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[st][i] != 0 && dop[i] == 1)
		{
			cout << "\n\nYES.\n";
			cycle.push(i + 1);
			check_print = true;
			return true;
		}
		if ((a[st][i] != 0) && (dop[i] == 0))
		{
			if (Dfs(i, a, dop, n))
			{
				cycle.push(i + 1);
				return true;
			}
		}
	}
	dop[st] = 0;
	return false;
}

void Check(int** a, int n)
{
	int* dop = new int[n]; 
	for (int i = 0; i < n; i++)
	{
		dop[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (dop[i] == 0)
		{
			Dfs(i, a, dop, n);
		}
	}
}

int main()
{
	int n,l;
	cin >> n >> l;
	int** a = new int*[n];
	a = Input(a, n, l);
	Check(a, n);
	if (!check_print)
	{
		cout << "\n\nNO.\n";
	}
	else
	{
		Print();
	}
	return 0;
}
