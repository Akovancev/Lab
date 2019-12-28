#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
   Входит ли атом А в список L (16.32а)

   Акованцев Павел 
   2 курс 62 группа

*/

struct Element
{
	string atom;
	Element* next;
};

struct List
{
	Element* data;
	List* next;
};


string CurentItem(string str, int pos)
{
	int i = pos + 1;
	while (i < str.length() && str[i] != ' ' && str[i] != '\0' && str[i] != '\n') i++;
	return str.substr(pos, i - pos);
}

Element* ReadElement(ifstream &f)
{
	Element* temp = new Element;
	Element* temp1 = new Element;
	Element* result = temp;
	string str;
	getline(f, str);
	int pos = 0;
	temp->atom = CurentItem(str, pos);
	while (pos < str.length() && str[pos] != ' ' && str[pos] != '\0' && str[pos] != '\n') pos++;
	pos++;
	temp->next = NULL;
	while (pos <= str.length())
	{
		temp1 = temp;
		temp = new Element;
		temp1->next = temp;
		temp->atom = CurentItem(str, pos);
		while (pos < str.length() && str[pos] != ' ' && str[pos] != '\0' && str[pos] != '\n') pos++;
		pos++;
		temp->next = NULL;
	}
	return result;
}

List* Read(ifstream &f)
{
	List* temp = new List;
	List* temp1 = new List;
	List* result = temp;
	temp->data = ReadElement(f);
	temp->next = NULL;
	while (!f.eof())
	{
		temp1 = temp;
		temp = new List;
		temp1->next = temp;
		temp->data = ReadElement(f);
		temp->next = NULL;
	}
	return result;
}

bool Check(List* l, string str)
{
	bool found = false;
	while (!found && l != NULL)
	{
		Element* b = l->data;
		while (!found && b != NULL)
		{
			if (b->atom == str) found = true;
			else b = b->next;
		}
		l = l->next;
	}
	return found;
}

int main()
{
	setlocale(0, "");
	ifstream input_file("input.txt");
	if (!input_file)
	{
		cout << "Не удается открыть файл\n";
		return 1;
	}
	List* l = Read(input_file);
	cout << "Введите атом А: ";
	string str;
	cin >> str;
	if (Check(l, str)) cout << "Атом А входит в список L\n\n";
	else cout << "Атом А не входит в список L\n\n";
	system("pause");
	return 0;
}


