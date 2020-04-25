#include "pch.h"
#include <iostream>
#include <fstream>

const int n = 10;           // Количество строк и столбцов в таблице
int *result = new int[n];   // Массив для хранения кратчайшего пути
int min = 1000;             // Переменная для хранения величины кратчайшего пути


using namespace std;


// Считываем исходную таблицу из файла и выводим ее на экран
int** Read(ifstream &f) 
{

	int **a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "\n\n";
	return a;
}


// Выводим на экран ответ (кратчайший путь и его величину)
void Print()  
{
	cout << "Кратчайший путь: ";
	for (int i = 0; i < n; i++)
	{
		cout << result[i];
		if (i != n - 1) cout << " -> ";
		else cout << endl;
	}
	cout << "Длина кратчайшего пути: " << min << endl;

}


// Функция для подсчета величины кратчайшего пути   
int Sum(int **table, int *a)
{
	int sum=0;
	for (int i = 0; i < n - 1; i++)
		sum += table[a[i]][a[i + 1]];
	return sum;
}


// Функция перебора всех возможных перестановок (путей)
void Perestanovki(int *a, int *dop, int k, int **table) 
{
	
	if (k == n) 
	{
		int sum = Sum(table,a); // Вызываем функцию для подсчета величины кратчайшего пути 
		if (sum < min) 
		{
			min = sum;
			result = a;
		}
	}
	else
		for (int i = 0; i < n; i++) 
		{
			if (dop[i] > 0) {
				a[k] = i;
				dop[i]--;
				Perestanovki(a, dop, k + 1, table);
				dop[i]++;
			}
		}
}

int main()
{
	setlocale(0, "");
	ifstream input_file("input.txt");    // Переменная отвечающая за файл в котором хранится исходная таблица
	int **table = new int*[n];           // Переменная для хранения исходной таблицы
	for (int i = 0; i < n; i++)
	{
		table[i] = new int[n];
	}
	table = Read(input_file);            // Вызываем функцию чтения исходной таблицы из файла
	input_file.close();

	int *a = new int[n];                 
	int *dop = new int[n];               
	for (int i = 0; i < n; i++) dop[i] = 1;  


	Perestanovki(a, dop, 0, table);      
	Print();                             
	cout << endl;
	system("pause");
	return 0;
}
