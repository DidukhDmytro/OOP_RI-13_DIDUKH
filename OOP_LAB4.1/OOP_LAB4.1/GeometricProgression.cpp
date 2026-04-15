#include <iostream>
#include <cmath>
#include "GeometricProgression.h"

using namespace std;

GeometricProgression::GeometricProgression(double a, double r)
    : Progression(a, r) {
}

double GeometricProgression::sum(int n) {
    if (d == 1)
        return a * n;
    return a * (1 - pow(d, n)) / (1 - d);
}

void GeometricProgression::showType() {
    cout << "Geometric Progression" << endl;
}