#include "pch.h"
#include <iostream>

using namespace std;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	setlocale(0, "");
	int t = 1;
	//cin >> t;
	for (int u = 0; u < t; u++)
	{
		int d, n;
		cin >> n >> d;
		int* a = new int[(n+2)*2];
		a[0] = a[1] = 0;
		int j = 2;
		for (int i = 0; i < n; i++)
		{
			int m;
			char s;
			cin >> s >> m;
			if (s == 'B')
			{
				a[j] = abs(m);
				j++;
			}
			a[j] = abs(m);
			j++;
		}
		a[j] = a[j + 1] = d;
		j += 2;
		int max = 0;
		for (int i = 2; i < j; i += 2)
		{
			max = Max(max, a[i] - a[i - 2]);
		}
		for (int i = 3; i < j; i += 2)
		{
			max = Max(max, a[i] - a[i - 2]);
		}
		cout << max << endl;
	}
	return 0;
}
