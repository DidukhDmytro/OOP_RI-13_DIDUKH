#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(MoneyTests)
{
public:

    TEST_METHOD(TestMoneyCreationAndSum)
    {
        class Money
        {
        public:
            int first;
            int second;

            Money(int f, int s) : first(f), second(s)
            {
                if (f <= 0 || s <= 0)
                    throw std::exception("Invalid value");
            }

            int summa() const
            {
                return first * second;
            }
        };

        Money m(10, 5);

        Assert::AreEqual(10, m.first);
        Assert::AreEqual(5, m.second);
        Assert::AreEqual(50, m.summa());
    }


    TEST_METHOD(TestMoneyIncrementLogic)
    {
        class Money
        {
        public:
            int first;
            int second;

            Money(int f, int s) : first(f), second(s) {}

            Money& operator++()
            {
                ++first;
                return *this;
            }

            Money operator++(int)
            {
                Money temp = *this;
                second++;
                return temp;
            }
        };

        Money m(10, 5);

        ++m;
        Assert::AreEqual(11, m.first);

        Money old = m++;
        Assert::AreEqual(5, old.second);
        Assert::AreEqual(6, m.second);
    }


    TEST_METHOD(TestExceptionHandling)
    {
        class Money
        {
        public:
            int first;
            int second;

            Money(int f, int s)
            {
                if (s <= 0)
                    throw std::invalid_argument("Count must be positive");

                first = f;
                second = s;
            }
        };

        try
        {
            Money m(10, -5);
            Assert::Fail(L"Exception was not thrown");
        }
        catch (std::invalid_argument&)
        {
            Assert::IsTrue(true);
        }
    }
};
