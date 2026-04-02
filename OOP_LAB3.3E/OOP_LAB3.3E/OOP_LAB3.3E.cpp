#include <iostream>
#include <string>
#include "Object.h"
#include "Pair.h"
#include "Rectangle.h"

#pragma pack(push, 1)
class PairPacked
{
private:
    double first;
    double second;
};

class RectanglePacked : public PairPacked
{
};
#pragma pack(pop)

int main()
{
    using namespace std;

    cout << "Count at start: " << Object::GetCount() << endl;

    Pair p1;
    Pair p2(3, 4);
    Pair p3(p2);

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << "Product of p2 = " << p2.Product() << endl;

    ++p2;
    cout << "After ++p2: " << p2 << endl;

    p2--;
    cout << "After p2--: " << p2 << endl;

    string s1 = (string)p2;
    cout << "String p2: " << s1 << endl;

    Pair pairArray[2] = { Pair(1, 2), Pair(5, 6) };
    cout << "Array of Pair:" << endl;
    for (int i = 0; i < 2; i++)
        cout << pairArray[i] << endl;

    Rectangle r1;
    Rectangle r2(5, 7);
    Rectangle r3(r2);

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;

    cout << "Perimeter of r2 = " << r2.Perimeter() << endl;
    cout << "Area of r2 = " << r2.Area() << endl;
    cout << "Product of sides = " << r2.Product() << endl;

    ++r2;
    cout << "After ++r2: " << r2 << endl;

    r2--;
    cout << "After r2--: " << r2 << endl;

    string s2 = (string)r2;
    cout << "String r2: " << s2 << endl;

    Rectangle rectArray[2] = { Rectangle(2, 3), Rectangle(4, 6) };
    cout << "Array of Rectangle:" << endl;
    for (int i = 0; i < 2; i++)
        cout << rectArray[i] << endl;

    cout << "Current object count: " << Object::GetCount() << endl;

    {
        Pair temp1(10, 20);
        Rectangle temp2(8, 9);
        cout << "Count inside block: " << Object::GetCount() << endl;
    }

    cout << "Count after block: " << Object::GetCount() << endl;

    cout << "sizeof(Pair) = " << sizeof(Pair) << endl;
    cout << "sizeof(Rectangle) = " << sizeof(Rectangle) << endl;
    cout << "sizeof(PairPacked) = " << sizeof(PairPacked) << endl;
    cout << "sizeof(RectanglePacked) = " << sizeof(RectanglePacked) << endl;

    return 0;
}