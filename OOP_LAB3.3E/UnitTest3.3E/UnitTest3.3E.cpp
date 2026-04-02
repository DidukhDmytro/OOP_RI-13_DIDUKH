#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Object
{
private:
    static int count;

public:
    Object()
    {
        count++;
    }

    Object(const Object&)
    {
        count++;
    }

    virtual ~Object()
    {
        count--;
    }

    static int GetCount()
    {
        return count;
    }
};

int Object::count = 0;

class Pair : public Object
{
private:
    double first;
    double second;

public:
    Pair() : first(0), second(0)
    {
    }

    Pair(double first, double second) : first(first), second(second)
    {
    }

    Pair(const Pair& other) : Object(other), first(other.first), second(other.second)
    {
    }

    double GetFirst() const
    {
        return first;
    }

    double GetSecond() const
    {
        return second;
    }

    void SetFirst(double value)
    {
        first = value;
    }

    void SetSecond(double value)
    {
        second = value;
    }

    double Product() const
    {
        return first * second;
    }
};

class Rectangle : public Pair
{
public:
    Rectangle() : Pair()
    {
    }

    Rectangle(double width, double height) : Pair(width, height)
    {
    }

    Rectangle(const Rectangle& other) : Pair(other)
    {
    }

    double GetWidth() const
    {
        return GetFirst();
    }

    double GetHeight() const
    {
        return GetSecond();
    }

    double Perimeter() const
    {
        return 2 * (GetWidth() + GetHeight());
    }

    double Area() const
    {
        return GetWidth() * GetHeight();
    }
};

namespace UnitTest3E
{
    TEST_CLASS(UnitTest3E)
    {
    public:

        TEST_METHOD(TestRectangleArea)
        {
            Rectangle r(5, 7);
            double area = r.Area();

            Assert::AreEqual(35.0, area, 0.0001);
        }
    };
}