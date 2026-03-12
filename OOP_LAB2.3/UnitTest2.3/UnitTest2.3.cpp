#include "pch.h"
#include "CppUnitTest.h"
#include "Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PointUnitTest
{
    TEST_CLASS(PointTests)
    {
    public:

        TEST_METHOD(TestDistance)
        {
            Point p1(0, 0);
            Point p2(3, 4);

            double distance = p1.DistanceTo(p2);

            Assert::AreEqual(5.0, distance);
        }

    };
}