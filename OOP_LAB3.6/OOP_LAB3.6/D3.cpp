#include "D3.h"
#include <iostream>
using namespace std;

D3::D3(int vb1, int vb2, int vd1, int vd2, int vd3)
    : D2(vb1, vb2, vd1, vd2), d3(vd3)
{
}

D3::~D3()
{
}

void D3::SetD3(int value)
{
    d3 = value;
}

int D3::GetD3() const
{
    return d3;
}

void D3::show() const
{
    cout << "Class D3: b1 = " << GetB1Value()
        << ", b2 = " << GetB2ValueFromD2()
        << ", d1 = " << GetD1Value()
        << ", d2 = " << GetD2()
        << ", d3 = " << d3 << endl;
}