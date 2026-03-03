#include "pch.h" // Обов'язково для проектів тестів у VS
#include "CppUnitTest.h"
#include<Money.h>
#include<Bankomat.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BankomatUnitTests
{
	TEST_CLASS(MoneyTests)
	{
	public:

		TEST_METHOD(TestToKopecksCalculation)
		{
			Money m;
			// 1 bill of 500, 2 bills of 200, 1 coin of 50, 1 coin of 5
			// Total: 50000 + 40000 + 50 + 5 = 90055 kopecks
			m.Init(1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0);

			Assert::AreEqual(90055LL, m.toKopecks());
		}

		TEST_METHOD(TestToStringFormatting)
		{
			Money m;
			m.Init(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0); // 100.05

			std::string expected = "100,05";
			Assert::AreEqual(expected, m.toString());
		}

		TEST_METHOD(TestMoneyAddition)
		{
			Money m1, m2;
			m1.Init(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 500
			m2.Init(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 200

			Money result = m1.Add(m2);
			Assert::AreEqual(70000LL, result.toKopecks());
		}
	};

	TEST_CLASS(BankomatTests)
	{
	public:

		TEST_METHOD(TestWithdrawWithinLimits)
		{
			Money initial;
			initial.Init(10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 5000

			Bankomat atm;
			atm.Init("TEST-01", initial, 100.0, 2000.0);

			// Зняття 500 (в межах лімітів)
			bool success = atm.Withdraw(500.0);

			Assert::IsTrue(success);
			Assert::AreEqual(std::string("4500,00"), atm.toString());
		}

		TEST_METHOD(TestWithdrawOutsideLimits)
		{
			Money initial;
			initial.Init(10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 5000

			Bankomat atm;
			atm.Init("TEST-01", initial, 100.0, 1000.0);

			// Спроба зняти 1500 (більше за макс. ліміт 1000)
			bool result = atm.Withdraw(1500.0);

			Assert::IsFalse(result);
		}

		TEST_METHOD(TestWithdrawInsufficientFunds)
		{
			Money lowCash;
			lowCash.Init(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0); // Тільки 5 грн

			Bankomat atm;
			atm.Init("LOW-CASH", lowCash, 1.0, 100.0);

			bool result = atm.Withdraw(50.0);

			Assert::IsFalse(result);
		}
	};
}