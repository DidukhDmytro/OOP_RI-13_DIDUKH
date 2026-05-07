#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    try
    {
        Array<int> a(-2, 2, 5);

        cout << "Array<int> a:" << endl;
        cout << a << endl;

        a[-2] = 10;
        a[-1] = 20;
        a[0] = 30;
        a[1] = 40;
        a[2] = 50;

        cout << endl << "After changing elements:" << endl;
        cout << a << endl;

        cout << endl << "Size: " << a.Size() << endl;
        cout << "Left border: " << a.Left() << endl;
        cout << "Right border: " << a.Right() << endl;

        cout << endl << "Find 30: index = " << a.Find(30) << endl;
        cout << "Find 20: index = " << a.Find(20) << endl;

        cout << endl << "a + 10:" << endl;
        cout << a + 10 << endl;

        cout << endl << "a - 5:" << endl;
        cout << a - 5 << endl;

        cout << endl << "a * 2:" << endl;
        cout << a * 2 << endl;

        cout << endl << "a / 10:" << endl;
        cout << a / 10 << endl;

        cout << endl << "Iterator:" << endl;
        for (a.Begin(); !a.IsEnd(); a.Next())
            cout << a.Current() << " ";
        cout << endl;

        Array<double> b(1, 4, 2.5);

        b[1] = 1.1;
        b[2] = 2.2;
        b[3] = 3.3;
        b[4] = 4.4;

        cout << endl << "Array<double> b:" << endl;
        cout << b << endl;

        cout << endl << "PrintInside:" << endl;
        PrintInside(cout, b);
        cout << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}