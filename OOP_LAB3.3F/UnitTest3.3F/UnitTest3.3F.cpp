#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Money
{
private:
    int n500, n200, n100, n50, n20, n10, n5, n2, n1;
    int k50, k25, k10, k5, k2, k1;

public:
    Money() : Money(0)
    {
    }

    Money(int sum)
    {
        Init(sum);
    }

    Money(const Money& other)
    {
        n500 = other.n500;
        n200 = other.n200;
        n100 = other.n100;
        n50 = other.n50;
        n20 = other.n20;
        n10 = other.n10;
        n5 = other.n5;
        n2 = other.n2;
        n1 = other.n1;
        k50 = other.k50;
        k25 = other.k25;
        k10 = other.k10;
        k5 = other.k5;
        k2 = other.k2;
        k1 = other.k1;
    }

    void Init(int sum)
    {
        int kop = sum * 100;

        n500 = kop / 50000; kop %= 50000;
        n200 = kop / 20000; kop %= 20000;
        n100 = kop / 10000; kop %= 10000;
        n50 = kop / 5000; kop %= 5000;
        n20 = kop / 2000; kop %= 2000;
        n10 = kop / 1000; kop %= 1000;
        n5 = kop / 500; kop %= 500;
        n2 = kop / 200; kop %= 200;
        n1 = kop / 100; kop %= 100;
        k50 = kop / 50; kop %= 50;
        k25 = kop / 25; kop %= 25;
        k10 = kop / 10; kop %= 10;
        k5 = kop / 5; kop %= 5;
        k2 = kop / 2; kop %= 2;
        k1 = kop;
    }

    int ToKopecks() const
    {
        return n500 * 50000 + n200 * 20000 + n100 * 10000 +
            n50 * 5000 + n20 * 2000 + n10 * 1000 +
            n5 * 500 + n2 * 200 + n1 * 100 +
            k50 * 50 + k25 * 25 + k10 * 10 +
            k5 * 5 + k2 * 2 + k1;
    }

    Money operator+(const Money& other) const
    {
        Money result;
        result.Init((ToKopecks() + other.ToKopecks()) / 100);
        return result;
    }
};

namespace UnitTestBankomat
{
    TEST_CLASS(UnitTestBankomat)
    {
    public:

        TEST_METHOD(TestMoneyAddition)
        {
            Money m1(1000);
            Money m2(500);
            Money m3 = m1 + m2;

            Assert::AreEqual(150000, m3.ToKopecks());
        }
    };
}