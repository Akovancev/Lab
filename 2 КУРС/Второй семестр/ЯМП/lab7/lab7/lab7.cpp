#include <iostream>
#include <fstream>
using namespace std;

int min(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (a > b)
        return b;
    else
        return a;
}

void ReadData(int** a, ifstream& f, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f >> a[i][j];
        }
    }
    f.close();
}

void Floyd(int** a, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            { 
                if (a[i][k] != 0 && a[k][j] != 0 && i != j)
                {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }
}

void Write(int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    setlocale(0, "");
    ifstream f("in.txt");
    int n;
    f >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    ReadData(a, f, n);
    Floyd(a, n);
    Write(a,n);
    return 0;
}