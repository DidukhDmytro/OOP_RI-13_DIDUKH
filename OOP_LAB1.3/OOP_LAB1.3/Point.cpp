#include "Point.h"
#include <cmath>
#include <sstream>

using namespace std;

// Конструктори
Point::Point() : x(0), y(0) {}

Point::Point(double xVal, double yVal)
{
    Init(xVal, yVal);
}

double Point::GetX() const { return x; }
double Point::GetY() const { return y; }

void Point::SetX(double value)
{
    x = value;
}

void Point::SetY(double value)
{
    y = value;
}

void Point::Init(double xVal, double yVal)
{
    SetX(xVal);
    SetY(yVal);
}

void Point::Read()
{
    cout << "Eter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}

void Point::Display() const
{
    cout << "Point: (" << x << ", " << y << ")" << endl;
}

string Point::toString() const
{
    stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

void Point::MoveX(double dx)
{
    x += dx;
}

void Point::MoveY(double dy)
{
    y += dy;
}

double Point::DistanceTo(const Point& other) const
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}
