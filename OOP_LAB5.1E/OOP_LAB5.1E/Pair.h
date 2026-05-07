#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair
{
private:
    double first;
    double second;

protected:
    static double ParseNumber(const string& value);
    void ParseFromString(const string& str);

public:
    Pair();
    Pair(double first, double second);
    Pair(const string& str);
    Pair(const Pair& other);

    double GetFirst() const;
    double GetSecond() const;
    void SetFirst(double value);
    void SetSecond(double value);

    void Init(double first, double second);
    void Read();
    void Display() const;
    string toString() const;
    double Product() const;

    Pair& operator=(const Pair& other);
    operator string() const;

    Pair& operator++();
    Pair operator++(int);
    Pair& operator--();
    Pair operator--(int);

    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);
};