#include "pch.h"
#include "CppUnitTest.h"
#include "Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PointUnitTests
{
    TEST_CLASS(PointUnitTests)
    {
    public:

        TEST_METHOD(DistanceTest)
        {
            Point p1(0, 0);
            Point p2(3, 4);

            double result = p1.DistanceTo(p2);

            Assert::AreEqual(5.0, result, 0.0001);
        }
    };
}
