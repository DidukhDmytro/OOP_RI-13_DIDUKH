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

    try
    {
        cout << "Count at start: " << Object::GetCount() << endl;
        cout << endl;

        Pair p1;
        Pair p2(3, 4);
        Pair p3("5.5,6.5");
        Pair p4(p2);

        cout << "Pair objects:" << endl;
        cout << "p1 = " << p1 << endl;
        cout << "p2 = " << p2 << endl;
        cout << "p3 = " << p3 << endl;
        cout << "p4 = " << p4 << endl;
        cout << "Product of p2 = " << p2.Product() << endl;
        cout << endl;

        ++p2;
        cout << "After ++p2: " << p2 << endl;

        p2--;
        cout << "After p2--: " << p2 << endl;

        string s1 = (string)p2;
        cout << "String p2: " << s1 << endl;
        cout << endl;

        Pair pairArray[2] = { Pair(1, 2), Pair("7,8") };
        cout << "Array of Pair:" << endl;
        for (int i = 0; i < 2; i++)
            cout << pairArray[i] << endl;
        cout << endl;

        Rectangle r1;
        Rectangle r2(5, 7);
        Rectangle r3("6,9");
        Rectangle r4(r2);

        cout << "Rectangle objects:" << endl;
        cout << "r1 = " << r1 << endl;
        cout << "r2 = " << r2 << endl;
        cout << "r3 = " << r3 << endl;
        cout << "r4 = " << r4 << endl;
        cout << endl;

        cout << "Perimeter of r2 = " << r2.Perimeter() << endl;
        cout << "Area of r2 = " << r2.Area() << endl;
        cout << "Product of sides = " << r2.Product() << endl;
        cout << endl;

        ++r2;
        cout << "After ++r2: " << r2 << endl;

        r2--;
        cout << "After r2--: " << r2 << endl;

        string s2 = (string)r2;
        cout << "String r2: " << s2 << endl;
        cout << endl;

        Rectangle rectArray[2] = { Rectangle(2, 3), Rectangle("4,6") };
        cout << "Array of Rectangle:" << endl;
        for (int i = 0; i < 2; i++)
            cout << rectArray[i] << endl;
        cout << endl;

        cout << "Current object count: " << Object::GetCount() << endl;

        {
            Pair temp1(10, 20);
            Rectangle temp2(8, 9);
            cout << "Count inside block: " << Object::GetCount() << endl;
        }

        cout << "Count after block: " << Object::GetCount() << endl;
        cout << endl;

        try
        {
            Rectangle bad(-2, 5);
        }
        catch (const exception& e)
        {
            cout << "Exception 1: " << e.what() << endl;
        }

        try
        {
            Rectangle bad2("abc,10");
        }
        catch (const exception& e)
        {
            cout << "Exception 2: " << e.what() << endl;
        }

        try
        {
            Rectangle bad3("10");
        }
        catch (const exception& e)
        {
            cout << "Exception 3: " << e.what() << endl;
        }

        cout << endl;
        cout << "sizeof(Pair) = " << sizeof(Pair) << endl;
        cout << "sizeof(Rectangle) = " << sizeof(Rectangle) << endl;
        cout << "sizeof(PairPacked) = " << sizeof(PairPacked) << endl;
        cout << "sizeof(RectanglePacked) = " << sizeof(RectanglePacked) << endl;
    }
    catch (const exception& e)
    {
        cout << "Fatal error: " << e.what() << endl;
    }

    return 0;
}