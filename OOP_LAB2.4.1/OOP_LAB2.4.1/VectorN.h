#pragma once
#include <iostream>
#include <string>

class VectorN {
private:
    int n;
    int* data;

    void allocate(int size);
    void freeMemory();
    void copyFrom(const VectorN& other);

public:
    VectorN();
    VectorN(int size);
    VectorN(int size, int value);
    VectorN(const VectorN& other);

    ~VectorN();

    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);

    VectorN& operator=(const VectorN& other);

    int& operator[](int index);
    const int& operator[](int index) const;

    double operator~() const; // норма вектора

    bool operator==(const VectorN& other) const;
    bool operator!=(const VectorN& other) const;
    bool operator<(const VectorN& other) const;
    bool operator>(const VectorN& other) const;

    operator std::string() const;

    friend std::istream& operator>>(std::istream& in, VectorN& v);
    friend std::ostream& operator<<(std::ostream& out, const VectorN& v);
    friend int operator*(const VectorN& left, const VectorN& right);
};