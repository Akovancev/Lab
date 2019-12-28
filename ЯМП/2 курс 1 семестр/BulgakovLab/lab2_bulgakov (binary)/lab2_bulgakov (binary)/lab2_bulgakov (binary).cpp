#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#define nfile 100

using namespace std;

/*
По данным, имеющимся в файле catalog.dat,
требуется занести в отдельный файл сведения о файлах,
размер которых превышает заданное число байтов.
Данные вводятся с клавиатуры.

Булгаков Ярослав
2 курс 62 группа

*/

struct Tfile {
	int size;
	string name, extansion, data;
};


// Функция генерации переменной типа Tfile ------------------------------------------
Tfile* Generate() {
	char name[5][8] = { "student","catalog","books","spisok","exams" };
	char r_name[4][8] = { "dat","txt","png","jpg" };
	Tfile* temp = new Tfile;
	temp->name = name[rand() % 5];
	temp->extansion = r_name[rand() % 4];
	int a = rand() % 30 + 1;
	temp->data = "";
	if (a < 10) temp->data += "0" + to_string(a) + ".";
	else temp->data += to_string(a) + ".";

	a = rand() % 12 + 1;
	if (a < 10) temp->data += "0" + to_string(a) + ".";
	else temp->data += to_string(a) + ".";
	temp->data += to_string(rand() % 100 + 1918);
	temp->size = rand() % 100000000 + 1;
	return temp;
}
// ---------------------------------------------------------------------------------


// Функция считывания переменной типа Tfile из файла-------------------------------
Tfile* Read_from_file(ifstream &f)
{
	Tfile* temp = new Tfile;
	f.read((char*)temp, sizeof(Tfile));
	return temp;
}
// ---------------------------------------------------------------------------------


// Функция вывода переменной типа Tfile в файл-----------------------------------
int Write_To_File(Tfile* temp, ofstream &f) {
	if (temp != NULL)
	{
		f.write((char*)temp, sizeof(Tfile));
		return 0;
	}
	else
		return 1;
}
// ---------------------------------------------------------------------------------


int main()
{
	setlocale(0, "");

	// Считываем с клавиатуры заданное число байтов ------------------------------------
	srand(time(NULL));
	cout << "Введите число байтов:" << endl;
	int check_size;
	cin >> check_size;
	// ---------------------------------------------------------------------------------


	// Генерируем файл catalog.txt ----------------------------------------------------
	ofstream f("catalog.txt", ios::binary || ios::out);
	if (!f) {
		cout << "Не удается открыть файл 1";
		return 1;
	}
	for (int i = 0; i < nfile; i++) Write_To_File(Generate(),f);
	f.close();
	// --------------------------------------------------------------------------------


	// Создаем входной и выходной потоки -----------------------------------------------
	ifstream input_file("catalog.txt", ios::binary || ios::in);
	if (!input_file) {
		cout << "Не удается открыть файл 2";
		return 1;
	}
	ofstream output_file("out_catalog.txt", ios::binary || ios::out);
	if (!output_file) {
		cout << "Не удается открыть файл 3";
		return 1;
	}
	// ---------------------------------------------------------------------------------


	/* ---------------------------------------------------------------------------------
	Считываем из файла catalog.txt данные и если они удовлетворяют условию
	то записываем данные в файл out_catalog.txt
	*/
	while (!input_file.eof()) {
		Tfile* temp = Read_from_file(input_file);
		if (check_size < temp->size)
		{
			Write_To_File(temp, output_file);
		}
	}
	// ---------------------------------------------------------------------------------

	input_file.close();
	output_file.close();
	system("pause");
	return 0;
}

