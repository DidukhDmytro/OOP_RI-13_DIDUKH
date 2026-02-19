#pragma once
#include <iostream>
#include <string>

class Point
{
private:
    double x;
    double y;

public:
    // Конструктори
    Point();
    Point(double x, double y);

    double GetX() const;
    double GetY() const;

    void SetX(double value);
    void SetY(double value);

    void Init(double x, double y);

    void Read();
    void Display() const;
    std::string toString() const;

    void MoveX(double dx);
    void MoveY(double dy);
    double DistanceTo(const Point& other) const;
};
