#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    string FIO;
    float mark;
    Student()
    {
        FIO = "";
    }
};

void Write(Student* temp, ofstream &f)
{
    if (temp != NULL)
    {
        f << temp->FIO << temp->mark << endl;
    }
}

Student* Read(ifstream& f)
{
    string s = "";
    Student* temp = new Student;
    getline(f, s);
    int i = 0;
    while (i < s.length() && (s[i] < '0' || s[i]>'9'))
    {
        temp->FIO += s[i];
        i++;
    }
    if (i == s.length() || (s[i + 1] != '.' && (i + 1) != s.length()))
    {
        return NULL;
    }
    temp->mark = s[i] - '0';
    int ten = 10;
    i+=2;
    for (; i < s.length(); i++)
    {
        float digit = s[i] - '0';
        temp->mark += digit/ten;
        ten *= 10;
    }
    return temp;
}

void Create_new_fail()
{
    ifstream in("in.txt");
    ofstream out("res.txt");
    while (!in.eof())
    {
        Write(Read(in), out);
    }
}

bool Partition()
{
    bool check = true;
    ifstream f("res.txt");
    ofstream a("a.txt");
    ofstream b("b.txt");
    Student* x = Read(f);
    Write(x, a);
    while (!f.eof())
    {
        Student* y = x;
        x = Read(f);
        while (x != NULL && !f.eof() && y->mark <= x->mark)
        {
            Write(x, a);
            y = x;
            x = Read(f);
        }
        if (x != NULL && y->mark > x->mark)
        {
            Write(x, b);
            check = false;
        }
        else Write(x, a);
        if (f.eof()) break;
        y = x;
        x = Read(f);
        while (x != NULL && !f.eof() && y->mark <= x->mark)
        {
            Write(x, b);
            check = false;
            y = x;
            x = Read(f);
        }
        if (x != NULL && y->mark > x->mark) Write(x, a);
        else
        {
            Write(x, b);
            check = false;
        }
    }
    f.close();
    a.close();
    b.close();
    return check;
}

void Merge()
{
    ofstream f("res.txt");
    ifstream a("a.txt");
    ifstream b("b.txt");
    Student* x1 = Read(a);
    Student* y1 = Read(b);
    Student* x2;
    Student* y2;
    while (!a.eof() && !b.eof())
    {
        x2 = x1;
        y2 = y1;
        while ((x1 != NULL && y1 != NULL) && x1->mark >= x2->mark && y1->mark >= y2->mark && !a.eof() && !b.eof())
        {
            if (x1->mark > y1->mark)
            {
                Write(y1, f);
                y2 = y1;
                y1 = Read(b);
            }
            else
            {
                Write(x1, f);
                x2 = x1;
                x1 = Read(a);
            }
        }
        while (x1 != NULL && x1->mark >= x2->mark && !a.eof())
        {
            Write(x1, f);
            x2 = x1;
            x1 = Read(a);
        }
        while (y1 != NULL && y1->mark >= y2->mark && !b.eof())
        {
            Write(y1, f);
            y2 = y1;
            y1 = Read(b);
        }
    }
    if (!a.eof())
    {
        while ((x1 != NULL && y1 != NULL) && !a.eof() && x1->mark <= y1->mark)
        {
            Write(x1, f);
            x1 = Read(a);
        }
        Write(y1, f);
        Write(x1, f);
    }
    if (!b.eof())
    {
        while ((x1 != NULL && y1 != NULL) && !b.eof() && x1->mark >= y1->mark)
        {
            Write(y1, f);
            y1 = Read(b);
        }
        Write(x1, f);
        Write(y1, f);
    }
    if (a.eof() && b.eof())
    {
        if ((x1 != NULL && y1 != NULL) && x1->mark >= y1->mark)
        {
            Write(y1, f);
            Write(x1, f);
        }
        else
        {
            Write(x1, f);
            Write(y1, f);
        }
    }
    while (!a.eof())
    {
        x1 = Read(a);
        Write(x1, f);
    }
    while (!b.eof())
    {
        y1 = Read(b);
        Write(y1, f);
    }
    f.close();
    a.close();
    b.close();
}

int main()
{
    setlocale(0, "");
    Create_new_fail();
    while (!Partition())
    {
        Merge();
    }
    cout << "Готово!!!!!\n\n\n";
    return 0;
}