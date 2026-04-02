#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class Array
{
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

    void rangeCheck(int index) const;

public:
    Array();
    Array(int size, unsigned char value = 0);
    Array(const Array& other);

    int GetSize() const;
    unsigned char GetAt(int index) const;
    void SetAt(int index, unsigned char value);

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    void Read();
    void Display() const;
    std::string toString() const;

    Array& operator=(const Array& other);
    operator std::string() const;

    friend std::ostream& operator<<(std::ostream& out, const Array& arr);
    friend std::istream& operator>>(std::istream& in, Array& arr);
};