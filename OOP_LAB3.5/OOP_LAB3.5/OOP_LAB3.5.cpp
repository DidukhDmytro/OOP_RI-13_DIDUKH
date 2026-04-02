#include <iostream>
#include "Decimal.h"

#pragma pack(push, 1)
class ArrayPacked
{
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;
};

class DecimalPacked : public ArrayPacked
{
};
#pragma pack(pop)

int main()
{
    Decimal a("12345");
    Decimal b("678");

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    Decimal c = a + b;
    std::cout << "a + b = " << c << std::endl;

    Decimal d = a - b;
    std::cout << "a - b = " << d << std::endl;

    Decimal e = a * b;
    std::cout << "a * b = " << e << std::endl;

    Decimal f = a / b;
    std::cout << "a / b = " << f << std::endl;

    Decimal g = a % b;
    std::cout << "a % b = " << g << std::endl;

    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;

    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a after a++ = " << a << std::endl;

    std::cout << "--a = " << --a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a after a-- = " << a << std::endl;

    Decimal x;
    std::cout << "Enter decimal number: ";
    std::cin >> x;
    std::cout << "x = " << x << std::endl;

    Decimal arr[3] = { Decimal("10"), Decimal("20"), Decimal("30") };
    std::cout << "Array of Decimal objects:" << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << arr[i] << std::endl;

    std::cout << "Digit a[0] = " << (int)a[0] << std::endl;

    a[0] = 9;
    std::cout << "a after a[0] = 9: " << a << std::endl;

    std::string s = (std::string)a;
    std::cout << "String conversion: " << s << std::endl;

    std::cout << "sizeof(Array) = " << sizeof(Array) << std::endl;
    std::cout << "sizeof(Decimal) = " << sizeof(Decimal) << std::endl;
    std::cout << "sizeof(ArrayPacked) = " << sizeof(ArrayPacked) << std::endl;
    std::cout << "sizeof(DecimalPacked) = " << sizeof(DecimalPacked) << std::endl;

    return 0;
}