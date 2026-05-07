#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

class Array {
public:
    typedef unsigned int UINT;
    typedef double value_type;
    typedef double* iterator;
    typedef const double* const_iterator;
    typedef double& reference;
    typedef const double& const_reference;
    typedef std::size_t size_type;

private:
    static const size_type minsize = 10;
    size_type Size;   // виділено пам'яті
    size_type Count;  // реальна кількість елементів
    size_type First;  // індекс початку
    value_type* elems;

public:
    Array(const size_type& n = minsize) throw(std::bad_alloc, std::invalid_argument);
    Array(const Array&) throw(std::bad_alloc);
    Array(const iterator first, const iterator last) throw(std::bad_alloc, std::invalid_argument);
    ~Array();

    Array& operator=(const Array&);

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems + Count; }
    const_iterator end() const { return elems + Count; }

    size_type size() const { return Count; }
    bool empty() const { return Count == 0; }
    size_type capacity() const { return Size; }
    void resize(size_type newsize) throw(std::bad_alloc);

    reference operator[](size_type) throw(std::out_of_range);
    const_reference operator[](size_type) const throw(std::out_of_range);

    void push_back(const value_type& v);
    void pop_back(); 
    void assign(const value_type& v); 
    void swap(Array& other);

    friend std::ostream& operator <<(std::ostream& out, const Array& a);
    friend std::istream& operator >>(std::istream& in, Array& a);
};