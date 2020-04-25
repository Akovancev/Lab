#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int n;
int m;

int Sum(int** a, int s)
{
    int* dop = new int[n];
    for (int i = 0; i < n; i++)
    {
        dop[i] = -1;
    }
    dop[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (a[t][i] != 0 && dop[i] == -1)
            {
                dop[i] = dop[t] + a[t][i];
                q.push(i);
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (dop[i] == -1)
        {
            return -1;
        }
        sum += dop[i];
    }
    return sum;
}

int main()
{
    setlocale(0, "");
    ifstream f("in.txt");
    f >> n;
    f >> m;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, s;
        f >> x >> y >> s;
        a[x-1][y-1] = s;
        a[y-1][x-1] = s;
    }
    f.close();
    int* sum = new int[n];
    for (int i = 0; i < n; i++)
    {
        sum[i] = Sum(a, i);
        if (sum[i] == -1)
        {
            cout << "Граф не связный" << endl;
            return -1;
        }
    }
    int min = sum[0];
    int imin = 0;
    for (int i = 1; i < n; i++)
    {
        if (sum[i] < min)
        {
            imin = i;
            min = sum[i];
        }
    }
    cout << "Оптимальное место встречи в доме " << imin + 1 << endl;
    return 0;
}
