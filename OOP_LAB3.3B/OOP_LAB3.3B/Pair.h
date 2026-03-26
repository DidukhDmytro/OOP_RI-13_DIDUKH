#pragma once
#include <iostream>
#include <string>

class Pair
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

    Pair& operator=(const Pair& other);

    bool operator>(const Pair& other) const;
    bool operator<(const Pair& other) const;
    bool operator>=(const Pair& other) const;
    bool operator<=(const Pair& other) const;
    bool operator==(const Pair& other) const;
    bool operator!=(const Pair& other) const;

    operator std::string() const;

    friend std::istream& operator>>(std::istream& in, Pair& p);
    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
};

Pair makePair(double first, double second);