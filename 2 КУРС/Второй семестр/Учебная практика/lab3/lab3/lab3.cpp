#include <iostream>

using namespace std;
const int n = 3;
const int m = 5;

int Sum(int max)
{
    int sum = 0;
    while (max != 0)
    {
        sum += max % 10;
        max /= 10;
    }
    return sum;
}

void Sort(int X[n][m], int** pos)
{
    int dop[n];
    for (int i = 0; i < n; i++)
    {
        int max = X[i][0];
        for (int j = 1; j < m; j++)
        {
            if (X[i][j] > max)
            {
                max = X[i][j];
            }
        }
        dop[i] = Sum(max);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (dop[j] < dop[j + 1])
            {
                int temp = dop[j];
                dop[j] = dop[j + 1];
                dop[j + 1] = temp;
                int* templine = pos[j];
                pos[j] = pos[j + 1];
                pos[j + 1] = templine;
            }
        }
    }
}

int main()
{
    setlocale(0, "");
    int X[n][m];
    for (int i = 0; i < n; i++) // инициализация статического массива a
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Введите элемент (" << i + 1 << ", " << j + 1 << ")" << endl;
            cin >> X[i][j];
        }
    }
    int** pos = new int* [n];
    if (!pos)
    {
        cout << "Память не выделенна" << endl;
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        pos[i] = X[i];
    }
    cout << "Исходный массив:" << endl; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
    Sort(X, pos);
    cout << "Итоговый массив:" << endl; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << *((pos[i]) + j) << " ";
        }
        cout << endl;
    } 
    for (int i = 0; i < n; i++) 
    {
        delete[] pos[i];
    } 
    delete[] pos;
    return 0;
}
