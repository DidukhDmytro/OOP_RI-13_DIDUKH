#pragma once
#include <iostream>
using namespace std;

class B1
{
private:
    int b1;

public:
    B1(int value = 0);
    ~B1();

    void SetB1(int value);
    int GetB1() const;

    void show() const;
};