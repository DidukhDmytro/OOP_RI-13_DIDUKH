#include <iostream>
#include <clocale>
#include "Pair.h"
#include "RectanglePublic.h"
#include "RectanglePrivate.h"

using namespace std;

class RectangleSizeNormal
{
private:
    double width;
    double height;
};

#pragma pack(push, 1)
class RectangleSizePacked
{
private:
    double width;
    double height;
};
#pragma pack(pop)

int main()
{
    setlocale(LC_ALL, "");

    try
    {
        cout << "Size without #pragma pack(1): " << sizeof(RectangleSizeNormal) << endl;
        cout << "Size with #pragma pack(1): " << sizeof(RectangleSizePacked) << endl;
        cout << endl;

        Pair p1;
        Pair p2(3, 4);
        Pair p3("5.5,6.5");
        Pair p4(p2);

        cout << "Pairs:" << endl;
        cout << "p1 = " << p1 << endl;
        cout << "p2 = " << p2 << endl;
        cout << "p3 = " << p3 << endl;
        cout << "p4 = " << p4 << endl;
        cout << "Product p3 = " << p3.Product() << endl;
        cout << endl;

        ++p2;
        cout << "++p2 = " << p2 << endl;
        p2++;
        cout << "p2++ -> " << p2 << endl;
        --p2;
        cout << "--p2 = " << p2 << endl;
        p2--;
        cout << "p2-- -> " << p2 << endl;
        cout << endl;

        RectanglePublic rp1;
        RectanglePublic rp2(4, 5);
        RectanglePublic rp3("6.5,7.5");
        RectanglePublic rp4(rp2);

        cout << "RectanglePublic objects:" << endl;
        cout << "rp1 = " << rp1 << endl;
        cout << "rp2 = " << rp2 << endl;
        cout << "rp3 = " << rp3 << endl;
        cout << "rp4 = " << rp4 << endl;
        cout << endl;

        cout << "rp2 area = " << rp2.Area() << endl;
        cout << "rp2 perimeter = " << rp2.Perimeter() << endl;
        cout << endl;

        ++rp2;
        cout << "++rp2 = " << rp2 << endl;
        rp2++;
        cout << "rp2++ -> " << rp2 << endl;
        --rp2;
        cout << "--rp2 = " << rp2 << endl;
        rp2--;
        cout << "rp2-- -> " << rp2 << endl;
        cout << endl;

        RectanglePrivate rpr1;
        RectanglePrivate rpr2(8, 9);
        RectanglePrivate rpr3("10,11");
        RectanglePrivate rpr4(rpr2);

        cout << "RectanglePrivate objects:" << endl;
        cout << "rpr1 = " << rpr1 << endl;
        cout << "rpr2 = " << rpr2 << endl;
        cout << "rpr3 = " << rpr3 << endl;
        cout << "rpr4 = " << rpr4 << endl;
        cout << endl;

        cout << "rpr2 area = " << rpr2.Area() << endl;
        cout << "rpr2 perimeter = " << rpr2.Perimeter() << endl;
        cout << "rpr2 product = " << rpr2.Product() << endl;
        cout << endl;

        ++rpr2;
        cout << "++rpr2 = " << rpr2 << endl;
        rpr2++;
        cout << "rpr2++ -> " << rpr2 << endl;
        --rpr2;
        cout << "--rpr2 = " << rpr2 << endl;
        rpr2--;
        cout << "rpr2-- -> " << rpr2 << endl;
        cout << endl;

        Pair pairArray[2] = { Pair(1, 2), Pair("3,4") };
        RectanglePublic rectPubArray[2] = { RectanglePublic(2, 3), RectanglePublic("4,5") };
        RectanglePrivate rectPrivArray[2] = { RectanglePrivate(6, 7), RectanglePrivate("8,9") };

        cout << "Arrays:" << endl;
        for (int i = 0; i < 2; i++)
            cout << "pairArray[" << i << "] = " << pairArray[i] << endl;

        for (int i = 0; i < 2; i++)
            cout << "rectPubArray[" << i << "] = " << rectPubArray[i] << endl;

        for (int i = 0; i < 2; i++)
            cout << "rectPrivArray[" << i << "] = " << rectPrivArray[i] << endl;

        cout << endl;

        try
        {
            RectanglePublic bad(-2, 5);
        }
        catch (const exception& e)
        {
            cout << "Exception 1: " << e.what() << endl;
        }

        try
        {
            RectanglePrivate bad2("abc,10");
        }
        catch (const exception& e)
        {
            cout << "Exception 2: " << e.what() << endl;
        }

        try
        {
            RectanglePublic bad3("10");
        }
        catch (const exception& e)
        {
            cout << "Exception 3: " << e.what() << endl;
        }
    }
    catch (const exception& e)
    {
        cout << "Fatal error: " << e.what() << endl;
    }

    return 0;
}