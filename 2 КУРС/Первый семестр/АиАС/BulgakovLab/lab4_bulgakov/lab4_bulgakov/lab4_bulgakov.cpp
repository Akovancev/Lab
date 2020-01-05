#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int** In_dop(int n)
{
	int** dop = new int*[n];
	for (int i = 0; i < n; i++)
	{
		dop[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dop[i][j] = 0;
		}
	}
	return dop;
}

bool check(int start, int finish, int** dop, string s)
{
	bool check = true;
	int c = 0;
	while (check && (c + start) <= (start + finish) / 2)
	{
		if (s[start + c] != s[finish - c])
		{
			check = false;
		}
		else
		{
			c++;
		}
	}
	return check;
}

int Counter(int** dop, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dop[i][j] == 1)
			{
				count++;
			}
		}
	}
	return count;
}

int Task(int** dop, string s, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (check(i, j, dop, s))
			{
				dop[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = i + 1; k < j - 1; k++)
			{
				if (dop[i][k] == 1 && dop[k + 1][j] == 1)
				{
					dop[i][j] = 1;
				}
			}
		}
	}
	return Counter(dop, n);
}

int main()
{
	setlocale(0, "");
	cout << "Введите строку: ";
	string s;
	cin >> s;
	cout << "Ответ: " << Task(In_dop(s.length()), s, s.length()) << endl;
	return 0;
}