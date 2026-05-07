#include "Pair.h"
#include <sstream>
#include <stdexcept>

Pair::Pair() : first(0), second(0) {}

Pair::Pair(double first, double second)
{
    Init(first, second);
}

Pair::Pair(const string& str)
{
    ParseFromString(str);
}

Pair::Pair(const Pair& other)
{
    first = other.first;
    second = other.second;
}

double Pair::ParseNumber(const string& value)
{
    stringstream ss(value);
    double number;
    ss >> number;

    if (ss.fail() || !ss.eof())
        throw invalid_argument("Invalid numeric value in string");

    return number;
}

void Pair::ParseFromString(const string& str)
{
    size_t comma = str.find(',');
    if (comma == string::npos)
        throw invalid_argument("Invalid string format. Expected: first,second");

    string left = str.substr(0, comma);
    string right = str.substr(comma + 1);

    double a = ParseNumber(left);
    double b = ParseNumber(right);

    Init(a, b);
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
    ++(*this);
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
    --(*this);
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