#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#define NumberOfMoves 8

using namespace std;
struct cell
{
    int x;
    int y;
    cell(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
    cell()
    {
        x = -1;
        y = -1;
    }
};
char** ChessBoard;
int* dop;
int n;
int dx[NumberOfMoves] = { -2,-2,-1,-1,1,1,2,2 };
int dy[NumberOfMoves] = { -1,1,-2,2,-2,2,-1,1 };

int Search_Razm_and_Create_New_Fail()
{
    ifstream f("in.txt");
    ofstream g("copy.txt");
    int nnn = 0;
    char a;
    while (f >> a && (a == '.' || a == 'W' || a == 'B'))
    {
        g << a;
        nnn++;
    }
    int nn = sqrt(nnn);
    if (nnn == nn * nn)
    {
        return nn;
    }
    else
    {
        return -1;
    }
}

bool NoRoad(cell* g)
{
    return (g->x < 0 || g->x >= n || g->y < 0 || g->y >= n);
}

bool CanGo(cell* g)
{
    return ChessBoard[g->x][g->y] == '.';
}

cell* Task(int curr, cell** black, int k)
{
    dop[curr]++;
    int max = 0;
    int* cell_max = new int[k];
    cell* position = new cell;
    for (int a = 0; a < k; a++)
    {
        cell_max[a] = 0;
    }
    for (int i = 0; i < NumberOfMoves; i++)
    {
        int xx = black[curr]->x + dx[i];
        int yy = black[curr]->y + dy[i];
        cell* temp = new cell(xx, yy);
        if (!NoRoad(temp) && CanGo(temp))
        {
            int count = 0;
            int* cell_curr = new int[k];
            for (int a = 0; a < k; a++)
            {
                cell_curr[a] = 0;
            }
            for (int j = 0; j < k; j++)
            {
                if (dop[j] == 0)
                {
                    int xxx = temp->x - black[j]->x;
                    int yyy = temp->y - black[j]->y;
                    int xy = xxx * yyy;
                    if (xy == 2 || xy == -2)
                    {
                        cell_curr[j]++;
                        count++;
                    }
                }
            }
            if (count >= max)
            {
                max = count;
                position = temp;
                for (int a = 0; a < k; a++)
                {
                    cell_max[a] = cell_curr[a];
                }
            }
        }
    }
    for (int a = 0; a < k; a++)
    {
        dop[a] = cell_max[a];
        dop[curr]++;
    }
    return position;
}

int main()
{
    setlocale(0, "");
    n = Search_Razm_and_Create_New_Fail();
    if (n == -1)
    {
        cout << "Неправильно введены данные";
        return -1;
    }
    ChessBoard = new char* [n];
    for (int i = 0; i < n; i++)
    {
        ChessBoard[i] = new char[n];
    }
    ifstream in("copy.txt");
    queue<cell*> qblack;
    queue<cell*> qwhite;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> ChessBoard[i][j];
            if (ChessBoard[i][j] == 'B')
            {
                cell* temp = new cell(i, j);
                qblack.push(temp);
            }
            /*if (ChessBoard[i][j] == 'W')
            {
                cell* temp = new cell(i, j);
                qwhite.push(temp);
            }*/
        }
    }
    int k = qblack.size();
    cell** black = new cell*[k];
    dop = new int[k];
    for (int i = 0; i < k; i++)
    {
        dop[i] = 0;
        black[i] = qblack.front();
        qblack.pop();
    }
    int count_horse = 0;
    for (int i = 0; i < k; i++)
    {
        if (dop[i] == 0)
        {
            cell* position = Task(i, black, k);
            if (position->x != -1)
            {
                ChessBoard[position->x][position->y] = 'H';
            }
            else
            {
                cout << "IMPOSSIBLE!!!!!!!!!!!!!!!!!\n\n\n";
                ofstream res("res.txt");
                res << "IMPOSSIBLE!!!!!!!!!!!!!!!!!";
                return - 1;
            }
            count_horse++;
        }
    }
    ofstream res("res.txt");
    res << "Minimum number of horses - " << count_horse << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res << ChessBoard[i][j];
        }
        res << endl;
    }
    cout << "Готово!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
    return 0;
}