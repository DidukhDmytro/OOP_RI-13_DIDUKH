#include <iostream>
#include "Array.h"
#include "Algorithms.h"

using namespace std;

void printResult(double* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    Array a(8);

    a[0] = 1;
    a[1] = -2;
    a[2] = 0;
    a[3] = 4;
    a[4] = -5;
    a[5] = 0;
    a[6] = 7;
    a[7] = -3;

    cout << "Initial Array:" << endl;
    cout << a << endl;

    double b[20];
    double c[20];
    double d[20];

    int n = erase(a.begin(), a.end(), b, 0.0);

    cout << endl << "After erase value 0:" << endl;
    printResult(b, n);

    Negative<double> negative;
    int k = erase_if(a.begin(), a.end(), c, negative);

    cout << endl << "After erase_if negative elements:" << endl;
    printResult(c, k);

    Positive<double> positive;
    int m = erase_if(a.begin(), a.end(), d, positive);

    cout << endl << "After erase_if positive elements:" << endl;
    printResult(d, m);

    return 0;
}