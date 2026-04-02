#pragma once
#include "D2.h"

class D3 : public D2
{
private:
    int d3;

public:
    D3(int vb1 = 0, int vb2 = 0, int vd1 = 0, int vd2 = 0, int vd3 = 0);
    ~D3();

    void SetD3(int value);
    int GetD3() const;

    void show() const;
};