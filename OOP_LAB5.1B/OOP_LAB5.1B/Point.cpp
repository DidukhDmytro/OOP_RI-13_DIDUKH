#include "Point.h"
#include <cmath>
#include <stdexcept>

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) {
    if (!Init(x, y)) throw std::invalid_argument("Invalid coordinates");
}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

void Point::setX(double value) { x = value; }
void Point::setY(double value) { y = value; }

bool Point::Init(double x, double y) {
    if (std::abs(x) > 10000 || std::abs(y) > 10000) return false;
    this->x = x;
    this->y = y;
    return true;
}

void Point::Read() {
    double tx, ty;
    std::cout << "Enter x: "; std::cin >> tx;
    std::cout << "Enter y: "; std::cin >> ty;
    if (!Init(tx, ty)) throw std::runtime_error("Coordinates out of range!");
}

void Point::Display() const {
    std::cout << toString() << std::endl;
}

std::string Point::toString() const {
    std::stringstream ss;
    ss << "(" << x << "; " << y << ")";
    return ss.str();
}

void Point::moveX(double delta) { x += delta; }
void Point::moveY(double delta) { y += delta; }

double Point::distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

Point& Point::operator = (const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point::operator std::string() const {
    return toString();
}

Point& Point::operator ++ () { ++x; ++y; return *this; }
Point Point::operator ++ (int) { Point tmp(*this); ++x; ++y; return tmp; }
Point& Point::operator -- () { --x; --y; return *this; }
Point Point::operator -- (int) { Point tmp(*this); --x; --y; return tmp; }

std::ostream& operator << (std::ostream& out, const Point& p) {
    out << p.toString();
    return out;
}

std::istream& operator >> (std::istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

double operator - (const Point& p1, const Point& p2) {
    return Point::distance(p1, p2);
}