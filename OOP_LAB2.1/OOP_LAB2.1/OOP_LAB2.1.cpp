#include <iostream>
#include "Money.h"

using namespace std;

struct Standard { int a; int b; };
#pragma pack(push, 1)
struct Packed { int a; int b; };
#pragma pack(pop)

int main() {
    try {
        Money m1;                      // без аргументів
        Money m2(100, 5);              // з аргументами
        Money m3 = m2;                 // копіювання
        Money m4 = makeMoney(50, 10);  

        cout << "Object m2: " << m2 << endl;

        cout << "\nTesting operators:" << endl;
        ++m2; // змінює first
        m2++; // змінює second
        cout << "After ++m2 and m2++: " << m2 << endl;

        // масив об'єктів
        cout << "\nArray of objects:" << endl;
        Money wallet[2] = { Money(1, 10), Money(500, 2) };
        for (int i = 0; i < 2; i++) {
            cout << "Element " << i << ": " << wallet[i] << endl;
        }

        // Розміри класу
        cout << "\nMemory sizes:" << endl;
        cout << "Size of Money class: " << sizeof(Money) << " bytes" << endl;
        cout << "Size with #pragma pack(1): " << sizeof(Packed) << " bytes" << endl;

        // Введення
        cout << "\nEnter new data:" << endl;
        Money m5;
        cin >> m5;
        cout << "You entered: " << m5 << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}