#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;
public:
    Array(int n, unsigned char val = 0) {
        size = (n > MAX_SIZE) ? MAX_SIZE : n;
        for (int i = 0; i < size; ++i) data[i] = val;
    }
    virtual ~Array() {}
    unsigned char& operator[](int i) { return data[i]; }
    int getSize() const { return size; }
    virtual Array* add(const Array& other) = 0;
};

class Money : public Array {
public:
    Money(int n, unsigned char val = 0) : Array(n, val % 10) {}
    Array* add(const Array& other) override {
        int maxSize = std::max(size, other.getSize());
        Money* res = new Money(maxSize);
        int carry = 0;
        for (int i = 0; i < maxSize; ++i) {
            int d1 = (i < size) ? data[i] : 0;
            int d2 = (i < other.getSize()) ? const_cast<Array&>(other)[i] : 0;
            int sum = d1 + d2 + carry;
            (*res)[i] = sum % 10;
            carry = sum / 10;
        }
        return res;
    }
    std::wstring toWString() const {
        std::wstring s = L"";
        for (int i = size - 1; i >= 0; --i) {
            if (i == 1 && size > 2) s += L",";
            s += std::to_wstring((int)data[i]);
        }
        return s;
    }
};

class BitString : public Array {
public:
    BitString(int n, unsigned char val = 0) : Array(n, val % 2) {}
    Array* add(const Array& other) override {
        int maxSize = std::max(size, other.getSize());
        BitString* res = new BitString(maxSize);
        for (int i = 0; i < maxSize; ++i) {
            unsigned char b1 = (i < size) ? data[i] : 0;
            unsigned char b2 = (i < other.getSize()) ? const_cast<Array&>(other)[i] : 0;
            (*res)[i] = b1 ^ b2;
        }
        return res;
    }
    std::wstring toWString() const {
        std::wstring s = L"";
        for (int i = size - 1; i >= 0; --i) s += std::to_wstring((int)data[i]);
        return s;
    }
};

namespace LabTests {
    TEST_CLASS(LongArithmeticTests) {
public:
    TEST_METHOD(TestMoneyAdditionWithCarry) {
        Money m1(3); m1[0] = 9; m1[1] = 9; m1[2] = 0; // 0,99
        Money m2(3); m2[0] = 1; m2[1] = 0; m2[2] = 0; // 0,01
        Array* res = m1.add(m2);
        Assert::AreEqual(L"1,00", static_cast<Money*>(res)->toWString().c_str());
        delete res;
    }

    TEST_METHOD(TestBitStringXor) {
        BitString b1(3); b1[0] = 1; b1[1] = 0; b1[2] = 1; // 101
        BitString b2(3); b2[0] = 1; b2[1] = 1; b2[2] = 0; // 011
        Array* res = b1.add(b2);
        Assert::AreEqual(L"110", static_cast<BitString*>(res)->toWString().c_str());
        delete res;
    }
    };
}