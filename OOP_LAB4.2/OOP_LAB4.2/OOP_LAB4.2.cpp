#include <iostream>
#include <vector>
#include <typeinfo>
#include "ArithmeticProgression.h"
#include "GeometricProgression.h"

using namespace std;

int main() {
    vector<IProgression*> arr;

    arr.push_back(new ArithmeticProgression(1.0, 2.0));  // 1, 3, 5
    arr.push_back(new GeometricProgression(2.0, 3.0));   // 2, 6, 18
    arr.push_back(new ArithmeticProgression(10.0, -2.0)); // 10, 8, 6
    arr.push_back(new GeometricProgression(1.0, 0.5));   // 1, 0.5, 0.25

    cout << "LAB 4.2: Interfaces and Polymorphism\n";
    cout << "======================================\n\n";

    for (size_t i = 0; i < arr.size(); ++i) {
        cout << "Object #" << i + 1 << ":" << endl;

        // Виведення типу через RTTI
        cout << "Real class name (typeid): " << typeid(*arr[i]).name() << endl;

        // Виведення через віртуальну функцію
        arr[i]->showType();

        int n = 5;
        cout << "Sum of first " << n << " elements = " << arr[i]->sum(n) << endl;

        cout << "--------------------------------------\n";
    }

    for (auto p : arr) {
        delete p;
    }
    arr.clear();

    return 0;
}