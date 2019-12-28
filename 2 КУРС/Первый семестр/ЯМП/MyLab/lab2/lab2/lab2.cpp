/* По данным, имеющимся в файле catalog.dat, 
требуется занести в отдельный файл сведения о файлах с заданным расширением имени. 
Данные вводятся с клавиатуры.
*/
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#define nfile 100

using namespace std;

struct Tfile {
	unsigned int size;
	string name, extansion, data;
};

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

void Write_To_File(Tfile* temp,ofstream &f) {
	f << temp->name << endl;
	f << temp->extansion << endl;
	f << temp->data << endl;
	f << temp->size << endl;
}


int main()
{
	setlocale(0, "");
	cout << "Введите расширение файла:" << endl;
	string check_ext;
	cin >> check_ext;

	ofstream f("catalog.txt");
	if (!f) {
		cout << "Не удается открыть файл";
		return 1;
	}

	srand(time(NULL));

	for (int i = 0; i < nfile; i++) Generate(f);
	f.close();

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
	while (!input_file.eof()) {
		Tfile* temp = Read_from_file(input_file);
		if (check_ext == temp->extansion) Write_To_File(temp, output_file);
	}
	input_file.close();
	output_file.close();
	return 0;
}

