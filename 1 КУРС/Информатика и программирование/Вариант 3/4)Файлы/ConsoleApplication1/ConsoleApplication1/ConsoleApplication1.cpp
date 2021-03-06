
#include "pch.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

int main()
{
	char x;
	int word, symbol, str, space;
	string text = "input.txt";
	bool flag = true;
	word = symbol = space = 0;
	str = 1;
	ifstream f;

	f.open(text);

	while (f.get(x))
	{
		if (x != ' ')
		{
			if (flag)
			{
				word++;
				flag = false;
			}
		}

		else
		{
			flag = true;
			space++;
		}
	    
		symbol++;

		if (x == '\n')
		{
			str++;
			flag = true;
		}
	}

	cout << "Number of characters with space: " << symbol - str +1 << endl << "Number of characters without space: " <<  symbol - space - str +1 << endl << "Number of words: " << word << endl << "Number of lines:  " << str << endl;

	f.close();
    return 0;
}
