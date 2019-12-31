#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

void Merge(int*& arr, int first, int last)
{
	int left = first;
	int j = first;
	while (arr[j] <= arr[j + 1])
	{
		j++;
	}
	int middle = j;
	int right = middle + 1;
	int* a = new int[last - first + 1];

	for (int i = first; i <= last; i++)
	{
		if ((left <= middle) && ((right > last) || (arr[left] < arr[right])))
		{
			a[i - first] = arr[left];
			left++;
		}
		else
		{
			a[i - first] = arr[right];
			right++;
		}
	}

	for (int i = first; i <= last; i++)
	{
		arr[i] = a[i - first];
	}
}

int main()
{
	setlocale(0, "");
	int n, k;
	cout << "Введите n и k: ";
	cin >> n >> k;
	cout << endl;
	cout << "Введите " << k << " массивов из " << n << " элементов\n";
	int* arr = new int[n*k];

	for (int i = 0; i < n*k; i++)
	{
		cin >> arr[i];
	}

	int size = n * k;

	for (int step = 2 * n; step <= size; step *= 2)
	{
		int i;
		for (i = 0; i <= size - step; i += step)
		{
			Merge(arr, i, i + step - 1);
		}
		if ((size / step) % 2 != 0)
		{
			Merge(arr, i - step, size - 1);
		}
	}
	
	for (int i = 0; i < n*k; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}