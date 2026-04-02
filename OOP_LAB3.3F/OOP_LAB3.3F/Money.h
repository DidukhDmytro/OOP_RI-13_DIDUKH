#pragma once
#include <string>
#include <iostream>

class Money
{
private:
    int n500, n200, n100, n50, n20, n10, n5, n2, n1;
    int k50, k25, k10, k5, k2, k1;

public:
    Money();
    Money(int sum);
    Money(const Money& other);

    void Init(int sum);
    void Read();
    void Display() const;
    std::string toString() const;

    int ToKopecks() const;

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator/(const Money& other) const;
    Money operator*(double value) const;
    Money operator/(double value) const;

    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Money& m);
    friend std::istream& operator>>(std::istream& in, Money& m);
};