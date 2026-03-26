#pragma once
#include "Pair.h"

class Rectangle : public Pair
{
public:
    Rectangle(const int x = 1, const int y = 1);
    Rectangle(const Rectangle& r);
    ~Rectangle(void);

    int getWidth() const {
        return getA(); 
    }
    int getHeight() const { 
        return getB();
    }

    void setWidth(const int value);
    void setHeight(const int value);

    int perimeter() const;
    int area() const;

    operator string() const;
    friend ostream& operator << (ostream& out, const Rectangle& r);
    friend istream& operator >> (istream& in, Rectangle& r);
};