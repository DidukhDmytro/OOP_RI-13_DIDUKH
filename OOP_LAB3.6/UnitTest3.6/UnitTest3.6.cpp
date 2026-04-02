#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class B1
{
private:
    int b1;

public:
    B1(int value = 0) : b1(value)
    {
    }

    ~B1()
    {
    }

    void SetB1(int value)
    {
        b1 = value;
    }

    int GetB1() const
    {
        return b1;
    }

    void show() const
    {
    }
};

class B2
{
private:
    int b2;

public:
    B2(int value = 0) : b2(value)
    {
    }

    ~B2()
    {
    }

    void SetB2(int value)
    {
        b2 = value;
    }

    int GetB2() const
    {
        return b2;
    }

    void show() const
    {
    }
};

class D1 : public B1, private B2
{
private:
    int d1;

public:
    D1(int vb1 = 0, int vb2 = 0, int vd1 = 0) : B1(vb1), B2(vb2), d1(vd1)
    {
    }

    ~D1()
    {
    }

    void SetD1(int value)
    {
        d1 = value;
    }

    int GetD1() const
    {
        return d1;
    }

    void SetB2Value(int value)
    {
        SetB2(value);
    }

    int GetB2Value() const
    {
        return GetB2();
    }

    void show() const
    {
    }
};

class D2 : private D1
{
private:
    int d2;

public:
    D2(int vb1 = 0, int vb2 = 0, int vd1 = 0, int vd2 = 0) : D1(vb1, vb2, vd1), d2(vd2)
    {
    }

    ~D2()
    {
    }

    void SetD2(int value)
    {
        d2 = value;
    }

    int GetD2() const
    {
        return d2;
    }

    void SetB1Value(int value)
    {
        SetB1(value);
    }

    int GetB1Value() const
    {
        return GetB1();
    }

    void SetB2ValueFromD2(int value)
    {
        D1::SetB2Value(value);
    }

    int GetB2ValueFromD2() const
    {
        return D1::GetB2Value();
    }

    void SetD1Value(int value)
    {
        SetD1(value);
    }

    int GetD1Value() const
    {
        return GetD1();
    }

    void show() const
    {
    }
};

class D3 : public D2
{
private:
    int d3;

public:
    D3(int vb1 = 0, int vb2 = 0, int vd1 = 0, int vd2 = 0, int vd3 = 0)
        : D2(vb1, vb2, vd1, vd2), d3(vd3)
    {
    }

    ~D3()
    {
    }

    void SetD3(int value)
    {
        d3 = value;
    }

    int GetD3() const
    {
        return d3;
    }

    void show() const
    {
    }
};

namespace UnitTestInheritance
{
    TEST_CLASS(UnitTestInheritance)
    {
    public:

        TEST_METHOD(TestD3Initialization)
        {
            D3 obj(13, 23, 33, 43, 53);

            Assert::AreEqual(13, obj.GetB1Value());
            Assert::AreEqual(23, obj.GetB2ValueFromD2());
            Assert::AreEqual(33, obj.GetD1Value());
            Assert::AreEqual(43, obj.GetD2());
            Assert::AreEqual(53, obj.GetD3());
        }
    };
}