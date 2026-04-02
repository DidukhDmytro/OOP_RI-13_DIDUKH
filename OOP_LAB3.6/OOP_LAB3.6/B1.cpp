#include "B1.h"

B1::B1(int value) : b1(value)
{
}

B1::~B1()
{
}

void B1::SetB1(int value)
{
    b1 = value;
}

int B1::GetB1() const
{
    return b1;
}

void B1::show() const
{
    cout << "Class B1: b1 = " << b1 << endl;
}