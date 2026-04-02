#include "Money.h"
#include <sstream>

Money::Money() : Money(0) {}

Money::Money(int sum)
{
    Init(sum);
}

Money::Money(const Money& other)
{
    *this = other;
}

void Money::Init(int sum)
{
    int kop = sum * 100;

    n500 = kop / 50000; kop %= 50000;
    n200 = kop / 20000; kop %= 20000;
    n100 = kop / 10000; kop %= 10000;
    n50 = kop / 5000;  kop %= 5000;
    n20 = kop / 2000;  kop %= 2000;
    n10 = kop / 1000;  kop %= 1000;
    n5 = kop / 500;   kop %= 500;
    n2 = kop / 200;   kop %= 200;
    n1 = kop / 100;   kop %= 100;

    k50 = kop / 50; kop %= 50;
    k25 = kop / 25; kop %= 25;
    k10 = kop / 10; kop %= 10;
    k5 = kop / 5;  kop %= 5;
    k2 = kop / 2;  kop %= 2;
    k1 = kop;
}

int Money::ToKopecks() const
{
    return n500 * 50000 + n200 * 20000 + n100 * 10000 +
        n50 * 5000 + n20 * 2000 + n10 * 1000 +
        n5 * 500 + n2 * 200 + n1 * 100 +
        k50 * 50 + k25 * 25 + k10 * 10 +
        k5 * 5 + k2 * 2 + k1;
}

std::string Money::toString() const
{
    std::ostringstream sout;
    int total = ToKopecks();
    sout << total / 100 << "," << total % 100;
    return sout.str();
}

void Money::Display() const
{
    std::cout << toString() << std::endl;
}

void Money::Read()
{
    int sum;
    std::cout << "Enter sum (UAH): ";
    std::cin >> sum;
    Init(sum);
}

Money Money::operator+(const Money& other) const
{
    return Money((ToKopecks() + other.ToKopecks()) / 100);
}

Money Money::operator-(const Money& other) const
{
    return Money((ToKopecks() - other.ToKopecks()) / 100);
}

Money Money::operator*(double value) const
{
    return Money((int)(ToKopecks() * value / 100));
}

Money Money::operator/(double value) const
{
    return Money((int)(ToKopecks() / value / 100));
}

bool Money::operator>(const Money& other) const
{
    return ToKopecks() > other.ToKopecks();
}

bool Money::operator<(const Money& other) const
{
    return ToKopecks() < other.ToKopecks();
}

bool Money::operator==(const Money& other) const
{
    return ToKopecks() == other.ToKopecks();
}

Money& Money::operator++()
{
    Init((ToKopecks() / 100) + 1);
    return *this;
}

Money Money::operator++(int)
{
    Money temp(*this);
    ++(*this);
    return temp;
}

Money& Money::operator--()
{
    Init((ToKopecks() / 100) - 1);
    return *this;
}

Money Money::operator--(int)
{
    Money temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Money& m)
{
    return out << m.toString();
}

std::istream& operator>>(std::istream& in, Money& m)
{
    int sum;
    in >> sum;
    m.Init(sum);
    return in;
}