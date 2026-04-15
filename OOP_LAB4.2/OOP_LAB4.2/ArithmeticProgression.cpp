#include <iostream>
#include "ArithmeticProgression.h"

ArithmeticProgression::ArithmeticProgression(double a, double d) : a(a), d(d) {}

double ArithmeticProgression::sum(int n) {
    if (n <= 0) return 0;
    double an = a + (n - 1) * d;
    return n * (a + an) / 2.0;
}

void ArithmeticProgression::showType() {
    std::cout << "Type: Arithmetic Progression" << std::endl;
}