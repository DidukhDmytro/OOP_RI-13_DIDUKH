#pragma once
#include <iostream>
#include <string>

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);

    double GetX() const;
    double GetY() const;

    void SetX(double value);
    void SetY(double value);

    void Init(double x, double y);
    std::string toString() const;

    void MoveX(double dx);
    void MoveY(double dy);
    double DistanceTo(const Point& other) const;

    Point& operator=(const Point& other);

    // унарний мінус
    Point operator-() const;

    // Інкремент / декремент
    Point& operator++();     // префіксний ++
    Point operator++(int);   // постфіксний ++
    Point& operator--();     // префіксний --
    Point operator--(int);   // постфіксний --

    operator std::string() const;

    friend std::istream& operator>>(std::istream& in, Point& p);
    friend std::ostream& operator<<(std::ostream& out, const Point& p);

    friend Point operator+(const Point& p, double value);  
    friend Point operator+(double value, const Point& p);
    friend double operator-(const Point& p1, const Point& p2); // відстань між точками
};