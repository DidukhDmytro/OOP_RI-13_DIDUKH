#pragma once
#include "Array.h"

class Decimal : public Array
{
private:
    void normalize();
    bool isValidDecimalString(const std::string& s) const;

public:
    Decimal();
    Decimal(int digits, unsigned int value = 0);
    Decimal(const std::string& number);
    Decimal(const Decimal& other);

    void Init(const std::string& number);
    void Read();
    void Display() const;
    std::string toString() const;

    Decimal& operator=(const Decimal& other);
    operator std::string() const;

    Decimal operator+(const Decimal& other) const;
    Decimal operator-(const Decimal& other) const;
    Decimal operator*(const Decimal& other) const;
    Decimal operator/(const Decimal& other) const;
    Decimal operator%(const Decimal& other) const;

    bool operator==(const Decimal& other) const;
    bool operator!=(const Decimal& other) const;
    bool operator<(const Decimal& other) const;
    bool operator<=(const Decimal& other) const;
    bool operator>(const Decimal& other) const;
    bool operator>=(const Decimal& other) const;

    Decimal& operator++();
    Decimal operator++(int);
    Decimal& operator--();
    Decimal operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Decimal& d);
    friend std::istream& operator>>(std::istream& in, Decimal& d);
};