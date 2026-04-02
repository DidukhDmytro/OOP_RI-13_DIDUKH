#pragma once
#include "Pair.h"

class RectanglePrivate : private Pair
{
public:
    RectanglePrivate();
    RectanglePrivate(double width, double height);
    RectanglePrivate(const RectanglePrivate& other);

    void Init(double width, double height);
    void Read();
    void Display() const;
    string toString() const;

    double GetWidth() const;
    double GetHeight() const;
    void SetWidth(double value);
    void SetHeight(double value);

    double Perimeter() const;
    double Area() const;
    double Product() const;

    RectanglePrivate& operator=(const RectanglePrivate& other);
    operator string() const;

    RectanglePrivate& operator++();
    RectanglePrivate operator++(int);
    RectanglePrivate& operator--();
    RectanglePrivate operator--(int);

    friend ostream& operator<<(ostream& out, const RectanglePrivate& r);
    friend istream& operator>>(istream& in, RectanglePrivate& r);
};