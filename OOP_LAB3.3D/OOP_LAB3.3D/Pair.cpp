#include "Pair.h"
#include <sstream>
#include <stdexcept>

Pair::Pair() : first(0), second(0) {}

Pair::Pair(double first, double second)
{
    Init(first, second);
}

Pair::Pair(const Pair& other)
{
    first = other.first;
    second = other.second;
}

double Pair::GetFirst() const
{
    return first;
}

double Pair::GetSecond() const
{
    return second;
}

void Pair::SetFirst(double value)
{
    first = value;
}

void Pair::SetSecond(double value)
{
    second = value;
}

void Pair::Init(double first, double second)
{
    SetFirst(first);
    SetSecond(second);
}

void Pair::Read()
{
    double a, b;
    cout << "first = ";
    cin >> a;
    cout << "second = ";
    cin >> b;
    Init(a, b);
}

void Pair::Display() const
{
    cout << toString() << endl;
}

string Pair::toString() const
{
    stringstream sout;
    sout << "Pair(" << first << ", " << second << ")";
    return sout.str();
}

double Pair::Product() const
{
    return first * second;
}

Pair& Pair::operator=(const Pair& other)
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Pair::operator string() const
{
    return toString();
}

Pair& Pair::operator++()
{
    ++first;
    ++second;
    return *this;
}

Pair Pair::operator++(int)
{
    Pair temp(*this);
    first++;
    second++;
    return temp;
}

Pair& Pair::operator--()
{
    --first;
    --second;
    return *this;
}

Pair Pair::operator--(int)
{
    Pair temp(*this);
    first--;
    second--;
    return temp;
}

ostream& operator<<(ostream& out, const Pair& p)
{
    out << p.toString();
    return out;
}

istream& operator>>(istream& in, Pair& p)
{
    double a, b;
    cout << "Enter first: ";
    in >> a;
    cout << "Enter second: ";
    in >> b;
    p.Init(a, b);
    return in;
}