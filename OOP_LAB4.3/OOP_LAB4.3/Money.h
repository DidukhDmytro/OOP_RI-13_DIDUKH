#pragma once
#include "Array.h"

class Money : public Array {
public:
    Money(int n, unsigned char val = 0);
    Array* add(const Array& other) override;
    void print() const;
};