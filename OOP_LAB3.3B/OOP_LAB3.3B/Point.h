#pragma once
#include "Pair.h"

class Point : public Pair
{
public:
    Point();
    Point(double x, double y);
    Point(const Point& other);

    double GetX() const;
    double GetY() const;

    void SetX(double value);
    void SetY(double value);

    void Init(double x, double y);

    void MoveX(double dx);
    void MoveY(double dy);
    double DistanceTo(const Point& other) const;

    Point& operator=(const Point& other);

    Point operator-() const;

    Point& operator++();
    Point operator++(int);
    Point& operator--();
    Point operator--(int);

    operator std::string() const;

    friend Point operator+(const Point& p, double value);
    friend Point operator+(double value, const Point& p);
    friend double operator-(const Point& p1, const Point& p2);
};

Point makePoint(double x, double y);