#include "pch.h"
#include "CppUnitTest.h"
#include"Money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest21
{
	TEST_CLASS(UnitTest21)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money m(100, 5);

			Assert::AreEqual(500, m.summa());
		}
	};
}
