#include "Point.h"
#include <cmath>
#include <sstream>

using namespace std;

Point::Point() : Pair()
{
}

Point::Point(double x, double y) : Pair(x, y)
{
}

Point::Point(const Point& other) : Pair(other)
{
}

double Point::GetX() const
{
    return GetFirst();
}

double Point::GetY() const
{
    return GetSecond();
}

void Point::SetX(double value)
{
    SetFirst(value);
}

void Point::SetY(double value)
{
    SetSecond(value);
}

void Point::Init(double x, double y)
{
    Pair::Init(x, y);
}

void Point::MoveX(double dx)
{
    SetX(GetX() + dx);
}

void Point::MoveY(double dy)
{
    SetY(GetY() + dy);
}

double Point::DistanceTo(const Point& other) const
{
    return sqrt((GetX() - other.GetX()) * (GetX() - other.GetX()) +
        (GetY() - other.GetY()) * (GetY() - other.GetY()));
}

Point& Point::operator=(const Point& other)
{
    if (this != &other)
    {
        Pair::operator=(other);
    }
    return *this;
}

Point Point::operator-() const
{
    return Point(-GetX(), -GetY());
}

Point& Point::operator++()
{
    SetX(GetX() + 1);
    SetY(GetY() + 1);
    return *this;
}

Point Point::operator++(int)
{
    Point temp(*this);
    SetX(GetX() + 1);
    SetY(GetY() + 1);
    return temp;
}

Point& Point::operator--()
{
    SetX(GetX() - 1);
    SetY(GetY() - 1);
    return *this;
}

Point Point::operator--(int)
{
    Point temp(*this);
    SetX(GetX() - 1);
    SetY(GetY() - 1);
    return temp;
}

Point::operator string() const
{
    stringstream ss;
    ss << "(" << GetX() << ", " << GetY() << ")";
    return ss.str();
}

Point operator+(const Point& p, double value)
{
    return Point(p.GetX() + value, p.GetY() + value);
}

Point operator+(double value, const Point& p)
{
    return Point(p.GetX() + value, p.GetY() + value);
}

double operator-(const Point& p1, const Point& p2)
{
    return sqrt((p1.GetX() - p2.GetX()) * (p1.GetX() - p2.GetX()) +
        (p1.GetY() - p2.GetY()) * (p1.GetY() - p2.GetY()));
}

Point makePoint(double x, double y)
{
    return Point(x, y);
}