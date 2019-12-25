#include "pch.h"
#include <iostream>
using namespace std;

struct TList
{
	int k;
	int e;
	TList* next;
};

int printMN(TList* temp)
{
	if (temp->e != 0)
		cout << temp->k << "x^" << temp->e;
	else
		cout << temp->k;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->e != 0)
			if (temp->k < 0)
				cout << temp->k << "x^" << temp->e;
			else
				cout << "+" << temp->k << "x^" << temp->e;
		else
			if (temp->k < 0)
				cout << temp->k;
			else
				cout << "+" << temp->k;
		temp = temp->next;
	}
	return 0;
}

TList* inputMN()
{
	TList* temp = new TList;
	TList* temp1 = new TList;
	TList* result = temp;
	cout << "Введите степень элемента многочлена ";
	cin >> temp->e;
	cout << "Введите коэффициент элемента многочлена ";
	cin >> temp->k;
	temp->next = NULL;
	while (temp->e != 0)
	{
		if (temp->k != 0)
			temp1 = temp;
		temp = new TList;
		temp1->next = temp;
		cout << "Введите степень элемента многочлена ";
		cin >> temp->e;
		cout << "Введите коэффициент элемента многочлена ";
		cin>>temp->k;
		temp->next = NULL;
	}
	return result;
}


void value(int x, TList* temp) {
	int res = 0;
	while (temp != NULL) {
		int m = temp->k;
		for (int i = 0; i < temp->e; i++) m *= x;
		res += m;
		temp = temp->next;
	}
	cout << " = " << res << endl;
}


int main()
{
	setlocale(0, "");
	TList* mn = NULL;
	int x;
	cout << "Введите x" << endl;
	cin >> x;
	cout << "Ввод многочлена:" << endl;
	mn = inputMN();
	cout << "Введенный многочлен: ";
	printMN(mn);
	value(x, mn);
	system("pause");
	return 0;
}