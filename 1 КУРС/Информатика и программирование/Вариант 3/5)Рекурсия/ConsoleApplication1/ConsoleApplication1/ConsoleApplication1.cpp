#include "pch.h"
#include <iostream>

using namespace std;

void f(int x)
{
	if (x > 1) f(x - 1);
	cout << x << ' ';
}

int main()
{
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	f(n);
}


