#include "Pair.h"
#include <sstream>
#include <stdexcept>

Pair::Pair() : Object(), first(0), second(0)
{
}

Pair::Pair(double first, double second) : Object()
{
    Init(first, second);
}

Pair::Pair(const std::string& str) : Object()
{
    ParseFromString(str);
}

Pair::Pair(const Pair& other) : Object(other), first(other.first), second(other.second)
{
}

double Pair::ParseNumber(const std::string& value)
{
    std::stringstream ss(value);
    double number;
    ss >> number;

    if (ss.fail() || !ss.eof())
        throw std::invalid_argument("Invalid numeric value in string");

    return number;
}

void Pair::ParseFromString(const std::string& str)
{
    size_t comma = str.find(',');
    if (comma == std::string::npos)
        throw std::invalid_argument("Invalid string format. Expected: first,second");

    std::string left = str.substr(0, comma);
    std::string right = str.substr(comma + 1);

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
    std::cout << "first = ";
    std::cin >> a;
    std::cout << "second = ";
    std::cin >> b;
    Init(a, b);
}

void Pair::Display() const
{
    std::cout << toString() << std::endl;
}

std::string Pair::toString() const
{
    std::ostringstream sout;
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

Pair::operator std::string() const
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

std::ostream& operator<<(std::ostream& out, const Pair& p)
{
    out << p.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Pair& p)
{
    double a, b;
    std::cout << "Enter first: ";
    in >> a;
    std::cout << "Enter second: ";
    in >> b;
    p.Init(a, b);
    return in;
}