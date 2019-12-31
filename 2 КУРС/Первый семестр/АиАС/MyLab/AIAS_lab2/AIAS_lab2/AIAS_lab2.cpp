#include "pch.h"
#include <iostream>

using namespace std;

void Merge(int*& arr, int first, int last, int middle)
{
	int left = first;
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


void MergeSort(int*& arr, int size, int step)
{
	int i;
	for (i = 0; i <= size - step; i += step)
	{
		Merge(arr, i, i + step - 1, i + step / 2 - 1);
	}
	if ((size / step) % 2 != 0)
	{
		Merge(arr, i - step, size - 1, i - 1);
	}
	if (size >= step)
	{
		MergeSort(arr, size, step * 2);
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

	MergeSort(arr, n*k, 2*n);

	for (int i = 0; i < n*k; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
