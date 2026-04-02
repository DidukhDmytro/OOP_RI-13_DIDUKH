#include "Decimal.h"
#include <cstdlib>

void Decimal::normalize()
{
    while (size > 1 && data[size - 1] == 0)
        size--;
}

bool Decimal::isValidDecimalString(const std::string& s) const
{
    if (s.empty() || s.size() > MAX_SIZE)
        return false;

    for (char c : s)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}

Decimal::Decimal() : Array(1, 0)
{
}

Decimal::Decimal(int digits, unsigned int value) : Array(digits, 0)
{
    if (digits <= 0 || digits > MAX_SIZE)
    {
        std::cerr << "Invalid digit count" << std::endl;
        std::exit(1);
    }

    int i = 0;
    while (value > 0 && i < size)
    {
        data[i] = value % 10;
        value /= 10;
        i++;
    }

    if (value > 0)
    {
        std::cerr << "Value does not fit into Decimal size" << std::endl;
        std::exit(1);
    }

    normalize();
}

Decimal::Decimal(const std::string& number) : Array((int)number.length(), 0)
{
    Init(number);
}

Decimal::Decimal(const Decimal& other) : Array(other)
{
}

void Decimal::Init(const std::string& number)
{
    if (!isValidDecimalString(number))
    {
        std::cerr << "Invalid decimal string" << std::endl;
        std::exit(1);
    }

    size = (int)number.length();

    for (int i = 0; i < size; i++)
        data[i] = number[size - 1 - i] - '0';

    for (int i = size; i < MAX_SIZE; i++)
        data[i] = 0;

    normalize();
}

void Decimal::Read()
{
    std::string s;
    std::cin >> s;
    Init(s);
}

void Decimal::Display() const
{
    std::cout << toString() << std::endl;
}

std::string Decimal::toString() const
{
    std::string s;
    for (int i = size - 1; i >= 0; i--)
        s += char('0' + data[i]);
    return s;
}

Decimal& Decimal::operator=(const Decimal& other)
{
    if (this != &other)
        Array::operator=(other);
    return *this;
}

Decimal::operator std::string() const
{
    return toString();
}

Decimal Decimal::operator+(const Decimal& other) const
{
    Decimal result;
    result.size = (size > other.size ? size : other.size) + 1;

    if (result.size > MAX_SIZE)
    {
        std::cerr << "Overflow in addition" << std::endl;
        std::exit(1);
    }

    int carry = 0;
    for (int i = 0; i < result.size; i++)
    {
        int a = (i < size) ? data[i] : 0;
        int b = (i < other.size) ? other.data[i] : 0;
        int sum = a + b + carry;
        result.data[i] = sum % 10;
        carry = sum / 10;
    }

    result.normalize();
    return result;
}

Decimal Decimal::operator-(const Decimal& other) const
{
    if (*this < other)
    {
        std::cerr << "Negative result is not allowed" << std::endl;
        std::exit(1);
    }

    Decimal result(*this);
    int borrow = 0;

    for (int i = 0; i < result.size; i++)
    {
        int a = result.data[i] - borrow;
        int b = (i < other.size) ? other.data[i] : 0;

        if (a < b)
        {
            a += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result.data[i] = a - b;
    }

    result.normalize();
    return result;
}

Decimal Decimal::operator*(const Decimal& other) const
{
    Decimal result;
    result.size = size + other.size;

    if (result.size > MAX_SIZE)
    {
        std::cerr << "Overflow in multiplication" << std::endl;
        std::exit(1);
    }

    for (int i = 0; i < MAX_SIZE; i++)
        result.data[i] = 0;

    for (int i = 0; i < size; i++)
    {
        int carry = 0;
        for (int j = 0; j < other.size; j++)
        {
            int cur = result.data[i + j] + data[i] * other.data[j] + carry;
            result.data[i + j] = cur % 10;
            carry = cur / 10;
        }

        int pos = i + other.size;
        while (carry > 0)
        {
            int cur = result.data[pos] + carry;
            result.data[pos] = cur % 10;
            carry = cur / 10;
            pos++;
        }
    }

    result.normalize();
    return result;
}

Decimal Decimal::operator/(const Decimal& other) const
{
    if (other == Decimal("0"))
    {
        std::cerr << "Division by zero" << std::endl;
        std::exit(1);
    }

    Decimal dividend(*this);
    Decimal divisor(other);
    Decimal quotient("0");
    Decimal one("1");

    while (dividend >= divisor)
    {
        dividend = dividend - divisor;
        quotient = quotient + one;
    }

    return quotient;
}

Decimal Decimal::operator%(const Decimal& other) const
{
    if (other == Decimal("0"))
    {
        std::cerr << "Division by zero" << std::endl;
        std::exit(1);
    }

    Decimal dividend(*this);
    while (dividend >= other)
        dividend = dividend - other;

    return dividend;
}

bool Decimal::operator==(const Decimal& other) const
{
    if (size != other.size)
        return false;

    for (int i = 0; i < size; i++)
    {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}

bool Decimal::operator!=(const Decimal& other) const
{
    return !(*this == other);
}

bool Decimal::operator<(const Decimal& other) const
{
    if (size != other.size)
        return size < other.size;

    for (int i = size - 1; i >= 0; i--)
    {
        if (data[i] != other.data[i])
            return data[i] < other.data[i];
    }
    return false;
}

bool Decimal::operator<=(const Decimal& other) const
{
    return *this < other || *this == other;
}

bool Decimal::operator>(const Decimal& other) const
{
    return !(*this <= other);
}

bool Decimal::operator>=(const Decimal& other) const
{
    return !(*this < other);
}

Decimal& Decimal::operator++()
{
    *this = *this + Decimal("1");
    return *this;
}

Decimal Decimal::operator++(int)
{
    Decimal temp(*this);
    ++(*this);
    return temp;
}

Decimal& Decimal::operator--()
{
    if (*this == Decimal("0"))
    {
        std::cerr << "Negative result is not allowed" << std::endl;
        std::exit(1);
    }

    *this = *this - Decimal("1");
    return *this;
}

Decimal Decimal::operator--(int)
{
    Decimal temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Decimal& d)
{
    out << d.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Decimal& d)
{
    std::string s;
    in >> s;
    d.Init(s);
    return in;
}