#include <iostream>
#include "VectorN.h"
using namespace std;

class VectorNSizeDefault
{
private:
    int n;
    int* data;
};

#pragma pack(push, 1)
class VectorNSizePacked
{
private:
    int n;
    int* data;
};
#pragma pack(pop)

int main()
{
    try
    {
        cout << "Size of class without #pragma pack(1): "
            << sizeof(VectorNSizeDefault) << endl;

        cout << "Size of class with #pragma pack(1): "
            << sizeof(VectorNSizePacked) << endl;

        cout << "\nDifferent ways of object creation\n";

        VectorN a;                  
        VectorN b(3);               
        VectorN c(3, 2);            
        VectorN d(c);               

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;

        cout << "\nFilling vector b\n";
        b.setElement(0, 1);
        b.setElement(1, 2);
        b.setElement(2, 3);
        cout << "b = " << b << endl;

        cout << "\nIndexing\n";
        cout << "b[1] = " << b[1] << endl;
        b[1] = 10;
        cout << "After b[1] = 10, b = " << b << endl;

        cout << "\nAssignment\n";
        a = b;
        cout << "a = " << a << endl;

        cout << "\nString conversion\n";
        string str = (string)a;
        cout << "string(a) = " << str << endl;

        cout << "\nNorm of vectors\n";
        cout << "norm(a) = " << ~a << endl;
        cout << "norm(c) = " << ~c << endl;

        cout << "\nScalar product\n";
        VectorN e(3);
        e[0] = 4;
        e[1] = 5;
        e[2] = 6;
        cout << "a = " << a << endl;
        cout << "e = " << e << endl;
        cout << "a * e = " << a * e << endl;

        cout << "\nComparison\n";
        cout << "a == e : " << (a == e) << endl;
        cout << "a != e : " << (a != e) << endl;
        cout << "a < e  : " << (a < e) << endl;
        cout << "a > e  : " << (a > e) << endl;

        cout << "\nArray of objects\n";
        VectorN arr[3] = {
            VectorN(2, 1),
            VectorN(3, 2),
            VectorN(4, 3)
        };

        for (int i = 0; i < 3; i++)
        {
            cout << "arr[" << i << "] = " << arr[i]
                << ", norm = " << ~arr[i] << endl;
        }

        cout << "\nInput demonstration\n";
        VectorN userVector;
        cin >> userVector;
        cout << "You entered: " << userVector << endl;
        cout << "Norm = " << ~userVector << endl;
    }
    catch (exception& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}