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

int m = 9;
int n = 4;

using namespace std;
struct Tstudent // Описание структуры
{
	string FIO, exam_name;
	unsigned int nkurs, ngroup, exam_mark;
	int marks[nsessions][nmarks];
	bool study_form;
};


// Функция генерирующая файл student.txt ----------------------------------------------------
Tstudent* Generate() {

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
	temp->FIO = name[rand() % 12];
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
//-------------------------------------------------------------------------------------------


// Функция считывания данных из файла --------------------------------------------------------
Tstudent* Read_from_file(ifstream &f)
{
	Tstudent* temp = new Tstudent;
	f.read((char*)temp, sizeof(Tstudent));
	return temp;
}
//-------------------------------------------------------------------------------------------


// Функция вывода структуры типа Tstudent в файл ---------------------------------------------
int Write_to_file(Tstudent* st, ofstream &f) {
	if (st != NULL)
	{
		f.write((char*)st, sizeof(Tstudent));
		return 0;
	}
	else
		return 1;
}
//-------------------------------------------------------------------------------------------


// Функция считывания данных с клавиатуры --------------------------------------------------------
Tstudent* Read_from_keyboard()
{
	string s;
	getline(cin, s);
	Tstudent* temp = new Tstudent;
	cout << "Введите ФИО студента ";
	getline(cin, temp->FIO);
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
	ofstream f("student.txt", ios::binary || ios::out);
	if (!f)
	{
		cout << "Не удается открыть файл 1";
		return 1;
	}
	for (int u = 0; u < nstudents; u++) Write_to_file(Generate(), f);
	f.close();
	//----------------------------------------------------------------------------

	ifstream input_file("student.txt", ios::binary || ios::in);
	if (!input_file)
	{
		cout << "Не удается открыть файл 2";
		return 1;
	}
	ofstream output_file("out_student.txt", ios::binary || ios::out);
	if (!output_file)
	{
		cout << "Не удается открыть файл 3";
		return 1;
	}

	// Записываем в выходной файл ("out_student.txt") данные из файла student.txt ----
	while (!input_file.eof())
	{
		Tstudent* st = Read_from_file(input_file);
		if (st != NULL) Write_to_file(st, output_file);
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
		Write_to_file(Read_from_keyboard(), output_file);
	}
	output_file.close();
	//---------------------------------------------------------------------------------

	cout << "\n\n";
	system("pause");
	return 0;
}
