#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <sstream>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestRectangle
{
    class Pair
    {
    private:
        double first;
        double second;

    protected:
        static double ParseNumber(const string& value)
        {
            stringstream ss(value);
            double number;
            ss >> number;
            if (ss.fail() || !ss.eof())
                throw invalid_argument("Invalid numeric value in string");
            return number;
        }

        void ParseFromString(const string& str)
        {
            size_t comma = str.find(',');
            if (comma == string::npos)
                throw invalid_argument("Invalid string format. Expected: first,second");

            string left = str.substr(0, comma);
            string right = str.substr(comma + 1);

            double a = ParseNumber(left);
            double b = ParseNumber(right);

            Init(a, b);
        }

    public:
        Pair() : first(0), second(0) {}
        Pair(double first, double second) { Init(first, second); }
        Pair(const string& str) { ParseFromString(str); }
        Pair(const Pair& other) : first(other.first), second(other.second) {}

        double GetFirst() const { return first; }
        double GetSecond() const { return second; }

        void SetFirst(double value) { first = value; }
        void SetSecond(double value) { second = value; }

        void Init(double first, double second)
        {
            SetFirst(first);
            SetSecond(second);
        }

        double Product() const
        {
            return first * second;
        }

        string toString() const
        {
            stringstream sout;
            sout << "Pair(" << first << ", " << second << ")";
            return sout.str();
        }

        Pair& operator=(const Pair& other)
        {
            if (this != &other)
            {
                first = other.first;
                second = other.second;
            }
            return *this;
        }

        Pair& operator++()
        {
            ++first;
            ++second;
            return *this;
        }

        Pair operator++(int)
        {
            Pair temp(*this);
            ++(*this);
            return temp;
        }

        Pair& operator--()
        {
            --first;
            --second;
            return *this;
        }

        Pair operator--(int)
        {
            Pair temp(*this);
            --(*this);
            return temp;
        }
    };

    class RectanglePublic : public Pair
    {
    public:
        RectanglePublic() : Pair() {}
        RectanglePublic(double width, double height) { Init(width, height); }
        RectanglePublic(const string& str) : Pair()
        {
            size_t comma = str.find(',');
            if (comma == string::npos)
                throw invalid_argument("Invalid string format. Expected: width,height");

            string left = str.substr(0, comma);
            string right = str.substr(comma + 1);

            double w = ParseNumber(left);
            double h = ParseNumber(right);

            Init(w, h);
        }

        RectanglePublic(const RectanglePublic& other) : Pair(other) {}

        double GetWidth() const { return GetFirst(); }
        double GetHeight() const { return GetSecond(); }

        void SetWidth(double value)
        {
            if (value < 0)
                throw invalid_argument("Width must be non-negative");
            Pair::SetFirst(value);
        }

        void SetHeight(double value)
        {
            if (value < 0)
                throw invalid_argument("Height must be non-negative");
            Pair::SetSecond(value);
        }

        void Init(double width, double height)
        {
            SetWidth(width);
            SetHeight(height);
        }

        double Perimeter() const
        {
            return 2 * (GetWidth() + GetHeight());
        }

        double Area() const
        {
            return GetWidth() * GetHeight();
        }

        RectanglePublic& operator=(const RectanglePublic& other)
        {
            if (this != &other)
                Pair::operator=(other);
            return *this;
        }

        RectanglePublic& operator++()
        {
            SetWidth(GetWidth() + 1);
            SetHeight(GetHeight() + 1);
            return *this;
        }

        RectanglePublic operator++(int)
        {
            RectanglePublic temp(*this);
            ++(*this);
            return temp;
        }

        RectanglePublic& operator--()
        {
            SetWidth(GetWidth() - 1);
            SetHeight(GetHeight() - 1);
            return *this;
        }

        RectanglePublic operator--(int)
        {
            RectanglePublic temp(*this);
            --(*this);
            return temp;
        }
    };

    TEST_CLASS(UnitTestRectangle)
    {
    public:

        TEST_METHOD(TestPairProduct)
        {
            Pair p(3, 4);
            Assert::AreEqual(12.0, p.Product(), 0.0001);
        }

        TEST_METHOD(TestPairStringConstructor)
        {
            Pair p("5,6");
            Assert::AreEqual(5.0, p.GetFirst(), 0.0001);
            Assert::AreEqual(6.0, p.GetSecond(), 0.0001);
        }

        TEST_METHOD(TestRectangleArea)
        {
            RectanglePublic r(4, 5);
            Assert::AreEqual(20.0, r.Area(), 0.0001);
        }

        TEST_METHOD(TestRectanglePerimeter)
        {
            RectanglePublic r(4, 5);
            Assert::AreEqual(18.0, r.Perimeter(), 0.0001);
        }

        TEST_METHOD(TestPrefixIncrement)
        {
            RectanglePublic r(2, 3);
            ++r;
            Assert::AreEqual(3.0, r.GetWidth(), 0.0001);
            Assert::AreEqual(4.0, r.GetHeight(), 0.0001);
        }

        TEST_METHOD(TestPostfixIncrement)
        {
            RectanglePublic r(2, 3);
            RectanglePublic old = r++;
            Assert::AreEqual(2.0, old.GetWidth(), 0.0001);
            Assert::AreEqual(3.0, old.GetHeight(), 0.0001);
            Assert::AreEqual(3.0, r.GetWidth(), 0.0001);
            Assert::AreEqual(4.0, r.GetHeight(), 0.0001);
        }

        TEST_METHOD(TestAssignment)
        {
            RectanglePublic r1(7, 8);
            RectanglePublic r2;
            r2 = r1;
            Assert::AreEqual(7.0, r2.GetWidth(), 0.0001);
            Assert::AreEqual(8.0, r2.GetHeight(), 0.0001);
        }

        TEST_METHOD(TestNegativeWidthThrows)
        {
            bool thrown = false;
            try
            {
                RectanglePublic r(-1, 5);
            }
            catch (const invalid_argument&)
            {
                thrown = true;
            }
            Assert::IsTrue(thrown);
        }

        TEST_METHOD(TestInvalidStringThrows)
        {
            bool thrown = false;
            try
            {
                RectanglePublic r("abc,10");
            }
            catch (const invalid_argument&)
            {
                thrown = true;
            }
            Assert::IsTrue(thrown);
        }
    };
}