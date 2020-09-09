#include <iostream>
#include <fstream>

using namespace std;

// Структура списка для хранения хеша
struct Hash
{
    int key;
    int value;
    Hash* next;

    Hash(int k, int v, Hash* n) // конструктор с параметрами
    {
        key = k;
        value = v;
        next = n;
    }
};
int m; // размер хеш-таблицы
int n; // количество элементов таблицы
Hash** table; // хеш-таблица

// Функция инициализации таблицы
void null_table()
{
    for (int i = 0; i < m; i++)
    {
        table[i] = NULL;
    }
}

// Функция добавления элемента в таблицу
void Insert(int key, int value)
{
    int hash = (key % m); // считаем хеш методом деления с остатком
    if (table[hash] == NULL) // если нет элементов с полученным хешем
    {
        table[hash] = new Hash(key, value, NULL); // то элемент будет первым в списке
    }
    else // если же уже есть элементы с полученным хешем
    {
        // то добавляем элемент в начало списка 
        Hash* list = table[hash];
        table[hash] = new Hash(key, value, list);
    }
    n++; // увеличиваем счетчик элементов на 1
}

// Функция считывания элементов из файла
void Read()
{
    ifstream f("in.txt");
    f >> m;
    table = new Hash * [m];
    null_table();
    n = 0; // зануляем количество элементов
    while (!f.eof())
    {
        int i, j;
        f >> i >> j; // считываем ключ элемента и значение
        Insert(i, j); // добавляем элемент в таблицу
    }
}

// Функция подсчета количества элементов с определенным хешем 
int Count(int key)
{
    int count = 0; // счетчик элементов
    Hash* list = table[key]; // копируем список, хранящий все элементы с данным хешем
    while (list != NULL) // считаем сколько элементов с данным хешем
    {
        count++;
        list = list->next;
    }
    return count;
}

// Функция для подсчета необходимого критерия
double Task()
{
    double x = 0;
    double c = (double)n / m;
    for (int i = 0; i < m; i++)
    {
        int f = Count(i);
        x += (f - c) * (f - c);
    }
    x /= c;
    return x;
}

int main()
{
    setlocale(0, "");
    Read();
    cout << "X2 = " << Task();
    return 0;
}