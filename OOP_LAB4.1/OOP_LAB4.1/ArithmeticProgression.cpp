#include <iostream>
#include "ArithmeticProgression.h"

using namespace std;

ArithmeticProgression::ArithmeticProgression(double a, double d)
    : Progression(a, d) {
}

double ArithmeticProgression::sum(int n) {
    double an = a + (n - 1) * d;
    return n * (a + an) / 2;
}

void ArithmeticProgression::showType() {
    cout << "Arithmetic Progression" << endl;
}