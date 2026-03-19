#include <iostream>
#include "Money.h"

using namespace std;

struct NormalMoneyLayout
{
    int digits[100];
    int size;
    int count;
};

#pragma pack(push, 1)
struct PackedMoneyLayout
{
    int digits[100];
    int size;
    int count;
};
#pragma pack(pop)

int main()
{
    try
    {
        cout << "Size without #pragma pack(1): " << sizeof(NormalMoneyLayout) << endl;
        cout << "Size with    #pragma pack(1): " << sizeof(PackedMoneyLayout) << endl;
        cout << endl;

        Money m1;
        Money m2(10);
        Money m3("1234.56", 10);
        Money m4 = m3; 

        cout << "Objects:" << endl;
        cout << "m1 = " << m1 << endl;
        cout << "m2 = " << m2 << endl;
        cout << "m3 = " << m3 << endl;
        cout << "m4 = " << m4 << endl;
        cout << endl;

        m2 = Money("15.25", 10);
        cout << "After assignment m2 = " << m2 << endl;

        Money sum = m2 + m3;
        cout << "m2 + m3 = " << sum << endl;

        Money diff = m3 - m2;
        cout << "m3 - m2 = " << diff << endl;

        m2 += Money("1.75", 10);
        cout << "After m2 += 1.75 -> " << m2 << endl;

        m2 -= Money("0.25", 10);
        cout << "After m2 -= 0.25 -> " << m2 << endl;
        cout << endl;

        cout << "Comparison:" << endl;
        cout << "m2 == m3 : " << (m2 == m3) << endl;
        cout << "m2 != m3 : " << (m2 != m3) << endl;
        cout << "m2 <  m3 : " << (m2 < m3) << endl;
        cout << "m2 >  m3 : " << (m2 > m3) << endl;
        cout << endl;

        cout << "Indexing:" << endl;
        cout << "m3 = " << m3 << endl;
        cout << "m3[0] (hundredths) = " << m3[0] << endl;
        cout << "m3[1] (tenths)     = " << m3[1] << endl;
        cout << "m3[2]              = " << m3[2] << endl;

        m3[0] = 9;
        m3[1] = 8;
        cout << "After changing cops with [] -> m3 = " << m3 << endl;
        cout << endl;

        string textMoney = static_cast<string>(m3);
        cout << "Conversion to string: " << textMoney << endl;
        cout << endl;

        Money arr[3] =
        {
            Money("10.00", 10),
            Money("20.50", 10),
            Money("999.99", 10)
        };

        cout << "Array of objects:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
        cout << endl;

        Money inputMoney(12);
        cout << "Enter money value (example 123.45): ";
        cin >> inputMoney;
        cout << "You entered: " << inputMoney << endl;
        cout << "size() = " << inputMoney.sizeOfMoney() << endl;
        cout << "count  = " << inputMoney.getCount() << endl;
    }
    catch (const exception& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}