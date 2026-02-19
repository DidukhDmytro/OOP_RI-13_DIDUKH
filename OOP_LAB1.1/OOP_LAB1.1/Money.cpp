#include "Money.h"

using namespace std;

bool Money::IsValidNominal(int value) const
{
    int allowed[] = { 1,2,5,10,20,50,100,200,500 };
    for (int i = 0; i < 9; i++)
        if (allowed[i] == value)
            return true;
    return false;
}

// Конструктори
Money::Money() : first(1), second(1) {}

Money::Money(int nominal, int count)
{
    Init(nominal, count);
}

// Get-методи
int Money::GetFirst() const { return first; }
int Money::GetSecond() const { return second; }

// Set-методи
void Money::SetFirst(int value)
{
    if (!IsValidNominal(value))
    {
        cout << "Incorrect nominal!" << endl;
        exit(1);
    }
    first = value;
}

void Money::SetSecond(int value)
{
    if (value <= 0)
    {
        cout << "Wrong amount!" << endl;
        exit(1);
    }
    second = value;
}

// Init
void Money::Init(int nominal, int count)
{
    SetFirst(nominal);
    SetSecond(count);
}

// Read
void Money::Read()
{
    int nominal, count;
    cout << "Enter nominal: ";
    cin >> nominal;
    cout << "Enter amount: ";
    cin >> count;
    Init(nominal, count);
}

// Display
void Money::Display() const
{
    cout << "Nominal: " << first
        << ", Amount: " << second
        << ", Summa: " << summa() << endl;
}

// summa
int Money::summa() const
{
    return first * second;
}

// Зовнішня функція
Money makeMoney(int nominal, int count)
{
    if (!(nominal == 1 || nominal == 2 || nominal == 5 ||
        nominal == 10 || nominal == 20 || nominal == 50 ||
        nominal == 100 || nominal == 200 || nominal == 500))
    {
        cout << "Error!" << endl;
        exit(1);
    }

    if (count <= 0)
    {
        cout << "Error!" << endl;
        exit(1);
    }

    return Money(nominal, count);
}
