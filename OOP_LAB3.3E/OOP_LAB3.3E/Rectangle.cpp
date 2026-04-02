#include "Rectangle.h"
#include <sstream>
#include <stdexcept>

Rectangle::Rectangle() : Pair()
{
}

Rectangle::Rectangle(double width, double height) : Pair()
{
    Init(width, height);
}

Rectangle::Rectangle(const Rectangle& other) : Pair(other)
{
}

double Rectangle::GetWidth() const
{
    return GetFirst();
}

double Rectangle::GetHeight() const
{
    return GetSecond();
}

void Rectangle::SetWidth(double value)
{
    if (value < 0)
        throw std::invalid_argument("Width must be non-negative");
    SetFirst(value);
}

void Rectangle::SetHeight(double value)
{
    if (value < 0)
        throw std::invalid_argument("Height must be non-negative");
    SetSecond(value);
}

void Rectangle::Init(double width, double height)
{
    SetWidth(width);
    SetHeight(height);
}

void Rectangle::Read()
{
    double w, h;
    std::cout << "width = ";
    std::cin >> w;
    std::cout << "height = ";
    std::cin >> h;
    Init(w, h);
}

void Rectangle::Display() const
{
    std::cout << toString() << std::endl;
}

std::string Rectangle::toString() const
{
    std::ostringstream sout;
    sout << "Rectangle(width = " << GetWidth()
        << ", height = " << GetHeight()
        << ", perimeter = " << Perimeter()
        << ", area = " << Area() << ")";
    return sout.str();
}

double Rectangle::Perimeter() const
{
    return 2 * (GetWidth() + GetHeight());
}

double Rectangle::Area() const
{
    return GetWidth() * GetHeight();
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other)
    {
        Pair::operator=(other);
    }
    return *this;
}

Rectangle::operator std::string() const
{
    return toString();
}

Rectangle& Rectangle::operator++()
{
    Pair::operator++();
    return *this;
}

Rectangle Rectangle::operator++(int)
{
    Rectangle temp(*this);
    Pair::operator++();
    return temp;
}

Rectangle& Rectangle::operator--()
{
    Pair::operator--();
    return *this;
}

Rectangle Rectangle::operator--(int)
{
    Rectangle temp(*this);
    Pair::operator--();
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r)
{
    out << r.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Rectangle& r)
{
    double w, h;
    std::cout << "Enter width: ";
    in >> w;
    std::cout << "Enter height: ";
    in >> h;
    r.Init(w, h);
    return in;
}