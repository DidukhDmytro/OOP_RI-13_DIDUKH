#include "pch.h"
#include "CppUnitTest.h"
#include<Circle.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircleUnitTests
{
	TEST_CLASS(CircleUnitTests)
	{
	public:
		TEST_METHOD(TestArea)
		{
			Circle c;
			c.Init(0, 0, 5); // Радіус = 5

			// Площа = PI * 5^2 = 3.14159... * 25 = 78.5398...
			double expected = 78.5;
			double actual = c.Area();

			// Використовуємо точність 0.0001
			Assert::AreEqual(expected, actual, 0.0001);
		}
	};
}