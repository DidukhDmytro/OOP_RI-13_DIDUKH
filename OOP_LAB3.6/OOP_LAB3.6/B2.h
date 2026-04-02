#pragma once
#include <iostream>
using namespace std;

class B2
{
private:
    int b2;

public:
    B2(int value = 0);
    ~B2();

    void SetB2(int value);
    int GetB2() const;

    void show() const;
};