#pragma once
#include "Pair.h"

class RectanglePublic : public Pair
{
public:
    RectanglePublic();
    RectanglePublic(double width, double height);
    RectanglePublic(const RectanglePublic& other);

    void Init(double width, double height);
    void Read();
    void Display() const;
    string toString() const;

    double Perimeter() const;
    double Area() const;

    RectanglePublic& operator=(const RectanglePublic& other);
    operator string() const;

    RectanglePublic& operator++();
    RectanglePublic operator++(int);
    RectanglePublic& operator--();
    RectanglePublic operator--(int);

    friend ostream& operator<<(ostream& out, const RectanglePublic& r);
    friend istream& operator>>(istream& in, RectanglePublic& r);
};