/*
    Задание 30
    Найти корень уравнения f(x) = 0 разными методами:
    методом деления отрезка пополам (из заданий 22 и 28),
    методом хорд, методом Ньютона
    f(x) = (x * x - 9) * (cos(x) - 1)

    Кракова Софья
    2 курс 62 группа

*/
#include <iostream>
using namespace std;

// Функция вычисления f(x)
double F(double x)
{
    return (x * x - 9) * (cos(x) - 1);
}

// Функция нахождения корня методом деления отрезка пополам
double Root(double a, double b, double epps)
{
    // a и b - концы отрезка, epps - точность
    // с - середина отрезка
    double c = (a + b) / 2;
    while ((b - a) / 2 > epps)
    {
        if (F(a) * F(c) > 0)
            a = c;
        else
            b = c;
        c = (a + b) / 2;
    }
    return c;
}

// Функция нахождения корня методом деления отрезка пополам (рекурсивно)
double Root(double a, double b, double epps, int &count)
{
    // a и b - концы отрезка, epps - точность
    // с - середина отрезка
    // count -  количество обращений к функции
    double c = (a + b) / 2;
    count++;
    if ((b - a) / 2 <= epps)
        return c;
    if (F(a) * F(c) > 0)
        return Root(c, b, epps, count);
    else
        return Root(a, c, epps, count);
}

// Функция нахождения корня методом хорд
double Chord(double a, double b, double epps)
{
    // a и b - концы отрезка, epps - точность
    // с - контрольная точка
    double c = (F(b) * a - F(a) * b) / (F(b) - F(a));
    if ((b - a) / 2 <= epps)
        return c;
    if (F(a) * F(c) > 0)
        return Chord(c, b, epps);
    else
        return Chord(a, c, epps);
}

// Функция нахождения корня методом Ньютона
double Newton(double x, double epps)
{
    // x - приближение к корню, epps - точность
    // h - шаг изменения аргумента
    double h = 0.0000001;
    if (abs(F(x)) > epps)
    {
        // lim - производная функции f(x)
        double lim = (F(x + h) - F(x)) / h;
        return Newton(x - F(x) / lim, epps);
    }
    else
        return x;
}

int main()
{
    setlocale(0, "");
    cout << "Введите концы отрезка: ";
    double a, b;
    cin >> a >> b;
    // проверка корректности введенных данных
    if (F(a) * F(b) > 0)
    {
        cout << "На заданном интервале нет корня";
        return -1;
    }
    if (a > b)
    {
        double temp = a;
        b = a;
        a = temp;
    }
    double epps;
    cout << "Введите точность: ";
    cin >> epps;
    int count = 0; // количество обращений к функции
    // поиск корня
    cout << "Метод деления отрезка пополам: " << Root(a, b, epps) << endl;
    cout << "Метод деления отрезка пополам: " << Root(a, b, epps, count);
    cout << " Количество обращений к функции: " << count << endl;
    cout << "Метод хорд: " << Chord(a, b, epps) << endl;
    cout << "Введите начальное приближение х к корню: ";
    double x; // приближение к корню
    cin >> x;
    cout << "Метод Ньютона: " << Newton(x, epps) << endl;
    return 0;
}