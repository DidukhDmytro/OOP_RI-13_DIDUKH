#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template <class T>
class Array
{
private:
    T* data;
    int left;
    int right;
    int count;
    int iteratorIndex;

    void rangeCheck(int index) const
    {
        if (index < left || index > right)
            throw std::out_of_range("Index out of range");
    }

public:
    Array(int l = 0, int r = 0, T value = T())
    {
        if (l > r)
            throw std::invalid_argument("Left border cannot be greater than right border");

        left = l;
        right = r;
        count = right - left + 1;
        iteratorIndex = 0;

        data = new T[count];

        for (int i = 0; i < count; i++)
            data[i] = value;
    }

    Array(const Array& other)
    {
        left = other.left;
        right = other.right;
        count = other.count;
        iteratorIndex = other.iteratorIndex;

        data = new T[count];

        for (int i = 0; i < count; i++)
            data[i] = other.data[i];
    }

    ~Array()
    {
        delete[] data;
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] data;

            left = other.left;
            right = other.right;
            count = other.count;
            iteratorIndex = other.iteratorIndex;

            data = new T[count];

            for (int i = 0; i < count; i++)
                data[i] = other.data[i];
        }

        return *this;
    }

    int Size() const
    {
        return count;
    }

    int Left() const
    {
        return left;
    }

    int Right() const
    {
        return right;
    }

    T& operator[](int index)
    {
        rangeCheck(index);
        return data[index - left];
    }

    const T& operator[](int index) const
    {
        rangeCheck(index);
        return data[index - left];
    }

    int Find(const T& value) const
    {
        for (int i = 0; i < count; i++)
        {
            if (data[i] == value)
                return left + i;
        }

        return -1;
    }

    Array operator+(int number) const
    {
        Array result(*this);

        for (int i = 0; i < count; i++)
            result.data[i] += number;

        return result;
    }

    Array operator-(int number) const
    {
        Array result(*this);

        for (int i = 0; i < count; i++)
            result.data[i] -= number;

        return result;
    }

    Array operator*(int number) const
    {
        Array result(*this);

        for (int i = 0; i < count; i++)
            result.data[i] *= number;

        return result;
    }

    Array operator/(int number) const
    {
        if (number == 0)
            throw std::invalid_argument("Division by zero");

        Array result(*this);

        for (int i = 0; i < count; i++)
            result.data[i] /= number;

        return result;
    }

    void Begin()
    {
        iteratorIndex = 0;
    }

    void Next()
    {
        iteratorIndex++;
    }

    bool IsEnd() const
    {
        return iteratorIndex >= count;
    }

    T& Current()
    {
        if (IsEnd())
            throw std::out_of_range("Iterator is out of range");

        return data[iteratorIndex];
    }
};

namespace UnitTestArray
{
    TEST_CLASS(ArrayTests)
    {
    public:

        TEST_METHOD(ConstructorCreatesCorrectArray)
        {
            Array<int> a(-2, 2, 5);

            Assert::AreEqual(5, a.Size());
            Assert::AreEqual(-2, a.Left());
            Assert::AreEqual(2, a.Right());
            Assert::AreEqual(5, a[-2]);
            Assert::AreEqual(5, a[2]);
        }

        TEST_METHOD(IndexOperatorWorksWithNegativeIndexes)
        {
            Array<int> a(-3, 1, 0);

            a[-3] = 10;
            a[-2] = 20;
            a[-1] = 30;
            a[0] = 40;
            a[1] = 50;

            Assert::AreEqual(10, a[-3]);
            Assert::AreEqual(30, a[-1]);
            Assert::AreEqual(50, a[1]);
        }

        TEST_METHOD(IndexOutOfRangeThrowsException)
        {
            Array<int> a(-2, 2, 0);

            Assert::ExpectException<std::out_of_range>([&]()
                {
                    a[5] = 10;
                });
        }

        TEST_METHOD(FindReturnsCorrectIndex)
        {
            Array<int> a(-2, 2, 0);

            a[-2] = 10;
            a[-1] = 20;
            a[0] = 30;

            Assert::AreEqual(-1, a.Find(20));
            Assert::AreEqual(0, a.Find(30));
            Assert::AreEqual(-1, a.Find(100));
        }

        TEST_METHOD(ArithmeticOperationsWork)
        {
            Array<int> a(0, 2, 10);

            Array<int> b = a + 5;
            Array<int> c = a - 5;
            Array<int> d = a * 2;
            Array<int> e = a / 2;

            Assert::AreEqual(15, b[0]);
            Assert::AreEqual(5, c[0]);
            Assert::AreEqual(20, d[0]);
            Assert::AreEqual(5, e[0]);
        }

        TEST_METHOD(DivisionByZeroThrowsException)
        {
            Array<int> a(0, 2, 10);

            Assert::ExpectException<std::invalid_argument>([&]()
                {
                    Array<int> b = a / 0;
                });
        }

        TEST_METHOD(CopyConstructorWorks)
        {
            Array<int> a(-1, 1, 7);
            Array<int> b(a);

            Assert::AreEqual(3, b.Size());
            Assert::AreEqual(7, b[-1]);
            Assert::AreEqual(7, b[1]);
        }

        TEST_METHOD(AssignmentOperatorWorks)
        {
            Array<int> a(0, 2, 4);
            Array<int> b(-2, -1, 9);

            b = a;

            Assert::AreEqual(3, b.Size());
            Assert::AreEqual(0, b.Left());
            Assert::AreEqual(2, b.Right());
            Assert::AreEqual(4, b[0]);
        }

        TEST_METHOD(IteratorWorks)
        {
            Array<int> a(0, 2, 0);

            a[0] = 1;
            a[1] = 2;
            a[2] = 3;

            int sum = 0;

            for (a.Begin(); !a.IsEnd(); a.Next())
                sum += a.Current();

            Assert::AreEqual(6, sum);
        }
    };
}