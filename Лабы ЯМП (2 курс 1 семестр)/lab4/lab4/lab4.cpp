#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TList {
	char value;
	TList* next;
};

struct TQueue
{
	TList* head;   
	TList* tail;  
};

bool isEmpty(TQueue* q)
{
	return ((q->head == NULL) && (q->tail == NULL));
}

int initQueue(TQueue** q)
{
	(*q) = new TQueue;
 	(*q)->head = NULL;
	(*q)->tail = NULL;
	return 0;
}

int push(TQueue** q, char newValue)   
{
	if ((*q) == NULL)
		initQueue(q);
	TList* temp = new TList; 
	temp->value = newValue;   
	temp->next = NULL;
	if (isEmpty((*q)))
	{
		(*q)->tail = temp;
		(*q)->head = temp;
	}
	else
	{
		(*q)->tail->next = temp;
		(*q)->tail = temp;
	}
	return 0;
}

char pop(TQueue* q)
{
	if (!isEmpty(q))
	{
		char retValue;  
		retValue = q->head->value;
		q->head = q->head->next;
		if (q->head == NULL)
			q->tail = NULL;
		return retValue;  
	}
	else
		return -1;
}

int clearQueue(TQueue* q)
{
	while (!isEmpty(q))
		pop(q);
	return 0;
}

int Task(ifstream &f, ofstream &g)
{
	string temp;
	TQueue* other = NULL;
	TQueue* digits = NULL;
	while (!f.eof())
	{
		getline(f, temp);
		for (unsigned int i = 0; i < temp.length(); i++)
			if ('0' <= temp[i] && temp[i] <= '9')
				push(&digits, temp[i]);
			else
				push(&other, temp[i]);
		while (!isEmpty(other)) {
			g << pop(other);
		}
		while (!isEmpty(digits)) {
			g << pop(digits);
		}
		g << endl;
	}
	return 0;
}

int main()
{
	setlocale(0, "Russian");
	ifstream inputFile("input.txt");
	if (!inputFile) {
		cout << "Не удается открыть файл input.txt" << endl;
		return 1;
	}
	ofstream outputFile("output.txt");
	if (!outputFile) {
		cout << "Не удается открыть файл output.txt" << endl;
		return 1;
	}
	Task(inputFile, outputFile);
	inputFile.close();
	outputFile.close();
	return 0;
}