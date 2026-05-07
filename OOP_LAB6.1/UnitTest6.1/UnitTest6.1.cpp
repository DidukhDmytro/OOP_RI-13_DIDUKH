#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Array {
    double* elems;
    size_t Count;
    size_t Size;
public:
    Array(size_t n = 10) : Count(n), Size(n) {
        elems = new double[Size];
        for (size_t i = 0; i < Size; i++) elems[i] = 0;
    }
    ~Array() { delete[] elems; }
    size_t size() const { return Count; }
    double& operator[](size_t i) {
        if (i >= Count) throw std::out_of_range("err");
        return elems[i];
    }
    void push_back(double v) {
        if (Count == Size) {
            Size *= 2;
            double* tmp = new double[Size];
            for (size_t i = 0; i < Count; i++) tmp[i] = elems[i];
            delete[] elems;
            elems = tmp;
        }
        elems[Count++] = v;
    }
};

namespace ArrayTests {
    TEST_CLASS(ArrayOperations) {
public:
    TEST_METHOD(TestSizeAndAccess) {
        Array a(5);
        a[0] = 10.5;
        Assert::AreEqual((size_t)5, a.size());
        Assert::AreEqual(10.5, a[0]);
    }
    TEST_METHOD(TestPushBackAndResize) {
        Array a(1);
        a[0] = 1.0;
        a.push_back(2.0);
        Assert::AreEqual((size_t)2, a.size());
        Assert::AreEqual(2.0, a[1]);
    }
    TEST_METHOD(TestOutOfRange) {
        Array a(2);
        Assert::ExpectException<std::out_of_range>([&] { a[5] = 0; });
    }
    };
}
