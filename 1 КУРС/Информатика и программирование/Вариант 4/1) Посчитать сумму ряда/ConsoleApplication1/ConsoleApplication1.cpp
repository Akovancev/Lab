#include "pch.h"
#include <iostream>

using namespace std;
int main()
{
	long double PI = 3.141592653589793, x = 0, y = 1, sign = 1;
	cout << "Enter the number of decimal places" << endl;
	int n;
	cin >> n;
	while (abs(x - PI)>pow(10,-(n+1)))
	{
		x = x + sign * (4 / y);
		y = y + 2;
		sign = -sign;
	}
	cout << x << endl;
	return 0;
}

