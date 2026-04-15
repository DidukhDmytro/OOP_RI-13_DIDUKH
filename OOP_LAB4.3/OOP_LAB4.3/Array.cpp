#include "Array.h"

Array::Array(int n, unsigned char val) {
    size = (n > MAX_SIZE) ? MAX_SIZE : n;
    for (int i = 0; i < size; ++i) {
        data[i] = val;
    }
}

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds!");
    }
}

unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    rangeCheck(index);
    return data[index];
}