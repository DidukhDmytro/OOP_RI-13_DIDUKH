#include "pch.h"
#include "CppUnitTest.h"
#include "Rectangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangle
{
	TEST_CLASS(UnitTestRectangle)
	{
	public:

		TEST_METHOD(TestArea)
		{
			Rectangle r(4, 5);
			Assert::AreEqual(20, r.area());
		}
	};
}