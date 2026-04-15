#pragma once
#include "Array.h"

class BitString : public Array {
public:
    BitString(int n, unsigned char val = 0);
    Array* add(const Array& other) override;

    void op_and(const BitString& other);
    void op_or(const BitString& other);
    void op_xor(const BitString& other);
    void op_not();

    void shiftLeft(int shift);
    void shiftRight(int shift);

    void print() const;
};