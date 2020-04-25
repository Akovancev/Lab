#include <iostream>
#include <fstream>
#include <time.h>
#define N_MAX 26

using namespace std;

struct Operator
{
    char left;
    char first;
    char second;
    char sign;
    bool empty;
};

Operator Generate(char* a, int n)
{
    Operator p;
    if (rand() % 10 < 1)
    {
        p.empty = true;
        p.first = NULL;
        p.left = NULL;
        p.second = NULL;
        p.sign = NULL;
        return p;
    }
    p.empty = false;
    p.left = a[rand() % n];
    p.first = a[rand() % n];
    p.second = a[rand() % n];
    char mas[4] = { '+','-','*','/' };
    p.sign = mas[rand() % 4];
    return p;
}

void Write(Operator p)
{
    if (p.empty)
    {
        cout << '&' << endl;
    }
    else
    {
        cout << p.left << " = " << p.first << ' ' << p.sign << ' ' << p.second << endl;
    }
}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    ifstream f("in.txt");
    char* a = new char[N_MAX];
    int k = rand() % 23 + 1;
    int n = 0;
    while (!f.eof())
    {
        char x;
        f >> x;
        a[n] = x;
        n++;
    }
    f.close();
    if (n == 0)
    {
        cout << "Введено пустое множество" << endl;
        return -1;
    }
    Operator* p = new Operator[k];
    for (int i = 0; i < k; i++)
    {
        p[i] = Generate(a, n);
    }
    for (int i = 0; i < k; i++)
    {
        Write(p[i]);
    }
    return 0;
}
