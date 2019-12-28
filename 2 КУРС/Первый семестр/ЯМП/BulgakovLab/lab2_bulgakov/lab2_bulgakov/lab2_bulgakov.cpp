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

// Описание структуры
struct Tfile {
	int size;
	string name, extansion, data;
};


// Функция генерации файла catalog.txt ------------------------------------------------
void Generate(ofstream &f) {
	char name[5][8] = { "student","catalog","books","spisok","exams" };
	char r_name[4][8] = { "dat","txt","png","jpg" };

	f << name[rand() % 5] << endl;
	f << r_name[rand() % 4] << endl;
	int a = rand() % 30 + 1;
	if (a < 10) f << '0' << a;
	else f << a;
	f << '.';
	a = rand() % 12 + 1;
	if (a < 10) f << '0' << a;
	else f << a;
	f << '.';
	f << rand() % 100 + 1918 << endl;
	f << rand() % 100000000 + 1 << endl;
}
//------------------------------------------------------------------------------------


// Функция считывания переменной типа Tfile из файла-------------------------------
Tfile* Read_from_file(ifstream &f) {
	Tfile* temp = new Tfile;
	string s;
	f >> temp->name;
	f >> temp->extansion;
	f >> temp->data;
	f >> temp->size;
	getline(f, s);
	return temp;
}
//--------------------------------------------------------------------------------------


// Функция вывода переменной типа Tfile в файл-----------------------------------
void Write_To_File(Tfile* temp, ofstream &f) {
	f << temp->name << endl;
	f << temp->extansion << endl;
	f << temp->data << endl;
	f << temp->size << endl;
}
//--------------------------------------------------------------------------------------


int main()
{
	setlocale(0, "");

	// Считываем с клавиатуры заданное число байтов ------------------------------------
	srand(time(NULL));
	cout << "Введите число байтов:" << endl;
	int check_size;
	cin >> check_size;
	//----------------------------------------------------------------------------------

	// Генерируем файл catalog.txt -----------------------------------------------------
	ofstream f("catalog.txt");
	if (!f) {
		cout << "Не удается открыть файл";
		return 1;
	}
	for (int i = 0; i < nfile; i++) Generate(f);
	f.close();
	//----------------------------------------------------------------------------------


	// Создаем входной и выходной потоки -----------------------------------------------
	ifstream input_file("catalog.txt");
	if (!input_file) {
		cout << "Не удается открыть файл";
		return 1;
	}
	ofstream output_file("out_catalog.txt");
	if (!output_file) {
		cout << "Не удается открыть файл";
		return 1;
	}
	//---------------------------------------------------------------------------------


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
	//---------------------------------------------------------------------------------


	input_file.close();
	output_file.close();
	system("pause");
	return 0;
}

