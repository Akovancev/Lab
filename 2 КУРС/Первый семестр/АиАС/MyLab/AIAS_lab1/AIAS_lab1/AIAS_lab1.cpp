#include "pch.h"
#include <iostream>
#define n 10

using namespace std; 

int a1(int *a) {
	int left = (a[0] * (a[1] * 10 + a[2]) + a[3] * a[4])*(a[5] * 100 + a[6] * 10 + a[7]);
	return left;
}

int a2(int *a) {
	int right = (a[8] * 10 + a[9]) * a[3] * (a[1] * 10 + a[2]);
	return right;
}

bool a3(int *a) {
	bool zero;
	if ( a[3] == 0 ) zero = true;
	else zero = false;
	return zero;
}

bool check(int *a) {
	bool found = false;
	if (!a3(a) && a1(a) == a2(a)) found = true;
	return found;
}

void P(int *a,int *dop, int k) {
	if (k == n) { 
		bool found = check(a);
		if (found) {
			char a_ch[11] = "ЦЕСДИЯТЬФР";
			for (int i = 0; i < n; i++) cout << a_ch[i] << '=' << a[i] << " ";
			cout << endl; 
		}
	}
	else
		for (int i = 0; i < n; i++) {
			if (dop[i] > 0) {
				a[k] = i;
				dop[i]--;
				P(a, dop, k+1);
				dop[i]++;
			}
		}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int *a = new int[n];
	int *dop=new int[n];
	for (int i = 0; i < n; i++) dop[i] = 1;   
	
	P(a, dop, 0);

	return 0;

}

