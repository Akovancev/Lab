#include "pch.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#define nmarks 5
#define nsessions 8
#define nstudents 5

/*
Требуется занести в отдельный файл данные из файла student.txt,
добавив сведения о новых студентах.
Новые данные задаются вводом с клавиатуры.

Булгаков Ярослав
2 курс 62 группа

*/

using namespace std;
struct Tstudent // Описание структуры
{
	string FIO, exam_name;
	unsigned int nkurs, ngroup, exam_mark;
	int marks[nsessions][nmarks];
	bool study_form;
};


// Функция генерирующая файл student.txt ----------------------------------------------------
void Generate(ofstream &f) {

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
	f << name[rand() % 12] << endl;
	int nkurs = rand() % 4 + 1;
	f << nkurs << endl;
	f << rand() % 9 + 1 << endl;
	for (int i = 0; i < nkurs * 2; i++)
		for (int j = 0; j < nmarks; j++)
			f << rand() % 4 + 2 << " ";
	f << endl << rand() % 2 << endl;
	f << exam[rand() % 5] << endl;
	f << rand() % 4 + 1 << endl;
}
//-------------------------------------------------------------------------------------------


// Функция считывания данных из файла --------------------------------------------------------
Tstudent* Read_from_file(ifstream &f)
{
	Tstudent* temp = new Tstudent;
	string s;
	getline(f, temp->FIO);
	if (f.eof())
	{
		delete temp;
		return NULL;
	}
	f >> temp->nkurs;
	f >> temp->ngroup;
	for (int i = 0; i < temp->nkurs * 2; i++)
		for (int j = 0; j < nmarks; j++)
		{
			f >> temp->marks[i][j];
		}
	f >> temp->study_form;
	getline(f, s);
	getline(f, temp->exam_name);
	f >> temp->exam_mark;
	getline(f, s);
	return temp;
}
//-------------------------------------------------------------------------------------------


// Функция вывода структуры типа Tstudent в файл ---------------------------------------------
void Write_To_File(ofstream &f, Tstudent* st)
{
	f << st->FIO << endl;
	f << st->nkurs << endl;
	f << st->ngroup << endl;
	for (int i = 0; i < st->nkurs * 2; i++)
		for (int j = 0; j < nmarks; j++)
		{
			f << st->marks[i][j] << " ";
		}
	f << endl << st->study_form << endl;
	f << st->exam_name << endl;
	f << st->exam_mark << endl;
}
//-------------------------------------------------------------------------------------------


// Функция считывания данных с клавиатуры --------------------------------------------------------
Tstudent* Read_from_keyboard()
{
	string s;
	getline(cin, s);
	Tstudent* temp = new Tstudent;
	cout << "Введите ФИО студента ";
	getline(cin,temp->FIO);
	cout << "Введите номер курса ";
	cin >> temp->nkurs;
	cout << "Введите номер группы ";
	cin >> temp->ngroup;
	cout << "Введите оценки ";
	for (int i = 0; i < temp->nkurs * 2; i++)
		for (int j = 0; j < nmarks; j++)
			cin >> temp->marks[i][j];
	cout << "Введите форму обучение(1 - очная, 0 - заочная) ";
	cin >> temp->study_form;
	getline(cin, s);
	cout << "Введите название экзамена ";
	getline(cin, temp->exam_name);
	cout << "Введите оценку за экзамен ";
	cin >> temp->exam_mark;
	return temp;
}
//------------------------------------------------------------------------------------------------


int main()
{
	setlocale(0, "");

	// Генерируем файл student.txt -----------------------------------------------
	srand(time(NULL));
	ofstream f("student.txt");
	if (!f)
	{
		cout << "Не удается открыть файл";
		return 1;
	}
	for (int u = 0; u < nstudents; u++) Generate(f);
	f.close();
	//----------------------------------------------------------------------------

	ifstream input_file("student.txt");
	if (!input_file)
	{
		cout << "Не удается открыть файл";
		return 1;
	}
	ofstream output_file("out_student.txt");
	if (!output_file)
	{
		cout << "Не удается открыть файл";
		return 1;
	}

	// Записываем в выходной файл ("out_student.txt") данные из файла student.txt ----
	while (!input_file.eof())
	{
		Tstudent* st = Read_from_file(input_file);
		if (st != NULL) Write_To_File(output_file, st);
	}
	input_file.close();
	//--------------------------------------------------------------------------------

	// Считываем количество новых студентов ------------------------------------------
	cout << "Введите количество новых студентов: ";
	int nnewstudent;
	cin >> nnewstudent;
	//--------------------------------------------------------------------------------

	// Записываем в файл всех новых студентов ----------------------------------------
	for (int i = 0; i < nnewstudent; i++)
	{
		Write_To_File(output_file, Read_from_keyboard());
	}
	output_file.close();

	//---------------------------------------------------------------------------------

	cout << "\n\n";
	system("pause");
	return 0;
}
