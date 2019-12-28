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

Tfile* Generate(ofstream &f) {
	char name[5][8] = { "student","catalog","books","spisok","exams" };
	char r_name[4][8] = { "dat","txt","png","jpg" };
	Tfile* temp = new Tfile;
	temp->name = name[rand() % 5];
	temp->extansion = r_name[rand() % 4];
	int a = rand() % 30 + 1;
	temp->data = "";
	if (a < 10) temp->data +="0" + to_string(a) + ".";
	else temp->data += to_string(a) + ".";

	a = rand() % 12 + 1;
	if (a < 10) temp->data += "0" + to_string(a) + ".";
	else temp->data += to_string(a) + ".";
	temp->data += to_string(rand() % 100 + 1918);
	temp->size = rand() % 100000000 + 1;
	return temp;
}


int Write(Tfile* temp, ofstream &f) {
	if (temp != NULL)
	{
		f.write((char*)temp, sizeof(Tfile));
		return 0;
	}
	else
		return 1;
}


Tfile* Read_from_file(ifstream &f)
{
	Tfile* temp = new Tfile;
	f.read((char*)temp, sizeof(Tfile));
	return temp;
}

int Write_To_File(Tfile* temp, ofstream &f) {
	if (temp != NULL)
	{
		f.write((char*)temp, sizeof(Tfile));
		return 0;
	}
	else
		return 1;
}


int main()
{
	setlocale(0, "");
	cout << "Введите расширение файла:" << endl;
	string check_ext;
	cin >> check_ext;

	ofstream f("catalog.txt", ios::binary | ios::out);
	if (!f) {
		cout << "Не удается открыть файл";
		return 1;
	}

	srand(time(NULL));

	for (int i = 0; i < nfile; i++) Write(Generate(f),f);
	f.close();

	ifstream input_file("catalog.txt", ios::binary | ios::in);
	if (!input_file) {
		cout << "Не удается открыть файл";
		return 1;
	}
	ofstream output_file("out_catalog.txt", ios::binary | ios::out);
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

