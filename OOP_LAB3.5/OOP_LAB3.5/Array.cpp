#include "Array.h"

void Array::rangeCheck(int index) const
{
    if (index < 0 || index >= size)
    {
        std::cerr << "Index out of range" << std::endl;
        std::exit(1);
    }
}

Array::Array() : size(MAX_SIZE)
{
    for (int i = 0; i < MAX_SIZE; i++)
        data[i] = 0;
}

Array::Array(int size, unsigned char value) : size(size)
{
    if (size <= 0 || size > MAX_SIZE)
    {
        std::cerr << "Invalid array size" << std::endl;
        std::exit(1);
    }

    for (int i = 0; i < size; i++)
        data[i] = value;
    for (int i = size; i < MAX_SIZE; i++)
        data[i] = 0;
}

Array::Array(const Array& other) : size(other.size)
{
    for (int i = 0; i < MAX_SIZE; i++)
        data[i] = other.data[i];
}

int Array::GetSize() const
{
    return size;
}

unsigned char Array::GetAt(int index) const
{
    rangeCheck(index);
    return data[index];
}

void Array::SetAt(int index, unsigned char value)
{
    rangeCheck(index);
    data[index] = value;
}

unsigned char& Array::operator[](int index)
{
    rangeCheck(index);
    return data[index];
}

const unsigned char& Array::operator[](int index) const
{
    rangeCheck(index);
    return data[index];
}

void Array::Read()
{
    for (int i = 0; i < size; i++)
        std::cin >> data[i];
}

void Array::Display() const
{
    std::cout << toString() << std::endl;
}

std::string Array::toString() const
{
    std::string s;
    for (int i = 0; i < size; i++)
        s += std::to_string((int)data[i]) + " ";
    return s;
}

Array& Array::operator=(const Array& other)
{
    if (this != &other)
    {
        size = other.size;
        for (int i = 0; i < MAX_SIZE; i++)
            data[i] = other.data[i];
    }
    return *this;
}

Array::operator std::string() const
{
    return toString();
}

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
    out << arr.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Array& arr)
{
    for (int i = 0; i < arr.size; i++)
        in >> arr.data[i];
    return in;
}