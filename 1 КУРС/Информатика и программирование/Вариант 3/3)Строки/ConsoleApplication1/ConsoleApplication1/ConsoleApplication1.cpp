#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter string" << endl;
	string str,slovo,res;

	slovo = "";
	res = "";
	getline(cin, str);

	int n = str.length();


	for (int i = 0; i < n; i++)
	{
		if (str[i] != ' ') slovo = slovo + str[i];
		else
			if (slovo != "")
			{
				res = slovo + ' ' + res;
				slovo = "";
			}
	}
	
	res = slovo + ' ' +  res ;


	cout << res;



	return 0;

	


}