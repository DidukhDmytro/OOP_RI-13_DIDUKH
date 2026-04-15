#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Progression {
public:
    virtual ~Progression() {}
    virtual double sum(int n) = 0;
    virtual std::wstring showType() = 0;
};

class ArithmeticProgression : public Progression {
    double a, d;
public:
    ArithmeticProgression(double start, double step) : a(start), d(step) {}

    double sum(int n) override {
        if (n <= 0) return 0;
        return (n / 2.0) * (2 * a + (n - 1) * d);
    }

    std::wstring showType() override { return L"Arithmetic"; }
};

class GeometricProgression : public Progression {
    double b, q;
public:
    GeometricProgression(double start, double ratio) : b(start), q(ratio) {}

    double sum(int n) override {
        if (n <= 0) return 0;
        if (q == 1) return b * n;
        return b * (std::pow(q, n) - 1) / (q - 1);
    }

    std::wstring showType() override { return L"Geometric"; }
};

// --- Тести ---

namespace ProgressionTests
{
    TEST_CLASS(ProgressionLogicTests)
    {
    public:

        TEST_METHOD(TestArithmeticLogic)
        {
            ArithmeticProgression ap(5, 5);
            Assert::AreEqual(30.0, ap.sum(3));
            Assert::AreEqual(L"Arithmetic", ap.showType().c_str());
        }

        TEST_METHOD(TestGeometricLogic)
        {
            GeometricProgression gp(2, 2);
            Assert::AreEqual(14.0, gp.sum(3));
            Assert::AreEqual(L"Geometric", gp.showType().c_str());
        }

        TEST_METHOD(TestPolymorphism)
        {
            Progression* p = new ArithmeticProgression(1, 1);
            Assert::IsNotNull(p);
            Assert::AreEqual(L"Arithmetic", p->showType().c_str());
            delete p;
        }
    };
}