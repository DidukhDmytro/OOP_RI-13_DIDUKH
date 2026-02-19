#include "pch.h"
#include "CppUnitTest.h"
#include"Money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MoneyUnitTests
{
    TEST_CLASS(MoneyUnitTests)
    {
    public:
        TEST_METHOD(TestSumma)
        {
            Money m;
            m.Init(200, 3); // 200 * 3 = 600
            Assert::AreEqual(600, m.summa());
        }
    };
}