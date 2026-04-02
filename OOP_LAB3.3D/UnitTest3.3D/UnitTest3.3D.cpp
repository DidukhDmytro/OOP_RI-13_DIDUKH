#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPair
{
    TEST_CLASS(UnitTestPair)
    {
    public:
        class Pair
        {
        private:
            double first;
            double second;

        public:
            Pair(double f, double s) : first(f), second(s) {}

            double Product() const
            {
                return first * second;
            }
        };

        TEST_METHOD(TestProduct)
        {
            Pair p(3, 4);

            double result = p.Product();

            Assert::AreEqual(12.0, result, 0.0001);
        }
    };
}