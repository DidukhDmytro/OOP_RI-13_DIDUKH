#include "D1.h"
#include <iostream>
using namespace std;

D1::D1(int vb1, int vb2, int vd1) : B1(vb1), B2(vb2), d1(vd1)
{
}

D1::~D1()
{
}

void D1::SetD1(int value)
{
    d1 = value;
}

int D1::GetD1() const
{
    return d1;
}

void D1::SetB2Value(int value)
{
    SetB2(value);
}

int D1::GetB2Value() const
{
    return GetB2();
}

void D1::show() const
{
    cout << "Class D1: b1 = " << GetB1()
        << ", b2 = " << GetB2()
        << ", d1 = " << d1 << endl;
}