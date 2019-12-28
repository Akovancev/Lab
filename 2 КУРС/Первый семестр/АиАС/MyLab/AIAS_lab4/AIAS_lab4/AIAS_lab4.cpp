#include "pch.h"
#include <iostream>

using namespace std;

long long** Input(int n, int k)
{
	long long** d = new long long*[2 * n];
	for (int i = 0; i <= 2 * n - 1; i++)
	{
		d[i] = new long long[k + 1];
	}
	for (int i = 0; i <= 2 * n - 1; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			d[i][j] = 0;
		}
	}
	for (int i = 0; i <= 2 * n - 1; i++)
	{
		d[i][0] = 1;
	}
	d[1][1] = 1;
	return d;
}

int CountCells(int i)
{
	if (i % 2 == 1)
	{
		return i / 4 * 2 + 1;
	}
	else
	{
		return (i - 1) / 4 * 2 + 2;
	}
}

long long Counter(long long** d, int n, int k)
{
	for (int i = 2; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			d[i][j] = d[i - 2][j] + d[i - 2][j - 1] * (CountCells(i) - j + 1);
		}
	}

	long long result = 0;
	for (int i = 0; i <= k; i++)
	{
		result += d[n * 2 - 1][i] * d[n * 2 - 2][k - i];
	}
	return result;
}

int main()
{
	int n, k;
	cin >> n >> k;
	while (n != 0 || k != 0)
	{
		if (k >= 2 * n - 1)
		{
			cout << "0" << "\n\n";
		}
		else
		{		
			cout << Counter(Input(n,k),n,k) << "\n\n";
		}
		cin >> n >> k;
	}
	return 0;
}