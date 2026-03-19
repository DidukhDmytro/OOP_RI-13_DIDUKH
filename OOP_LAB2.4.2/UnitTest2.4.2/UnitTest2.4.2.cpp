#include "pch.h"
#include "CppUnitTest.h"
#include<Money.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MoneyUnitTest
{
    TEST_CLASS(MoneyUnitTest)
    {
    public:

        TEST_METHOD(TestAddition)
        {
            Money a("12.35", 10);
            Money b("7.15", 10);

            Money c = a + b;

            std::string expected = "19.50";
            std::string actual = string(c);

            Assert::AreEqual(expected.c_str(), actual.c_str());
        }
    };
}