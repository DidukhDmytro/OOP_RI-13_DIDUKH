#include "BitString.h"
#include <iostream>
#include <algorithm>

BitString::BitString(int n, unsigned char val) : Array(n, val % 2) {}

Array* BitString::add(const Array& other) {
    int maxSize = std::max(this->size, other.getSize());
    BitString* result = new BitString(maxSize);

    for (int i = 0; i < maxSize; ++i) {
        unsigned char b1 = (i < this->size) ? this->data[i] : 0;
        unsigned char b2 = (i < other.getSize()) ? other[i] : 0;
        (*result)[i] = b1 ^ b2;
    }
    return result;
}

void BitString::op_and(const BitString& other) {
    int minSize = std::min(this->size, other.size);
    for (int i = 0; i < minSize; ++i) data[i] &= other.data[i];
}

void BitString::op_or(const BitString& other) {
    int minSize = std::min(this->size, other.size);
    for (int i = 0; i < minSize; ++i) data[i] |= other.data[i];
}

void BitString::op_xor(const BitString& other) {
    int minSize = std::min(this->size, other.size);
    for (int i = 0; i < minSize; ++i) data[i] ^= other.data[i];
}

void BitString::op_not() {
    for (int i = 0; i < size; ++i) {
        data[i] = (data[i] == 0) ? 1 : 0;
    }
}

void BitString::shiftLeft(int shift) {
    if (shift <= 0) return;
    if (shift >= size) {
        for (int i = 0; i < size; ++i) data[i] = 0;
        return;
    }
    for (int i = size - 1; i >= shift; --i) data[i] = data[i - shift];
    for (int i = 0; i < shift; ++i) data[i] = 0;
}

void BitString::shiftRight(int shift) {
    if (shift <= 0) return;
    if (shift >= size) {
        for (int i = 0; i < size; ++i) data[i] = 0;
        return;
    }
    for (int i = 0; i < size - shift; ++i) data[i] = data[i + shift];
    for (int i = size - shift; i < size; ++i) data[i] = 0;
}

void BitString::print() const {
    for (int i = size - 1; i >= 0; --i) std::cout << (int)data[i];
    std::cout << " (bin)";
}