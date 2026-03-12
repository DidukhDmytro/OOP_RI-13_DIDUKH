#include "pch.h"
#include "CppUnitTest.h"
#include"Bankomat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestATM
{
    TEST_CLASS(MoneyTests)
    {
    public:

        TEST_METHOD(TestAddMoney)
        {
            Bankomat::Money m1;
            Bankomat::Money m2;

            m1.Init(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 500 грн
            m2.Init(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 200 грн

            Bankomat::Money result = m1.Add(m2);

            Assert::AreEqual((long long)70000, result.toKopecks());
        }

    };
}