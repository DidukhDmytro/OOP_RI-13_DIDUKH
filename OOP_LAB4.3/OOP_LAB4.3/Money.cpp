#include "Money.h"
#include <iostream>
#include <algorithm>

Money::Money(int n, unsigned char val) : Array(n, val % 10) {}

Array* Money::add(const Array& other) {
    int maxSize = std::max(this->size, other.getSize());
    Money* result = new Money(maxSize);

    int carry = 0;
    for (int i = 0; i < maxSize; ++i) {
        int d1 = (i < this->size) ? this->data[i] : 0;
        int d2 = (i < other.getSize()) ? other[i] : 0;

        int sum = d1 + d2 + carry;
        (*result)[i] = (unsigned char)(sum % 10);
        carry = sum / 10;
    }
    return result;
}

void Money::print() const {
    for (int i = size - 1; i >= 0; --i) {
        std::cout << (int)data[i];
        if (i == 2 && size > 2) {
            std::cout << ",";
        }
    }
    std::cout << " UAH";
}