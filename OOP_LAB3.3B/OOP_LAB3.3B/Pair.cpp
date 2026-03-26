#include "Pair.h"
#include <sstream>
#include <stdexcept>

using namespace std;

Pair::Pair() : first(0.0), second(0.0)
{
}

Pair::Pair(double firstVal, double secondVal)
{
    Init(firstVal, secondVal);
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

void Pair::Init(double firstVal, double secondVal)
{
    SetFirst(firstVal);
    SetSecond(secondVal);
}

void Pair::Read()
{
    cin >> *this;
}

void Pair::Display() const
{
    cout << *this << endl;
}

string Pair::toString() const
{
    stringstream ss;
    ss << "(" << first << ", " << second << ")";
    return ss.str();
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

bool Pair::operator>(const Pair& other) const
{
    return (first > other.first) ||
        (first == other.first && second > other.second);
}

bool Pair::operator<(const Pair& other) const
{
    return other > *this;
}

bool Pair::operator>=(const Pair& other) const
{
    return !(*this < other);
}

bool Pair::operator<=(const Pair& other) const
{
    return !(*this > other);
}

bool Pair::operator==(const Pair& other) const
{
    return first == other.first && second == other.second;
}

bool Pair::operator!=(const Pair& other) const
{
    return !(*this == other);
}

Pair::operator string() const
{
    return toString();
}

istream& operator>>(istream& in, Pair& p)
{
    double firstVal, secondVal;

    cout << "Enter first: ";
    in >> firstVal;
    cout << "Enter second: ";
    in >> secondVal;

    if (!in)
        throw invalid_argument("Error: incorrect input.");

    p.Init(firstVal, secondVal);
    return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

Pair makePair(double first, double second)
{
    return Pair(first, second);
}