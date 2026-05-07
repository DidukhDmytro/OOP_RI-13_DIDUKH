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

Rectangle::Rectangle(const std::string& str) : Pair()
{
    size_t comma = str.find(',');
    if (comma == std::string::npos)
        throw std::invalid_argument("Invalid string format. Expected: width,height");

    std::string left = str.substr(0, comma);
    std::string right = str.substr(comma + 1);

    double w = ParseNumber(left);
    double h = ParseNumber(right);

    Init(w, h);
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
    Pair::SetFirst(value);
}

void Rectangle::SetHeight(double value)
{
    if (value < 0)
        throw std::invalid_argument("Height must be non-negative");
    Pair::SetSecond(value);
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
    SetWidth(GetWidth() + 1);
    SetHeight(GetHeight() + 1);
    return *this;
}

Rectangle Rectangle::operator++(int)
{
    Rectangle temp(*this);
    ++(*this);
    return temp;
}

Rectangle& Rectangle::operator--()
{
    SetWidth(GetWidth() - 1);
    SetHeight(GetHeight() - 1);
    return *this;
}

Rectangle Rectangle::operator--(int)
{
    Rectangle temp(*this);
    --(*this);
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