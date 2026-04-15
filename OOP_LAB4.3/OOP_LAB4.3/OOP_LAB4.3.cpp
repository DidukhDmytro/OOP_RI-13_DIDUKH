#include <iostream>
#include <vector>
#include <typeinfo>
#include "Money.h"
#include "BitString.h"

using namespace std;

int main() {
    vector<Array*> arr;

    Money* m1 = new Money(5, 0);
    (*m1)[0] = 5; (*m1)[1] = 2; (*m1)[2] = 1; // 125

    Money* m2 = new Money(5, 0);
    (*m2)[0] = 5; (*m2)[1] = 8; (*m2)[2] = 0; // 085

    BitString* b1 = new BitString(8, 0);
    (*b1)[0] = 1; (*b1)[1] = 0; (*b1)[2] = 1; // 101

    arr.push_back(m1);
    arr.push_back(m2);
    arr.push_back(b1);

    cout << "--- Polimorphic Objects Info ---" << endl;
    for (auto obj : arr) {
        cout << "Real type: " << typeid(*obj).name() << endl;

        if (auto m = dynamic_cast<Money*>(obj)) {
            m->print();
        }
        else if (auto b = dynamic_cast<BitString*>(obj)) {
            b->print();
        }
        cout << "\n----------------" << endl;
    }

    cout << "\n--- Testing Virtual Add ---" << endl;
    Array* sumMoney = arr[0]->add(*arr[1]);
    cout << "Sum of Money: ";
    static_cast<Money*>(sumMoney)->print();
    cout << endl;

    for (auto obj : arr) delete obj;
    delete sumMoney;

    return 0;
}