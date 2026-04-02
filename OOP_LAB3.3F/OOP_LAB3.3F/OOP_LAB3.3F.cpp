#include <iostream>
#include "Bankomat.h"

int main()
{
    using namespace std;

    Money m1(1000);
    Money m2(500);

    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;

    Money m3 = m1 + m2;
    cout << "m1 + m2 = " << m3 << endl;

    Money m4 = m1 - m2;
    cout << "m1 - m2 = " << m4 << endl;

    Money m5 = m1 * 2.5;
    cout << "m1 * 2.5 = " << m5 << endl;

    Money m6 = m1 / 2.0;
    cout << "m1 / 2 = " << m6 << endl;

    cout << "m1 > m2: " << (m1 > m2) << endl;
    cout << "m1 < m2: " << (m1 < m2) << endl;
    cout << "m1 == m2: " << (m1 == m2) << endl;

    cout << "Prefix ++m1: " << ++m1 << endl;
    cout << "Postfix m1++: " << m1++ << endl;
    cout << "After m1++: " << m1 << endl;

    cout << "Prefix --m1: " << --m1 << endl;
    cout << "Postfix m1--: " << m1-- << endl;
    cout << "After m1--: " << m1 << endl;

    cout << "Enter money value: ";
    cin >> m2;
    cout << "You entered: " << m2 << endl;

    BankomatPublic atm1(1, 10000, 100, 5000);

    atm1.Display();

    atm1.LoadMoney(2000);
    atm1.Display();

    if (atm1.Withdraw(300))
        cout << "Withdraw success\n";
    else
        cout << "Withdraw failed\n";

    atm1.Display();

    BankomatPrivate atm2(2, 5000, 50, 3000);
    atm2.Display();

    return 0;
}