#include "pch.h"
#include "CppUnitTest.h"
#include "Football.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFootball
{
	TEST_CLASS(UnitTestFootball)
	{
	public:

		TEST_METHOD(TestGetMatchDuration)
		{
			Football f("Football", 11, 90);
			Assert::AreEqual(90, f.getMatchDuration());
		}
	};
}