#pragma once
#include <iostream>
#include <stdexcept>

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

public:
    Array(int n, unsigned char val = 0);
    virtual ~Array() {}

    void rangeCheck(int index) const;
    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    int getSize() const { return size; }

    virtual Array* add(const Array& other) = 0;
};