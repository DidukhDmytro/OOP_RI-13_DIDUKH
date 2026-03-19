#include "VectorN.h"
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

void VectorN::allocate(int size) {
    if (size < 0)
        throw invalid_argument("Size cannot be negative");

    n = size;
    if (n == 0)
        data = nullptr;
    else
        data = new int[n] {};
}

void VectorN::freeMemory() {
    delete[] data;
    data = nullptr;
    n = 0;
}

void VectorN::copyFrom(const VectorN& other) {
    allocate(other.n);
    for (int i = 0; i < n; i++) {
        data[i] = other.data[i];
    }
}

VectorN::VectorN() : n(0), data(nullptr) {}

VectorN::VectorN(int size) : n(0), data(nullptr) {
    allocate(size);
}

VectorN::VectorN(int size, int value) : n(0), data(nullptr) {
    allocate(size);
    for (int i = 0; i < n; i++)
        data[i] = value;
}

VectorN::VectorN(const VectorN& other) : n(0), data(nullptr) {
    copyFrom(other);
}

VectorN::~VectorN() {
    freeMemory();
}

int VectorN::getSize() const {
    return n;
}

int VectorN::getElement(int index) const {
    if (index < 0 || index >= n)
        throw out_of_range("Index out of range");

    return data[index];
}

void VectorN::setElement(int index, int value) {
    if (index < 0 || index >= n)
        throw out_of_range("Index out of range");

    data[index] = value;
}

VectorN& VectorN::operator=(const VectorN& other) {
    if (this != &other)
    {
        freeMemory();
        copyFrom(other);
    }
    return *this;
}

int& VectorN::operator[](int index) {
    if (index < 0 || index >= n)
        throw out_of_range("Index out of range");

    return data[index];
}

const int& VectorN::operator[](int index) const {
    if (index < 0 || index >= n)
        throw out_of_range("Index out of range");

    return data[index];
}

double VectorN::operator~() const {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += data[i] * data[i];

    return sqrt(sum);
}

bool VectorN::operator==(const VectorN& other) const {
    if (n != other.n)
        return false;

    for (int i = 0; i < n; i++) {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}

bool VectorN::operator!=(const VectorN& other) const {
    return !(*this == other);
}

bool VectorN::operator<(const VectorN& other) const {
    return ~(*this) < ~other;
}

bool VectorN::operator>(const VectorN& other) const {
    return ~(*this) > ~other;
}

VectorN::operator std::string() const {
    stringstream sout;
    sout << "[";
    for (int i = 0; i < n; i++) {
        sout << data[i];
        if (i != n - 1)
            sout << ", ";
    }
    sout << "]";
    return sout.str();
}

istream& operator>>(istream& in, VectorN& v) {
    cout << "Enter size: ";
    int size;
    in >> size;

    if (size < 0)
        throw invalid_argument("Size cannot be negative");

    v.freeMemory();
    v.allocate(size);

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < v.n; i++)
        in >> v.data[i];

    return in;
}

ostream& operator<<(ostream& out, const VectorN& v) {
    out << "[";
    for (int i = 0; i < v.n; i++)
    {
        out << v.data[i];
        if (i != v.n - 1)
            out << ", ";
    }
    out << "]";
    return out;
}

int operator*(const VectorN& left, const VectorN& right) {
    if (left.n != right.n)
        throw invalid_argument("Vectors must have the same size");

    int sum = 0;
    for (int i = 0; i < left.n; i++)
        sum += left.data[i] * right.data[i];

    return sum;
}