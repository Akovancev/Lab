#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, i = 0, min = 0, count = 0;
	cout << "Enter the number of elements in the array" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "Enter array elements" << endl;

	while (i < n)
	{
		cin >> a[i];
		i++;
	}

	i = 1;
	min = a[0];

	while (i < n)
	{
		if (a[i] < min) min = a[i];
		i++;
	}

	i = 0;

	while (i < n)
	{
		if (a[i] - min == 5) count++;
		i++;
	}

	cout << count;

	return 0;
}

