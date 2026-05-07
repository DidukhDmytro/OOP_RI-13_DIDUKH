#include "Array.h"
#include <stdexcept>

template <class T>
void Array<T>::rangeCheck(int index) const
{
    if (index < left || index > right)
        throw std::out_of_range("Index out of range");
}

template <class T>
Array<T>::Array(int l, int r, T value)
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

template <class T>
Array<T>::Array(const Array& other)
{
    left = other.left;
    right = other.right;
    count = other.count;
    iteratorIndex = other.iteratorIndex;

    data = new T[count];

    for (int i = 0; i < count; i++)
        data[i] = other.data[i];
}

template <class T>
Array<T>::~Array()
{
    delete[] data;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other)
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

template <class T>
int Array<T>::Size() const
{
    return count;
}

template <class T>
int Array<T>::Left() const
{
    return left;
}

template <class T>
int Array<T>::Right() const
{
    return right;
}

template <class T>
T& Array<T>::operator[](int index)
{
    rangeCheck(index);
    return data[index - left];
}

template <class T>
const T& Array<T>::operator[](int index) const
{
    rangeCheck(index);
    return data[index - left];
}

template <class T>
int Array<T>::Find(const T& value) const
{
    for (int i = 0; i < count; i++)
    {
        if (data[i] == value)
            return left + i;
    }

    return -1;
}

template <class T>
Array<T> Array<T>::operator+(int number) const
{
    Array result(*this);

    for (int i = 0; i < count; i++)
        result.data[i] += number;

    return result;
}

template <class T>
Array<T> Array<T>::operator-(int number) const
{
    Array result(*this);

    for (int i = 0; i < count; i++)
        result.data[i] -= number;

    return result;
}

template <class T>
Array<T> Array<T>::operator*(int number) const
{
    Array result(*this);

    for (int i = 0; i < count; i++)
        result.data[i] *= number;

    return result;
}

template <class T>
Array<T> Array<T>::operator/(int number) const
{
    if (number == 0)
        throw std::invalid_argument("Division by zero");

    Array result(*this);

    for (int i = 0; i < count; i++)
        result.data[i] /= number;

    return result;
}

template <class T>
void Array<T>::Begin()
{
    iteratorIndex = 0;
}

template <class T>
void Array<T>::End()
{
    iteratorIndex = count - 1;
}

template <class T>
void Array<T>::Next()
{
    iteratorIndex++;
}

template <class T>
void Array<T>::Prev()
{
    iteratorIndex--;
}

template <class T>
bool Array<T>::IsEnd() const
{
    return iteratorIndex >= count;
}

template <class T>
T& Array<T>::Current()
{
    if (IsEnd())
        throw std::out_of_range("Iterator is out of range");

    return data[iteratorIndex];
}

template <class T>
const T& Array<T>::Current() const
{
    if (IsEnd())
        throw std::out_of_range("Iterator is out of range");

    return data[iteratorIndex];
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Array<T>& a)
{
    for (int i = a.left; i <= a.right; i++)
        out << "a[" << i << "] = " << a[i] << " ";

    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, Array<T>& a)
{
    for (int i = a.left; i <= a.right; i++)
    {
        std::cout << "a[" << i << "] = ";
        in >> a[i];
    }

    return in;
}

template class Array<int>;
template class Array<double>;

template std::ostream& operator<< <int>(std::ostream& out, const Array<int>& a);
template std::ostream& operator<< <double>(std::ostream& out, const Array<double>& a);

template std::istream& operator>> <int>(std::istream& in, Array<int>& a);
template std::istream& operator>> <double>(std::istream& in, Array<double>& a);