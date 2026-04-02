#pragma once
#include "Pair.h"
#include <string>
#include <iostream>

class Rectangle : public Pair
{
public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(const Rectangle& other);

    double GetWidth() const;
    double GetHeight() const;

    void SetWidth(double value);
    void SetHeight(double value);

    void Init(double width, double height);
    void Read();
    void Display() const;
    std::string toString() const;

    double Perimeter() const;
    double Area() const;

    Rectangle& operator=(const Rectangle& other);
    operator std::string() const;

    Rectangle& operator++();
    Rectangle operator++(int);
    Rectangle& operator--();
    Rectangle operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
    friend std::istream& operator>>(std::istream& in, Rectangle& r);
};