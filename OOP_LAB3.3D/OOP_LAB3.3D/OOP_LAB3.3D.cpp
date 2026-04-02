#include <iostream>
#include "Pair.h"
#include "RectanglePublic.h"
#include "RectanglePrivate.h"
using namespace std;

#pragma pack(push, 1)
class PairPacked
{
private:
    double first;
    double second;
};

class RectanglePublicPacked : public PairPacked
{
};
#pragma pack(pop)

int main()
{
    cout << "Pair" << endl;
    Pair p1;
    Pair p2(3, 4);
    Pair p3 = p2;

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "Product of p2 = " << p2.Product() << endl;

    ++p2;
    cout << "After ++p2: " << p2 << endl;

    p2--;
    cout << "After p2--: " << p2 << endl;

    string s1 = (string)p2;
    cout << "String conversion: " << s1 << endl;

    Pair pairArray[2] = { Pair(1, 2), Pair(5, 6) };
    cout << "\nArray of Pair objects:" << endl;
    for (int i = 0; i < 2; i++)
        cout << pairArray[i] << endl;

    cout << "\nRectanglePublic (public inheritance)" << endl;
    RectanglePublic rp1;
    RectanglePublic rp2(5, 7);
    RectanglePublic rp3 = rp2;

    cout << "rp1 = " << rp1 << endl;
    cout << "rp2 = " << rp2 << endl;
    cout << "rp3 = " << rp3 << endl;
    cout << "Perimeter = " << rp2.Perimeter() << endl;
    cout << "Area = " << rp2.Area() << endl;
    cout << "Inherited Product = " << rp2.Product() << endl;

    ++rp2;
    cout << "After ++rp2: " << rp2 << endl;

    RectanglePublic rectPubArray[2] = { RectanglePublic(2, 3), RectanglePublic(4, 6) };
    cout << "\nArray of RectanglePublic objects:" << endl;
    for (int i = 0; i < 2; i++)
        cout << rectPubArray[i] << endl;

    cout << "\nRectanglePrivate (private inheritance)" << endl;
    RectanglePrivate rr1;
    RectanglePrivate rr2(8, 9);
    RectanglePrivate rr3 = rr2;

    cout << "rr1 = " << rr1 << endl;
    cout << "rr2 = " << rr2 << endl;
    cout << "rr3 = " << rr3 << endl;
    cout << "Perimeter = " << rr2.Perimeter() << endl;
    cout << "Area = " << rr2.Area() << endl;
    cout << "Product = " << rr2.Product() << endl;

    rr2--;
    cout << "After rr2--: " << rr2 << endl;

    RectanglePrivate rectPrivArray[2] = { RectanglePrivate(3, 5), RectanglePrivate(6, 10) };
    cout << "\nArray of RectanglePrivate objects:" << endl;
    for (int i = 0; i < 2; i++)
        cout << rectPrivArray[i] << endl;

    cout << "\nSizeof" << endl;
    cout << "sizeof(Pair) = " << sizeof(Pair) << endl;
    cout << "sizeof(RectanglePublic) = " << sizeof(RectanglePublic) << endl;
    cout << "sizeof(RectanglePrivate) = " << sizeof(RectanglePrivate) << endl;

    cout << "\nWith #pragma pack(1):" << endl;
    cout << "sizeof(PairPacked) = " << sizeof(PairPacked) << endl;
    cout << "sizeof(RectanglePublicPacked) = " << sizeof(RectanglePublicPacked) << endl;

    return 0;
}