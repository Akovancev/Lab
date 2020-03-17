#include <iostream>
#define m 2

using namespace std;

bool Check(int* a, int n)
{
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == 1 && a[i] == a[i + 1])
		{
			check = false;
			break;
		}
	}
	return check;
}

void Razm_SP(int* a, int n, int k)
{
	if (k == n)
	{
		if (Check(a, n))
		{
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << ' ';
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			a[k] = i;
			Razm_SP(a, n, k + 1);
		}
	}
}

int main()
{
    setlocale(0, "");
    cout << "Введите N: ";
    int n;
    cin >> n;
	int* a = new int[n];
	Razm_SP(a, n, 0);
    return 0;
}