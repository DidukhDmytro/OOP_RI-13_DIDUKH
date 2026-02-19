#pragma once
#include <iostream>

class Circle
{
private:
    double x;
    double y;
    double R;

public:
    Circle();
    Circle(double x, double y, double R);

    double GetX() const;
    double GetY() const;
    double GetR() const;

    void SetX(double value);
    void SetY(double value);
    void SetR(double value);

    void Init(double x, double y, double R);

    void Read();
    void Display() const;

    double Area() const;
    double Circumference() const;
};

Circle makeCircle(double x, double y, double R);
