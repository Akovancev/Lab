#include "pch.h"
#include <iostream>

using namespace std;

int curr_color = 1;

void Painting(int st, int*& dop, int** a,int n)
{
	for (int i = 0; i < n; i++) 
	{
		if ((a[st][i] == 0) && (dop[i] == 0))
		{
			dop[i] = curr_color;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (dop[i] == curr_color && i != st)
		{
			for (int j = 0; j < n; j++)
			{
				if ((a[i][j] == 1) && (dop[j] == curr_color))
				{
					dop[j] = 0;
				}
			}
		}
	}
}

bool Check(int** a, int n)
{
	int* dop = new int[n];
	for (int i = 0; i < n; i++)
	{
		dop[i] = 0;
	}
	int i = 0;
	while (i < n && curr_color <= 3)
	{
		if (dop[i] == 0)
		{
			dop[i] = 1;
			Painting(i, dop, a, n);
			curr_color++;
		}
		i++;
	}
	return curr_color > 3;
}

int main()
{
	int n, l;
	cin >> n >> l;
	int** a = new int*[n];
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
		a[x-1][y-1]++;
		a[y-1][x-1]++;
	}

	if (!Check(a, n))
	{
		cout << "\n\nBICOLOURABLE.\n";
	}
	else
	{
		cout << "\n\nNOT BICOLOURABLE.\n";
	}

	return 0;
}
