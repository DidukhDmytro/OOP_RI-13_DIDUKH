#include <iostream>
#include <cmath>
#include "GeometricProgression.h"

GeometricProgression::GeometricProgression(double a, double r) : a(a), r(r) {}

double GeometricProgression::sum(int n) {
    if (n <= 0) return 0;
    if (r == 1) return a * n;
    return a * (1 - std::pow(r, n)) / (1 - r);
}

void GeometricProgression::showType() {
    std::cout << "Type: Geometric Progression" << std::endl;
}