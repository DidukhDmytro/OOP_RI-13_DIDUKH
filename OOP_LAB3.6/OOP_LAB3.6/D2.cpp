#include "D2.h"
#include <iostream>
using namespace std;

D2::D2(int vb1, int vb2, int vd1, int vd2) : D1(vb1, vb2, vd1), d2(vd2)
{
}

D2::~D2()
{
}

void D2::SetD2(int value)
{
    d2 = value;
}

int D2::GetD2() const
{
    return d2;
}

void D2::SetB1Value(int value)
{
    SetB1(value);
}

int D2::GetB1Value() const
{
    return GetB1();
}

void D2::SetB2ValueFromD2(int value)
{
    D1::SetB2Value(value);
}

int D2::GetB2ValueFromD2() const
{
    return D1::GetB2Value();
}

void D2::SetD1Value(int value)
{
    SetD1(value);
}

int D2::GetD1Value() const
{
    return GetD1();
}

void D2::show() const
{
    cout << "Class D2: b1 = " << GetB1()
        << ", b2 = " << D1::GetB2Value()
        << ", d1 = " << GetD1()
        << ", d2 = " << d2 << endl;
}