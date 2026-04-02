#include "B2.h"

B2::B2(int value) : b2(value)
{
}

B2::~B2()
{
}

void B2::SetB2(int value)
{
    b2 = value;
}

int B2::GetB2() const
{
    return b2;
}

void B2::show() const
{
    cout << "Class B2: b2 = " << b2 << endl;
}