#include "Money.h"

int main()
{
    Money m1;
    m1.Read();
    m1.Display();

    Money m2 = makeMoney(100, 5);
    m2.Display();

    return 0;
}