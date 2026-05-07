#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Money {
private:
    int first;   // номінал
    int second;  // кількість

    void checkNominal(int value) const;
    void checkCount(int value) const;

public:
    Money();
    Money(int f, int s);
    Money(const Money& other);

    ~Money() {}

    int getFirst() const;
    int getSecond() const;

    void setFirst(int value);
    void setSecond(int value);

    void Init(int f, int s);
    void Read();
    void Display() const;
    int summa() const;

    operator string() const;

    Money& operator=(const Money& other);

    Money& operator++();      // префікс
    Money operator++(int);    // постфікс

    Money& operator--();
    Money operator--(int);

    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};

Money makeMoney(int f, int s);