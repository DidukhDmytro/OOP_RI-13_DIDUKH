#include "Rectangle.h"

using namespace std;

Pair MakePair(Pair p) {
    return p;
}

void ShowPair(Pair p)
{
    cout << p << endl;
}

int main()
{
    Pair a, b(2, 3), c;
    Rectangle x(4, 5), y, z(x);

    cout << "Objects of class Pair:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << endl << "Objects of class Rectangle:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    cout << endl << "Input Pair a:" << endl;
    cin >> a;
    cout << "a = " << a << endl;

    cout << endl << "Input Rectangle y:" << endl;
    cin >> y;
    cout << "y = " << y << endl;
    cout << endl << "Perimeter and area of entered rectangle:" << endl;
    cout << "Perimeter = " << y.perimeter() << endl;
    cout << "Area = " << y.area() << endl;

    cout << endl << "Operations for Pair:" << endl;
    c = a + b;
    cout << "a + b = " << c << endl;
    c = a * 3;
    cout << "a * 3 = " << c << endl;
    c = 2 * b;
    cout << "2 * b = " << c << endl;
    cout << "Product of numbers in b = " << b.product() << endl;

    cout << endl << "Methods of Rectangle:" << endl;
    cout << "Perimeter of x = " << x.perimeter() << endl;
    cout << "Area of x = " << x.area() << endl;
    cout << "Product of sides in x = " << x.product() << endl;

    cout << endl << "Function that gets and returns object of base class:" << endl;
    Pair d = MakePair(b);
    cout << "d = " << d << endl;

    cout << endl << "Substitution principle:" << endl;
    ShowPair(b);
    ShowPair(x);

    cout << endl << "Array of Pair objects:" << endl;
    Pair arr1[3] = { Pair(1, 2), Pair(3, 4), Pair(5, 6) };
    for (int i = 0; i < 3; i++)
        cout << "arr1[" << i << "] = " << arr1[i] << endl;

    cout << endl << "Array of Rectangle objects:" << endl;
    Rectangle arr2[3] = { Rectangle(2, 3), Rectangle(4, 5), Rectangle(6, 7) };
    for (int i = 0; i < 3; i++)
        cout << "arr2[" << i << "] = " << arr2[i] << endl;

    return 0;
}