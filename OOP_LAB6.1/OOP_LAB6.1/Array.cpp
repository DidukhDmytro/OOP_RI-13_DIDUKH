#include "Array.h"
#include <algorithm>

Array::Array(const size_type& n) throw(std::bad_alloc, std::invalid_argument) {
    First = 0;
    Count = n;
    Size = (n > minsize) ? n : minsize;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++) elems[i] = 0;
}

Array::Array(const Array& t) throw(std::bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[t.Size]) {
    for (UINT i = 0; i < Size; ++i) elems[i] = t.elems[i];
}

Array::~Array() {
    delete[] elems;
}

void Array::push_back(const value_type& v) {
    if (Count == Size) resize(Size * 2);
    elems[Count++] = v;
}

void Array::pop_back() {
    if (Count > 0) Count--;
}

void Array::assign(const value_type& v) {
    for (size_type i = 0; i < Count; i++) elems[i] = v;
}

void Array::resize(size_type newsize) throw(std::bad_alloc) {
    if (newsize > Size) {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i) data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

Array::reference Array::operator [](size_type index) throw(std::out_of_range) {
    if (index < Count) return elems[index];
    throw std::out_of_range("Index out of range!");
}

Array::const_reference Array::operator [](size_type index) const throw(std::out_of_range) {
    if (index < Count) return elems[index];
    throw std::out_of_range("Index out of range!");
}

void Array::swap(Array& other) {
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
    std::swap(Count, other.Count);
}

Array& Array::operator=(const Array& t) {
    Array tmp(t);
    swap(tmp);
    return *this;
}

std::ostream& operator <<(std::ostream& out, const Array& tmp) {
    for (size_t j = 0; j < tmp.Count; j++)
        out << tmp.elems[j] << " ";
    return out;
}