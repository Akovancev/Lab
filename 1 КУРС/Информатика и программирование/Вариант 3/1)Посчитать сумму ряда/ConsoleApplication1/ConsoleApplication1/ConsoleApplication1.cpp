#include "pch.h"
#include <iostream>

using namespace std;
int main()
{
	long double PI = 3.141592653589793, x = 0, y = 1, p = 0,sign = 1;
	cout << "Enter the number of decimal places" << endl;
	int n;
	cin >> n;
	while (abs(x - PI/sqrt(12)) > pow(10, -(n + 1)))
	{
		x = x + sign * (1 / (y * pow(3,p)));
		y = y + 2;
		p++;
		sign = -sign;
	}

	x = x * sqrt(12);

	cout << x << endl;
	return 0;
}
