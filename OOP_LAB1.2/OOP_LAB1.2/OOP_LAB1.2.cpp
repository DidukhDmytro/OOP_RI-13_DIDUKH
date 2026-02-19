#include "Circle.h"

int main()
{
    Circle c1;
    c1.Read();
    c1.Display();

    Circle c2 = makeCircle(2, 3, 5);
    c2.Display();

    return 0;
}
