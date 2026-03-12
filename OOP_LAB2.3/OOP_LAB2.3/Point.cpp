#include "Point.h"
#include <sstream>

using namespace std;

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double xVal, double yVal){
    Init(xVal, yVal);
}

Point::Point(const Point& other){
    x = other.x;
    y = other.y;
}

double Point::GetX() const{
    return x;
}

double Point::GetY() const{
    return y;
}

void Point::SetX(double value){
    x = value;
}

void Point::SetY(double value){
    y = value;
}

void Point::Init(double xVal, double yVal){
    SetX(xVal);
    SetY(yVal);
}

void Point::MoveX(double dx){
    x += dx;
}

void Point::MoveY(double dy){
    y += dy;
}

double Point::DistanceTo(const Point& other) const{
    return sqrt((x - other.x) * (x - other.x) +
        (y - other.y) * (y - other.y));
}

string Point::toString() const{
    stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

Point::operator std::string() const{
    return toString();
}

Point& Point::operator=(const Point& other){
    if (this != &other){
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point Point::operator-() const{
    return Point(-x, -y);           // унарний мінус
}

Point& Point::operator++(){
    ++x;
    ++y;
    return *this;
}

Point Point::operator++(int){
    Point temp(*this);
    x++;
    y++;
    return temp;
}

Point& Point::operator--(){
    --x;
    --y;
    return *this;
}

Point Point::operator--(int){
    Point temp(*this);
    x--;
    y--;
    return temp;
}

istream& operator>>(istream& in, Point& p){
    cout << "Enter x: ";
    in >> p.x;
    cout << "Enter y: ";
    in >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const Point& p){
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

Point operator+(const Point& p, double value){
    return Point(p.x + value, p.y + value);
}

Point operator+(double value, const Point& p){
    return Point(p.x + value, p.y + value);
}

double operator-(const Point& p1, const Point& p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y));
}