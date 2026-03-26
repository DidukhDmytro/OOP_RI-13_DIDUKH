#include "pch.h"
#include "CppUnitTest.h"
#include "Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPoint
{
	TEST_CLASS(UnitTestPoint)
	{
	public:

		TEST_METHOD(TestDistanceTo)
		{
			Point p1(0, 0);
			Point p2(3, 4);

			Assert::AreEqual(5.0, p1.DistanceTo(p2), 0.0001);
		}
	};
}