#include "RectanglePair.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleUnitTest
{
    TEST_CLASS(RectangleTests)
    {
    public:

        TEST_METHOD(TestArea)
        {
            Rectangle r(3, 4);

            double area = r.Area();

            Assert::AreEqual(12.0, area);
        }

    };
}