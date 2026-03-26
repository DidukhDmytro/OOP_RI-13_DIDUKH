#include <iostream>
#include "Point.h"

using namespace std;

struct NormalPairSize
{
    double first;
    double second;
};

#pragma pack(push, 1)
struct PackedPairSize
{
    double first;
    double second;
};
#pragma pack(pop)

int main()
{
    try
    {
        Pair pair1;
        cin >> pair1;
        cout << "pair1 = " << pair1 << endl;

        Pair pair2(3, 4);
        cout << "pair2 = " << pair2 << endl;

        Pair pair3(pair2);
        cout << "pair3 = " << pair3 << endl;

        pair1 = pair2;
        cout << "pair1 after assignment = " << pair1 << endl;

        cout << "\nComparison operations:\n";
        cout << "pair1 == pair2: " << (pair1 == pair2) << endl;
        cout << "pair1 != pair3: " << (pair1 != pair3) << endl;
        cout << "pair1 > makePair(1, 2): " << (pair1 > makePair(1, 2)) << endl;
        cout << "pair1 < makePair(10, 20): " << (pair1 < makePair(10, 20)) << endl;
        cout << "pair1 >= pair2: " << (pair1 >= pair2) << endl;
        cout << "pair1 <= pair3: " << (pair1 <= pair3) << endl;

        Point p1;
        cin >> p1;
        cout << "p1 = " << p1 << endl;

        Point p2(3, 4);
        cout << "p2 = " << p2 << endl;

        Point p3(p2);
        cout << "p3 = " << p3 << endl;

        p1 = p2;
        cout << "p1 after assignment = " << p1 << endl;

        p2.MoveX(2);
        p2.MoveY(-1);
        cout << "p2 after MoveX and MoveY = " << p2 << endl;

        cout << "Distance between p2 and p3 = " << (p2 - p3) << endl;
        cout << "Distance by method DistanceTo = " << p2.DistanceTo(p3) << endl;

        Point p4 = -p2;
        cout << "p4 = -p2 = " << p4 << endl;

        cout << "++p2 = " << ++p2 << endl;
        cout << "p2++ = " << p2++ << endl;
        cout << "after p2++ = " << p2 << endl;

        cout << "--p2 = " << --p2 << endl;
        cout << "p2-- = " << p2-- << endl;
        cout << "after p2-- = " << p2 << endl;

        Point p5 = p2 + 5;
        cout << "p5 = p2 + 5 = " << p5 << endl;

        Point p6 = 10 + p2;
        cout << "p6 = 10 + p2 = " << p6 << endl;

        string s = (string)p2;
        cout << "String form of p2: " << s << endl;

        Point p7 = makePoint(8, 9);
        cout << "p7 = " << p7 << endl;

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

        cout << "\nSize without #pragma pack(1): " << sizeof(NormalPairSize) << endl;
        cout << "Size with #pragma pack(1): " << sizeof(PackedPairSize) << endl;
        cout << "Size of class Pair: " << sizeof(Pair) << endl;
        cout << "Size of class Point: " << sizeof(Point) << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}