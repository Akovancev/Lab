﻿/* По данным, имеющимся в файле student.dat,
требуется определить и вывести на экран количество студентов,
обучающихся на каждом курсе и в каждой группе. Результат представить в виде таблицы.
*/
#include "pch.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#define nmarks 5
#define nsessions 8
#define nstudents 100

int m = 9;
int n = 4;

using namespace std;
struct Tstudent
{
	string FIO, exam_name;
	unsigned int nkurs, ngroup, exam_mark;
	int marks[nsessions][nmarks];
	bool study_form;
};


Tstudent* Generate(ofstream &f) {
	
	char name[12][40] = {
		"Акованцев Павел Максимович",
		"Аксянов Даниил Владимирович",
		"Булгаков Ярослав Сергеевич",
		"Гладких Александр Владимирович",
		"Гудков Василий Михайлович",
		"Желтяков Михаил Александрович",
		"Иванников Никита Сергеевич",
		"Качалкова Дарья Сергеевна",
		"Ковалёв Данил Юрьевич",
		"Корон Данил Евгеньевич",
		"Кракова Софья Павловна",
		"Панькин Дмитрий Владимирович"
	};
	char exam[5][10] = {
		"МЛиТА",
		"ЯМП",
		"АиАС",
		"ТВ",
		"МА"
	};
	Tstudent* temp = new Tstudent;
	temp->FIO = name[rand()%12];
	temp->nkurs = rand() % 4 + 1;
	temp->ngroup = rand() % 9 + 1;
	for (int i = 0; i < temp->nkurs * 2; i++)
		for (int j = 0; j < nmarks; j++)
			temp->marks[i][j] = rand() % 4 + 2;
	temp->study_form = rand() % 2;
	temp->exam_name = exam[rand() % 5];
	temp->exam_mark = rand() % 4 + 1;
	return temp;
}

int Write_to_file(Tstudent* st, ofstream &f) {
	if (st != NULL)
	{
		f.write((char*)st, sizeof(Tstudent));
		return 0;
	}
	else
		return 1;
}


Tstudent* Read_from_file(ifstream &f)
{
	Tstudent* temp = new Tstudent;
	f.read((char*)temp, sizeof(Tstudent));
	return temp;
}

int** Counter(Tstudent* st, int **a, int m) {

	for (int i = 1; i <= m; i++)
		if (st != NULL && a[0][i] == st->ngroup) a[st->nkurs][i]++;
	return a;
}

void Write(int **a, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			cout << a[i][j] << ' ';
		if (i == 0) cout << "Группы" << endl;
		else if (i == n) cout << "\nК\nу\nр\nс\n";
		else cout << endl;
	}

}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	ofstream f("student.txt", ios::binary | ios::out);
	if (!f)
	{
		cout << "Не удается открыть файл";
		return 1;
	}
	for (int u = 0; u < nstudents; u++) Write_to_file(Generate(f),f);
	f.close();

	ifstream input_file("student.txt", ios::binary | ios::in);
	if (!input_file)
	{
		cout << "Не удается открыть файл";
		return 1;
	}
	
	int **a = new int*[n + 1];
	for (int i = 0; i <= n; i++) a[i] = new int[m + 1];
	for (int i = 1; i <= m; i++) a[0][i]=i;
	for (int i = 1; i <= n; i++) a[i][0] = i;
	a[0][0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = 0;

	while (!input_file.eof())
	{
		a = Counter(Read_from_file(input_file), a, m);
	}

	input_file.close();
	Write(a, m);
	system("pause");
	return 0;
}
