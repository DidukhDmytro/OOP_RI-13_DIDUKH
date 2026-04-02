#pragma once
#include "D1.h"

class D2 : private D1
{
private:
    int d2;

public:
    D2(int vb1 = 0, int vb2 = 0, int vd1 = 0, int vd2 = 0);
    ~D2();

    void SetD2(int value);
    int GetD2() const;

    void SetB1Value(int value);
    int GetB1Value() const;

    void SetB2ValueFromD2(int value);
    int GetB2ValueFromD2() const;

    void SetD1Value(int value);
    int GetD1Value() const;

    void show() const;
};