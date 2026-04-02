#include <iostream>
#include "B1.h"
#include "B2.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"

using namespace std;

int main()
{
    B1 objB1(10);
    B2 objB2(20);
    D1 objD1(11, 21, 31);
    D2 objD2(12, 22, 32, 42);
    D3 objD3(13, 23, 33, 43, 53);

    cout << "Sizes of objects:" << endl;
    cout << "sizeof(B1) = " << sizeof(objB1) << endl;
    cout << "sizeof(B2) = " << sizeof(objB2) << endl;
    cout << "sizeof(D1) = " << sizeof(objD1) << endl;
    cout << "sizeof(D2) = " << sizeof(objD2) << endl;
    cout << "sizeof(D3) = " << sizeof(objD3) << endl;

    cout << endl << "show() results:" << endl;
    objB1.show();
    objB2.show();
    objD1.show();
    objD2.show();
    objD3.show();

    return 0;
}