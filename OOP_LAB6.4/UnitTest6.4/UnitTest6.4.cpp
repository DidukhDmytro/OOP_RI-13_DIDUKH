#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestTemplateArray
{
    template <class T>
    class Array
    {
    private:
        T* data;
        int size;

    public:
        Array() : data(nullptr), size(0) {}

        Array(int size)
        {
            if (size < 0)
                throw invalid_argument("Size cannot be negative");

            this->size = size;
            data = new T[size];

            for (int i = 0; i < size; i++)
                data[i] = T();
        }

        Array(const Array<T>& other)
        {
            size = other.size;
            data = new T[size];

            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }

        ~Array()
        {
            delete[] data;
        }

        int GetSize() const
        {
            return size;
        }

        Array<T>& operator=(const Array<T>& other)
        {
            if (this != &other)
            {
                delete[] data;
                size = other.size;
                data = new T[size];

                for (int i = 0; i < size; i++)
                    data[i] = other.data[i];
            }
            return *this;
        }

        T& operator[](int index)
        {
            if (index < 0 || index >= size)
                throw out_of_range("Index out of range");
            return data[index];
        }

        const T& operator[](int index) const
        {
            if (index < 0 || index >= size)
                throw out_of_range("Index out of range");
            return data[index];
        }
    };

    TEST_CLASS(UnitTestTemplateArray)
    {
    public:

        TEST_METHOD(TestConstructorAndSize)
        {
            Array<int> a(5);
            Assert::AreEqual(5, a.GetSize());
        }

        TEST_METHOD(TestDefaultValues)
        {
            Array<int> a(3);
            Assert::AreEqual(0, a[0]);
            Assert::AreEqual(0, a[1]);
            Assert::AreEqual(0, a[2]);
        }

        TEST_METHOD(TestIndexWriteRead)
        {
            Array<int> a(3);
            a[0] = 10;
            a[1] = 20;
            a[2] = 30;

            Assert::AreEqual(10, a[0]);
            Assert::AreEqual(20, a[1]);
            Assert::AreEqual(30, a[2]);
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Array<int> a(2);
            a[0] = 7;
            a[1] = 9;

            Array<int> b(a);

            Assert::AreEqual(7, b[0]);
            Assert::AreEqual(9, b[1]);
        }

        TEST_METHOD(TestAssignmentOperator)
        {
            Array<int> a(2);
            a[0] = 11;
            a[1] = 22;

            Array<int> b(2);
            b = a;

            Assert::AreEqual(11, b[0]);
            Assert::AreEqual(22, b[1]);
        }

        TEST_METHOD(TestOutOfRangeThrows)
        {
            Array<int> a(2);
            bool thrown = false;

            try
            {
                int x = a[5];
            }
            catch (const out_of_range&)
            {
                thrown = true;
            }

            Assert::IsTrue(thrown);
        }

        TEST_METHOD(TestNegativeSizeThrows)
        {
            bool thrown = false;

            try
            {
                Array<int> a(-1);
            }
            catch (const invalid_argument&)
            {
                thrown = true;
            }

            Assert::IsTrue(thrown);
        }

        TEST_METHOD(TestInstantiationDouble)
        {
            Array<double> a(2);
            a[0] = 1.5;
            a[1] = 2.5;

            Assert::AreEqual(1.5, a[0], 0.0001);
            Assert::AreEqual(2.5, a[1], 0.0001);
        }
    };
}