#include <iostream>
#include <ctime>
#include <cmath>
#include "Array.h"

using namespace std;

Array processArray(double* rawArray, int n) {
    Array result(n);

    double sum = 0;
    double absSum = 0;
    double minVal = rawArray[0];

    for (int i = 0; i < n; i++) {
        result[i] = rawArray[i];
        if (rawArray[i] < minVal) minVal = rawArray[i];
    }

    cout << "Minimum found: " << minVal << endl;


    for (int i = 0; i < n; i++) {
        result[i] *= minVal;
        sum += result[i];
        absSum += std::abs(result[i]);
    }

    result.push_back(sum);
    result.push_back(absSum / n);

    return result;
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "Enter size n: "; cin >> n;

    // створення масиву
    double* a = new double[n];
    cout << "Initial random array: " << endl;
    for (int i = 0; i < n; i++) {
        a[i] = (rand() % 101) - 50; // діапазон -50/+50
        cout << a[i] << " ";
    }
    cout << endl << "-------------------" << endl;

    try {
        Array res = processArray(a, n);

        cout << "Result Array (Multiplied by min, with Sum and Avg at end):" << endl;
        cout << res << endl;

    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    delete[] a;
    return 0;
}