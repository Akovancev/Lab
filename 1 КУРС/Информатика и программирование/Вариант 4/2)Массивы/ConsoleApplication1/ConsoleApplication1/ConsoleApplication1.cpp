#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, i = 0, j = 0, sum = 0;
	cout << "Enter the number of elements in the array" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "Enter array elements" << endl;

	while (i < n)
	{
		cin >> a[i];
        sum = sum + a[i];
		i++;
	}

	if (sum != 0)
	{
		int *b = new int[sum];

		i = 0;


		while (i < n)
		{
			while (a[i] != 0)
			{
				if (i % 2 == 0) b[j] = 0;
				else b[j] = 1;
				a[i]--;
				j++;
			}
			i++;
		}

		i = 0;

		while (i < sum)
		{
			cout << b[i] << " ";
			i++;
		}
	}

	else cout << "No elements" << endl;

	return 0;
}



