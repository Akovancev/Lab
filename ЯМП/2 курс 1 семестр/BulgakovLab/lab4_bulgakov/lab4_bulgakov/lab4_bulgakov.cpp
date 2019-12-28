#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
	Напечатать элементы файла f в следующем порядке:
	Сначала все числа, меньшие a, затем все числа из отрезка [a,b],
	после все остальные числа.
	Сохранить исходный порядок чисел во всех трех группах.

	Булгаков Ярослав
	2 курс 62 группа

*/

struct TList
{
	int data;
	TList* next;
};

struct TQueue
{
	TList* head; // указатель на голову 
	TList* tail; // указатель на хвост
};

// Функция проверки пустоты очереди (пустая очередь или нет)
bool isEmpty(TQueue* q)
{
	return ((q->head == NULL) && (q->tail == NULL));
}

// Функция создания очереди
int initQueue(TQueue*& q)
{
	q = new TQueue;
	q->head = NULL;
	q->tail = NULL;
	return 0;
}

// Функция добавления элемента в очередь
int push(TQueue*& q, int newValue)
{
	if (q == NULL)
		initQueue(q);
	TList* temp = new TList;
	temp->data = newValue;
	temp->next = NULL;
	if (isEmpty(q))
	{
		q->tail = temp;
		q->head = temp;
	}
	else
	{
		q->tail->next = temp;
		q->tail = temp;
	}
	return 0;
}

// Функция выталкивания элемента из очереди
int pop(TQueue* q)
{
	if (!isEmpty(q))
	{
		int retValue;
		retValue = q->head->data;
		q->head = q->head->next;
		if (q->head == NULL)
			q->tail = NULL;
		return retValue;
	}
	else
		return -1;
}

// Функция очистки очереди
int clearQueue(TQueue* q)
{
	while (!isEmpty(q))
		pop(q);
	return 0;
}

int Task(ifstream &f, int a, int b)
{
	int temp;
	// Инициализируем три очереди
	TQueue* first = NULL;
	TQueue* second = NULL;
	TQueue* third = NULL;
	while (!f.eof())
	{
		f >> temp;
		if (temp < a)
		{
			push(first, temp); // если число меньше а, то закидываем его в первую очередь
		}
		else
		{
			if (temp <= b)
			{
				push(second, temp); // если число принадлежит отрезку [a,b], то во вторую очередь
			}
			else
			{
				push(third, temp); // иначе в третью
			}
		}
	}
	while (first != NULL && !isEmpty(first)) // выводим сначала все элементы из первой очереди
	{
		cout << pop(first) << " ";
	}
	while (second != NULL && !isEmpty(second)) // затем из второй
	{
		cout << pop(second) << " ";
	}
	while (third != NULL && !isEmpty(third)) // и наконец из третьей
	{
		cout << pop(third) << " ";
	}
	cout << endl;
		
	return 0;
}

int main()
{
	setlocale(0, "");
	ifstream inputFile("input.txt");
	if (!inputFile) {
		cout << "Не удается открыть файл input.txt" << endl;
		return 1;
	}


	int a, b;
	cout << "Введите a и b: ";
	cin >> a >> b;
	Task(inputFile, a, b);
	inputFile.close();
	return 0;
}