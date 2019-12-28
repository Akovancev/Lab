#include "pch.h"
#include <iostream>
#define n 2

using namespace std;

int count_zero(int *a, int m)
{
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i] == 0)
		{
			k++;
		}
	}
	return k;
}

bool check(int *a, int m)
{
	int count_0 = count_zero(a, m);
	int count_1 = m - count_0;
	return (count_0 % 2 != 0) && (count_1 - count_0 <= 3);
}

void Razm_SP(int *a, int m, int k)
{
	if (k == m)
	{
		if (check(a, m))
		{
			for (int i = 0; i < m; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			a[k] = i;
			Razm_SP(a, m, k + 1);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите m:\n";
	int m;
	cin >> m;

	int *a = new int[m];
	Razm_SP(a, m, 0);

	return 0;

}