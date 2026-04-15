#include <iostream>
#include <vector>
#include <typeinfo>
#include "ArithmeticProgression.h"
#include "GeometricProgression.h"

using namespace std;

int main() {
    vector<Progression*> arr;

    arr.push_back(new ArithmeticProgression(1, 2));  // 1, 3, 5, 7
    arr.push_back(new ArithmeticProgression(5, 5));  // 5, 10, 15
    arr.push_back(new GeometricProgression(2, 2));   // 2, 4, 8
    arr.push_back(new GeometricProgression(3, 3));   // 3, 9, 27

    int n_values[] = { 3, 5, 7 };

    cout << "polymorphism\n\n";

    for (int i = 0; i < arr.size(); i++) {
        cout << "Object #" << i + 1 << endl;

        cout << "Real type (typeid): " << typeid(*arr[i]).name() << endl;

        cout << "Custom type: ";
        arr[i]->showType();

        for (int n : n_values) {
            cout << "Sum of first " << n << " elements = "
                << arr[i]->sum(n) << endl;
        }

        cout << "--------------------------------------\n";
    }

    for (auto p : arr) {
        delete p;
    }

    return 0;
}