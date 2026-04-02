#pragma once
#include "B1.h"
#include "B2.h"

class D1 : public B1, private B2
{
private:
    int d1;

public:
    D1(int vb1 = 0, int vb2 = 0, int vd1 = 0);
    ~D1();

    void SetD1(int value);
    int GetD1() const;

    void SetB2Value(int value);
    int GetB2Value() const;

    void show() const;
};