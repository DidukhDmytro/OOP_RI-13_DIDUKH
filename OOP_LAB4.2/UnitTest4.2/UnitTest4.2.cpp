#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class IProgression {
public:
    virtual double sum(int n) = 0;
    virtual ~IProgression() {}
};

class ArithmeticProgression : public IProgression {
    double a, d;
public:
    ArithmeticProgression(double a, double d) : a(a), d(d) {}
    double sum(int n) override {
        if (n <= 0) return 0;
        double an = a + (n - 1) * d;
        return n * (a + an) / 2.0;
    }
};

class GeometricProgression : public IProgression {
    double a, r;
public:
    GeometricProgression(double a, double r) : a(a), r(r) {}
    double sum(int n) override {
        if (n <= 0) return 0;
        if (r == 1) return a * n;
        return a * (1 - std::pow(r, n)) / (1 - r);
    }
};

namespace Lab42Tests
{
    TEST_CLASS(ProgressionTests)
    {
    public:
        TEST_METHOD(TestArithmeticSum)
        {
            IProgression* prog = new ArithmeticProgression(1.0, 2.0);
            double expected = 9.0;
            double actual = prog->sum(3);

            Assert::AreEqual(expected, actual, L"Арифметична сума розрахована невірно");

            delete prog;
        }

        TEST_METHOD(TestGeometricSum)
        {
            IProgression* prog = new GeometricProgression(2.0, 3.0);
            double expected = 26.0;
            double actual = prog->sum(3);

            Assert::AreEqual(expected, actual, L"Геометрична сума розрахована невірно");

            delete prog;
        }

        TEST_METHOD(TestZeroElements)
        {
            ArithmeticProgression ap(10, 5);
            Assert::AreEqual(0.0, ap.sum(0), L"Сума 0 елементів має бути 0");
        }
        TEST_METHOD(TestPolymorphicType)
        {
            IProgression* prog = new GeometricProgression(1, 2);
            bool isGeometric = (dynamic_cast<GeometricProgression*>(prog) != nullptr);

            Assert::IsTrue(isGeometric, L"Об'єкт не розпізнано як GeometricProgression");

            delete prog;
        }
    };
}