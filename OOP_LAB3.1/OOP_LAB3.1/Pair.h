#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair
{
    int a, b;

public:
    Pair(const int x = 0, const int y = 0);
    Pair(const Pair& r);
    ~Pair(void);

    int getA() const { 
        return a; 
    }
    int getB() const {
        return b;
    }

    void setA(const int value);
    void setB(const int value);

    int product() const;

    friend Pair operator + (const Pair& l, const Pair& r);
    friend Pair operator * (const Pair& l, const int k);
    friend Pair operator * (const int k, const Pair& r);

    operator string() const;
    friend ostream& operator << (ostream& out, const Pair& r);
    friend istream& operator >> (istream& in, Pair& r);
};