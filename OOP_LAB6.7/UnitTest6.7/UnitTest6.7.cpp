#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<class T>
class Predicate
{
public:
    virtual bool operator()(T x) = 0;
};

template<class T>
class Zero : public Predicate<T>
{
public:
    bool operator()(T x) override
    {
        T zero = T();
        return x == zero;
    }
};

template<class T>
class Positive : public Predicate<T>
{
public:
    bool operator()(T x) override
    {
        return x > 0;
    }
};

template<class T>
class Negative : public Predicate<T>
{
public:
    bool operator()(T x) override
    {
        return x < 0;
    }
};

template<class T>
int erase(T* begin, T* end, T* to, T value)
{
    int n = 0;

    for (T* from = begin; from < end; from++)
    {
        if (*from != value)
        {
            *to = *from;
            to++;
            n++;
        }
    }

    return n;
}

template<class T>
int erase_if(T* begin, T* end, T* to, Predicate<T>& p)
{
    int n = 0;

    for (T* from = begin; from < end; from++)
    {
        if (!p(*from))
        {
            *to = *from;
            to++;
            n++;
        }
    }

    return n;
}

namespace UnitTestEraseAlgorithms
{
    TEST_CLASS(EraseTests)
    {
    public:

        TEST_METHOD(EraseRemovesGivenValue)
        {
            double a[8] = { 1, -2, 0, 4, -5, 0, 7, -3 };
            double result[20];

            int n = erase(a, a + 8, result, 0.0);

            Assert::AreEqual(6, n);
            Assert::AreEqual(1.0, result[0]);
            Assert::AreEqual(-2.0, result[1]);
            Assert::AreEqual(4.0, result[2]);
            Assert::AreEqual(-5.0, result[3]);
            Assert::AreEqual(7.0, result[4]);
            Assert::AreEqual(-3.0, result[5]);
        }

        TEST_METHOD(EraseIfRemovesNegativeElements)
        {
            double a[8] = { 1, -2, 0, 4, -5, 0, 7, -3 };
            double result[20];

            Negative<double> negative;

            int n = erase_if(a, a + 8, result, negative);

            Assert::AreEqual(5, n);
            Assert::AreEqual(1.0, result[0]);
            Assert::AreEqual(0.0, result[1]);
            Assert::AreEqual(4.0, result[2]);
            Assert::AreEqual(0.0, result[3]);
            Assert::AreEqual(7.0, result[4]);
        }

        TEST_METHOD(EraseIfRemovesPositiveElements)
        {
            double a[8] = { 1, -2, 0, 4, -5, 0, 7, -3 };
            double result[20];

            Positive<double> positive;

            int n = erase_if(a, a + 8, result, positive);

            Assert::AreEqual(5, n);
            Assert::AreEqual(-2.0, result[0]);
            Assert::AreEqual(0.0, result[1]);
            Assert::AreEqual(-5.0, result[2]);
            Assert::AreEqual(0.0, result[3]);
            Assert::AreEqual(-3.0, result[4]);
        }

        TEST_METHOD(EraseIfRemovesZeroElements)
        {
            double a[8] = { 1, -2, 0, 4, -5, 0, 7, -3 };
            double result[20];

            Zero<double> zero;

            int n = erase_if(a, a + 8, result, zero);

            Assert::AreEqual(6, n);
            Assert::AreEqual(1.0, result[0]);
            Assert::AreEqual(-2.0, result[1]);
            Assert::AreEqual(4.0, result[2]);
            Assert::AreEqual(-5.0, result[3]);
            Assert::AreEqual(7.0, result[4]);
            Assert::AreEqual(-3.0, result[5]);
        }

        TEST_METHOD(EraseKeepsAllElementsIfValueNotFound)
        {
            double a[5] = { 1, 2, 3, 4, 5 };
            double result[10];

            int n = erase(a, a + 5, result, 100.0);

            Assert::AreEqual(5, n);
            Assert::AreEqual(1.0, result[0]);
            Assert::AreEqual(2.0, result[1]);
            Assert::AreEqual(3.0, result[2]);
            Assert::AreEqual(4.0, result[3]);
            Assert::AreEqual(5.0, result[4]);
        }

        TEST_METHOD(EraseRemovesAllElements)
        {
            double a[5] = { 2, 2, 2, 2, 2 };
            double result[10];

            int n = erase(a, a + 5, result, 2.0);

            Assert::AreEqual(0, n);
        }
    };
}