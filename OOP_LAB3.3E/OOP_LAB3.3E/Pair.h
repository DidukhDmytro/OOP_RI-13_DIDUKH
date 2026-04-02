#pragma once
#include "Object.h"
#include <string>
#include <iostream>

class Pair : public Object
{
private:
    double first;
    double second;

public:
    Pair();
    Pair(double first, double second);
    Pair(const Pair& other);

    double GetFirst() const;
    double GetSecond() const;

    void SetFirst(double value);
    void SetSecond(double value);

    void Init(double first, double second);
    void Read();
    void Display() const;
    std::string toString() const;
    double Product() const;

    Pair& operator=(const Pair& other);
    operator std::string() const;

    Pair& operator++();
    Pair operator++(int);
    Pair& operator--();
    Pair operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
    friend std::istream& operator>>(std::istream& in, Pair& p);
};