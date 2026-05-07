#pragma once
#include <iostream>

template <class T>
class Array
{
private:
    T* data;
    int left;
    int right;
    int count;
    int iteratorIndex;

    void rangeCheck(int index) const;

public:
    Array(int l = 0, int r = 0, T value = T());
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);

    int Size() const;
    int Left() const;
    int Right() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    int Find(const T& value) const;

    Array operator+(int number) const;
    Array operator-(int number) const;
    Array operator*(int number) const;
    Array operator/(int number) const;

    void Begin();
    void End();
    void Next();
    void Prev();
    bool IsEnd() const;

    T& Current();
    const T& Current() const;

    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const Array<U>& a);

    template <class U>
    friend std::istream& operator>>(std::istream& in, Array<U>& a);

    friend std::ostream& PrintInside(std::ostream& out, const Array<T>& a)
    {
        for (int i = a.left; i <= a.right; i++)
            out << "a[" << i << "] = " << a[i] << " ";

        return out;
    }

    friend std::istream& ReadInside(std::istream& in, Array<T>& a)
    {
        for (int i = a.left; i <= a.right; i++)
        {
            std::cout << "a[" << i << "] = ";
            in >> a[i];
        }

        return in;
    }
};