#include "Address.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest14
{
	TEST_CLASS(UnitTest14)
	{
	public:

		TEST_METHOD(TestSetAndGetCity)
		{
			Address adr;
			adr.setCity("Lviv");

			Assert::AreEqual(std::string("Lviv"), adr.getCity());
		}

		TEST_METHOD(TestSetPostIndex)
		{
			Address adr;
			adr.setPostIndex(79000);

			Assert::AreEqual(79000, adr.getPostIndex());
		}

		TEST_METHOD(TestToString)
		{
			Address adr;
			adr.Init("Kyiv", "Shevchenka", "10", 12345);

			std::string expected =
				"Address: Kyiv, st. Shevchenka, house. 10, index: 12345";

			Assert::AreEqual(expected, adr.toString());
		}
	};
}
