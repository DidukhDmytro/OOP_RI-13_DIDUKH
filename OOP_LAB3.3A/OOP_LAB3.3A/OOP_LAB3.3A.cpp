#include <iostream>
#include "PointPublic.h"
#include "PointPrivate.h"

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
    try
    {
        cout << "PUBLIC INHERITANCE" << endl;

        PointPublic p1;
        cin >> p1;
        cout << "p1 = " << p1 << endl;

        PointPublic p2(3, 4);
        cout << "p2 = " << p2 << endl;

        PointPublic p3(p2);
        cout << "p3 = " << p3 << endl;

        p1 = p2;
        cout << "p1 after assignment = " << p1 << endl;

        p2.MoveX(2);
        p2.MoveY(-1);
        cout << "p2 after MoveX and MoveY = " << p2 << endl;

        cout << "Distance between p2 and p3 = " << (p2 - p3) << endl;

        PointPublic p4 = -p2;
        cout << "p4 = -p2 = " << p4 << endl;

        cout << "++p2 = " << ++p2 << endl;
        cout << "p2++ = " << p2++ << endl;
        cout << "after p2++: " << p2 << endl;

        cout << "--p2 = " << --p2 << endl;
        cout << "p2-- = " << p2-- << endl;
        cout << "after p2--: " << p2 << endl;

        PointPublic p5 = p2 + 5;
        cout << "p5 = p2 + 5 = " << p5 << endl;

        PointPublic p6 = 10 + p2;
        cout << "p6 = 10 + p2 = " << p6 << endl;

        string s1 = (string)p2;
        cout << "string(p2) = " << s1 << endl;

        PointPublic arr1[3];
        cout << "\nEnter 3 public points:\n";
        for (int i = 0; i < 3; i++)
            cin >> arr1[i];

        cout << "\nArray of public points:\n";
        for (int i = 0; i < 3; i++)
            cout << "arr1[" << i << "] = " << arr1[i] << endl;

        cout << "\nPRIVATE INHERITANCE" << endl;

        PointPrivate q1;
        cin >> q1;
        cout << "q1 = " << q1 << endl;

        PointPrivate q2(7, 8);
        cout << "q2 = " << q2 << endl;

        PointPrivate q3(q2);
        cout << "q3 = " << q3 << endl;

        q1 = q2;
        cout << "q1 after assignment = " << q1 << endl;

        q2.MoveX(-2);
        q2.MoveY(3);
        cout << "q2 after MoveX and MoveY = " << q2 << endl;

        cout << "Distance between q2 and q3 = " << (q2 - q3) << endl;

        PointPrivate q4 = -q2;
        cout << "q4 = -q2 = " << q4 << endl;

        cout << "++q2 = " << ++q2 << endl;
        cout << "q2++ = " << q2++ << endl;
        cout << "after q2++: " << q2 << endl;

        cout << "--q2 = " << --q2 << endl;
        cout << "q2-- = " << q2-- << endl;
        cout << "after q2--: " << q2 << endl;

        PointPrivate q5 = q2 + 2;
        cout << "q5 = q2 + 2 = " << q5 << endl;

        PointPrivate q6 = 3 + q2;
        cout << "q6 = 3 + q2 = " << q6 << endl;

        string s2 = (string)q2;
        cout << "string(q2) = " << s2 << endl;

        PointPrivate arr2[3];
        cout << "\nEnter 3 private points:\n";
        for (int i = 0; i < 3; i++)
            cin >> arr2[i];

        cout << "\nArray of private points:\n";
        for (int i = 0; i < 3; i++)
            cout << "arr2[" << i << "] = " << arr2[i] << endl;

        cout << "\nSize without #pragma pack(1): " << sizeof(NormalPointSize) << endl;
        cout << "Size with #pragma pack(1): " << sizeof(PackedPointSize) << endl;
        cout << "Size of PointBase: " << sizeof(PointBase) << endl;
        cout << "Size of PointPublic: " << sizeof(PointPublic) << endl;
        cout << "Size of PointPrivate: " << sizeof(PointPrivate) << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}