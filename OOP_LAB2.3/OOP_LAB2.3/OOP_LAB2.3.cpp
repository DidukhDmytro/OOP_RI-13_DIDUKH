#include "Point.h"
#include <iostream>

using namespace std;

struct NormalPointSize
{
    double x;
    double y;
};

#pragma pack(push, 1)
struct PackedPointSize
{
    double x;
    double y;
};
#pragma pack(pop)

int main()
{
    Point p1;
    cin >> p1;
    cout << "p1 = " << p1 << endl;

    Point p2(3, 4);
    cout << "p2 = " << p2 << endl;

    Point p3(p2);
    cout << "p3 (copy of p2) = " << p3 << endl;

    p1 = p2;
    cout << "p1 after assignment p1 = p2: " << p1 << endl;

    p2.MoveX(2);
    p2.MoveY(-1);
    cout << "p2 after MoveX(2) and MoveY(-1): " << p2 << endl;

    cout << "Distance between p2 and p3: " << (p2 - p3) << endl;

    // унарний мінус
    Point p4 = -p2;
    cout << "p4 = -p2: " << p4 << endl;

    cout << "Prefix ++p2: " << ++p2 << endl;
    cout << "Postfix p2++: " << p2++ << endl;
    cout << "After postfix p2: " << p2 << endl;

    cout << "Prefix --p2: " << --p2 << endl;
    cout << "Postfix p2--: " << p2-- << endl;
    cout << "After postfix p2: " << p2 << endl;

    Point p5 = p2 + 5;
    cout << "p5 = p2 + 5: " << p5 << endl;

    Point p6 = 10 + p2;
    cout << "p6 = 10 + p2: " << p6 << endl;

    string s = (string)p2;
    cout << "String form of p2: " << s << endl;

    Point arr[3];
    cout << "\nEnter 3 points:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Point " << i + 1 << ":\n";
        cin >> arr[i];
    }

    cout << "\nArray of points:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    cout << "\nSize without #pragma pack(1): " << sizeof(NormalPointSize) << endl;
    cout << "Size with #pragma pack(1): " << sizeof(PackedPointSize) << endl;
    cout << "Size of class Point: " << sizeof(Point) << endl;

    return 0;
}