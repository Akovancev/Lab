#include "pch.h"
#include <iostream>

using namespace std;

int f(int x)
{
	if (x == 0) return 0;
	return x % 2 + f(x / 2);
}

int main()
{
	int n;
	cout << "Enter the number" << endl;
	cin >> n;
	int res = f(n);
	cout << res << endl;
}




