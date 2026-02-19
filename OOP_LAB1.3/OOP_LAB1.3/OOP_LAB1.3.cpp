#include "Point.h"
#include <iostream>

using namespace std;

int main()
{
    // cтворення через конструктор без параметрів
    Point p1;
    p1.Read();
    p1.Display();

    // cтворення через конструктор з параметрами
    Point p2(3, 4);
    cout << "p2 = " << p2.toString() << endl;

    //Переміщення
    p2.MoveX(2);
    p2.MoveY(-1);
    cout << "p2 after movement: ";
    p2.Display();

    // Відстань між точками
    cout << "Distance beetween: "
        << p1.DistanceTo(p2) << endl;

    //Масив об'єктів
    Point arr[3];

    cout << "\nmassif of points:\n";
    for (int i = 0; i < 3; i++)
        arr[i].Read();

    cout << "\nmassif of points:\n";
    for (int i = 0; i < 3; i++)
        arr[i].Display();

    return 0;
}
