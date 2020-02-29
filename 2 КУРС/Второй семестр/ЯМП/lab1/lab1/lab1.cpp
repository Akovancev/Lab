#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int* Read(ifstream& f, int n)
{
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        f >> a[i];
    }
    return a;
}
void Write(ofstream& f, int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        f << a[i] << ' ';
    }
    f << endl;
}
int Multiple(int* a, int n)
{
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        m *= a[i];
    }
    return m;
}
int Create_file_and_Razm() {
    ifstream f("input.txt");
    ofstream f1("res.txt");
    int n = 0;
    int a;
    while (!f.eof())
    {
        f >> a;
        n++;
        f1 << a << ' ';
    }
    n = sqrt(n);
    return n;
}



void Partition(int count, int n) {
    ifstream f("res.txt");
    ofstream a("a.txt");
    ofstream b("b.txt");
    int* mas = Read(f, n);
    while (!f.eof()) {
        for (int i = 0; i < count && (!f.eof()); i++) {
            Write(a, mas, n);
            mas = Read(f, n);
        }
        for (int j = 0; j < count && !f.eof(); j++) {
            Write(b, mas, n);
            mas = Read(f, n);
        }
    }
    a.close();
    b.close();
    f.close();
}

void Merge(int count, int n)
{
    ifstream a("a.txt");
    ifstream b("b.txt");
    ofstream f("res.txt");
    int* mas1 = new int[n];
    int* mas2 = new int[n];
    if (!a.eof())
        mas1 = Read(a, n);
    if (!b.eof())
        mas2 = Read(b, n);
    while (!a.eof() && !b.eof())
    {
        int i = 0;
        int j = 0;
        while (i < count && j < count && !a.eof() && !b.eof())
        {
            if (Multiple(mas1, n) < Multiple(mas2, n))
            {
                Write(f, mas1, n);
                mas1 = Read(a, n);
                i++;
            }
            else
            {
                Write(f, mas2, n);
                mas2 = Read(b, n);
                j++;
            }
        }
        while (i < count && !a.eof())
        {
            Write(f, mas1, n);
            mas1 = Read(a, n);
            i++;
        }
        while (j < count && !b.eof()) {
            Write(f, mas2, n);
            mas2 = Read(b, n);
            j++;
        }
    }
    while (!a.eof())
    {
        Write(f, mas1, n);
        mas1 = Read(a, n);
    }
    while (!b.eof())
    {
        Write(f, mas2, n);
        mas2 = Read(b, n);
    }
    a.close();
    b.close();
    f.close();
}
int main()
{
    setlocale(0, "");
    int n = Create_file_and_Razm();
    cout << "Размерность матрицы:" << n << endl;
    for (int k = 1; k < n; k *= 2)
    {
        Partition(k, n);
        Merge(k, n);
    }
    cout << "Готово!";
    return 0;
}
