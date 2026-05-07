#include <iostream>
#include "Money.h"

using namespace std;

int main() {

    try {
        Money m1(50, 10);
        cout << m1 << endl;

        Money m2 = m1;
        cout << m2 << endl;

        m1++;
        ++m2;

        cout << m1 << endl;
        cout << m2 << endl;

        Money arr[2] = { Money(10, 5), Money(100, 2) };

        for (int i = 0; i < 2; i++) {
            cout << arr[i] << endl;
        }

        cout << "\nSize without pack: " << sizeof(Money) << endl;

#pragma pack(push,1)
        cout << "Size with pack(1): " << sizeof(Money) << endl;
#pragma pack(pop)
    }
    catch (...) {
        cout << "Unexpected error\n";
    }

    try {
        Money m3(3, 10);
    }
    catch (bad_exception& e) {
        cout << "bad_exception caught\n";
    }

    try {
        Money m4(50, -5);
    }
    catch (exception e) {
        cout << "exception caught: " << e.what() << endl;
    }

    try {
        throw new exception();
    }
    catch (exception* e) {
        cout << "pointer exception caught: " << e->what() << endl;
        delete e;
    }

    return 0;
}