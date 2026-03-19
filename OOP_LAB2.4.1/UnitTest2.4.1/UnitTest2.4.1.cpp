#include "pch.h"
#include "CppUnitTest.h"
#include"VectorN.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorNTests
{
    TEST_CLASS(VectorNTests)
    {
    public:

        TEST_METHOD(ScalarProductTest)
        {
            VectorN a(3);
            a[0] = 1;
            a[1] = 2;
            a[2] = 3;

            VectorN b(3);
            b[0] = 4;
            b[1] = 5;
            b[2] = 6;

            int result = a * b;

            Assert::AreEqual(32, result);
        }
    };
}