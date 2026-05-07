#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestExceptionsLab
{
    class Empty
    {
    };

    class Error
    {
    private:
        int hours;
        int minutes;
        string message;

    public:
        Error(int h, int m, const string& msg)
            : hours(h), minutes(m), message(msg) {
        }

        string What() const
        {
            return message + " (" + to_string(hours) + ":" + to_string(minutes) + ")";
        }

        int GetHours() const { return hours; }
        int GetMinutes() const { return minutes; }
    };

    class TimeError : public exception
    {
    private:
        int hours;
        int minutes;
        string message;

    public:
        TimeError(int h, int m, const string& msg)
            : hours(h), minutes(m), message(msg) {
        }

        const char* what() const noexcept override
        {
            return message.c_str();
        }

        int GetHours() const { return hours; }
        int GetMinutes() const { return minutes; }
    };

    bool IsValidTime(int hours, int minutes)
    {
        return hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59;
    }

    int ToSeconds1(int hours, int minutes)
    {
        if (!IsValidTime(hours, minutes))
            throw 1;

        return hours * 3600 + minutes * 60;
    }

    int ToSeconds3(int hours, int minutes)
    {
        if (!IsValidTime(hours, minutes))
            throw invalid_argument("invalid time");

        return hours * 3600 + minutes * 60;
    }

    int ToSeconds4(int hours, int minutes)
    {
        if (!IsValidTime(hours, minutes))
            throw Empty();

        return hours * 3600 + minutes * 60;
    }

    int ToSeconds5(int hours, int minutes)
    {
        if (!IsValidTime(hours, minutes))
            throw Error(hours, minutes, "invalid time");

        return hours * 3600 + minutes * 60;
    }

    int ToSeconds6(int hours, int minutes)
    {
        if (!IsValidTime(hours, minutes))
            throw TimeError(hours, minutes, "invalid time");

        return hours * 3600 + minutes * 60;
    }

    TEST_CLASS(UnitTestExceptionsLab)
    {
    public:

        TEST_METHOD(TestValidTime)
        {
            Assert::IsTrue(IsValidTime(12, 30));
            Assert::IsFalse(IsValidTime(25, 10));
            Assert::IsFalse(IsValidTime(10, 78));
        }

        TEST_METHOD(TestToSeconds1Correct)
        {
            Assert::AreEqual(9000, ToSeconds1(2, 30));
        }

        TEST_METHOD(TestToSeconds1ThrowsInt)
        {
            bool thrown = false;
            try
            {
                ToSeconds1(25, 78);
            }
            catch (int)
            {
                thrown = true;
            }
            Assert::IsTrue(thrown);
        }

        TEST_METHOD(TestToSeconds3Correct)
        {
            Assert::AreEqual(3660, ToSeconds3(1, 1));
        }

        TEST_METHOD(TestToSeconds3ThrowsInvalidArgument)
        {
            bool thrown = false;
            try
            {
                ToSeconds3(-1, 20);
            }
            catch (const invalid_argument&)
            {
                thrown = true;
            }
            Assert::IsTrue(thrown);
        }

        TEST_METHOD(TestToSeconds4ThrowsEmpty)
        {
            bool thrown = false;
            try
            {
                ToSeconds4(24, 0);
            }
            catch (Empty)
            {
                thrown = true;
            }
            Assert::IsTrue(thrown);
        }

        TEST_METHOD(TestToSeconds5ThrowsError)
        {
            bool thrown = false;
            try
            {
                ToSeconds5(30, 10);
            }
            catch (const Error& e)
            {
                thrown = true;
                Assert::AreEqual(30, e.GetHours());
                Assert::AreEqual(10, e.GetMinutes());
            }
            Assert::IsTrue(thrown);
        }

        TEST_METHOD(TestToSeconds6ThrowsTimeError)
        {
            bool thrown = false;
            try
            {
                ToSeconds6(22, 70);
            }
            catch (const TimeError& e)
            {
                thrown = true;
                Assert::AreEqual(string("invalid time"), string(e.what()));
                Assert::AreEqual(22, e.GetHours());
                Assert::AreEqual(70, e.GetMinutes());
            }
            Assert::IsTrue(thrown);
        }
    };
}