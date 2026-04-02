#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Array
{
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

    void rangeCheck(int index) const
    {
        if (index < 0 || index >= size)
            exit(1);
    }

public:
    Array() : size(MAX_SIZE)
    {
        for (int i = 0; i < MAX_SIZE; i++)
            data[i] = 0;
    }

    Array(int size, unsigned char value = 0) : size(size)
    {
        if (size <= 0 || size > MAX_SIZE)
            exit(1);

        for (int i = 0; i < size; i++)
            data[i] = value;

        for (int i = size; i < MAX_SIZE; i++)
            data[i] = 0;
    }

    Array(const Array& other) : size(other.size)
    {
        for (int i = 0; i < MAX_SIZE; i++)
            data[i] = other.data[i];
    }

    unsigned char& operator[](int index)
    {
        rangeCheck(index);
        return data[index];
    }

    const unsigned char& operator[](int index) const
    {
        rangeCheck(index);
        return data[index];
    }
};

class Decimal : public Array
{
private:
    void normalize()
    {
        while (size > 1 && data[size - 1] == 0)
            size--;
    }

public:
    Decimal() : Array(1, 0)
    {
    }

    Decimal(const std::string& number) : Array((int)number.length(), 0)
    {
        Init(number);
    }

    void Init(const std::string& number)
    {
        size = (int)number.length();

        for (int i = 0; i < size; i++)
            data[i] = number[size - 1 - i] - '0';

        for (int i = size; i < MAX_SIZE; i++)
            data[i] = 0;

        normalize();
    }

    std::string toString() const
    {
        std::string s;
        for (int i = size - 1; i >= 0; i--)
            s += char('0' + data[i]);
        return s;
    }

    Decimal operator+(const Decimal& other) const
    {
        Decimal result;
        result.size = (size > other.size ? size : other.size) + 1;

        int carry = 0;
        for (int i = 0; i < result.size; i++)
        {
            int a = (i < size) ? data[i] : 0;
            int b = (i < other.size) ? other.data[i] : 0;
            int sum = a + b + carry;
            result.data[i] = sum % 10;
            carry = sum / 10;
        }

        result.normalize();
        return result;
    }
};

namespace UnitTestDecimal
{
    TEST_CLASS(UnitTestDecimal)
    {
    public:

        TEST_METHOD(TestDecimalAddition)
        {
            Decimal a("123");
            Decimal b("77");
            Decimal c = a + b;

            Assert::AreEqual(std::string("200"), c.toString());
        }
    };
}