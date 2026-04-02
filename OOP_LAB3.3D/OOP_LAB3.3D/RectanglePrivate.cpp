#include "RectanglePrivate.h"
#include <sstream>
#include <stdexcept>

RectanglePrivate::RectanglePrivate() : Pair() {}

RectanglePrivate::RectanglePrivate(double width, double height) : Pair(width, height)
{
    if (width < 0 || height < 0)
        throw invalid_argument("Rectangle sides must be non-negative");
}

RectanglePrivate::RectanglePrivate(const RectanglePrivate& other) : Pair(other) {}

void RectanglePrivate::Init(double width, double height)
{
    if (width < 0 || height < 0)
        throw invalid_argument("Rectangle sides must be non-negative");

    SetFirst(width);
    SetSecond(height);
}

void RectanglePrivate::Read()
{
    double w, h;
    cout << "width = ";
    cin >> w;
    cout << "height = ";
    cin >> h;
    Init(w, h);
}

void RectanglePrivate::Display() const
{
    cout << toString() << endl;
}

string RectanglePrivate::toString() const
{
    stringstream sout;
    sout << "RectanglePrivate(width = " << GetWidth()
        << ", height = " << GetHeight()
        << ", perimeter = " << Perimeter()
        << ", area = " << Area() << ")";
    return sout.str();
}

double RectanglePrivate::GetWidth() const
{
    return GetFirst();
}

double RectanglePrivate::GetHeight() const
{
    return GetSecond();
}

void RectanglePrivate::SetWidth(double value)
{
    if (value < 0)
        throw invalid_argument("Width must be non-negative");
    SetFirst(value);
}

void RectanglePrivate::SetHeight(double value)
{
    if (value < 0)
        throw invalid_argument("Height must be non-negative");
    SetSecond(value);
}

double RectanglePrivate::Perimeter() const
{
    return 2 * (GetWidth() + GetHeight());
}

double RectanglePrivate::Area() const
{
    return GetWidth() * GetHeight();
}

double RectanglePrivate::Product() const
{
    return Pair::Product();
}

RectanglePrivate& RectanglePrivate::operator=(const RectanglePrivate& other)
{
    if (this != &other)
        Pair::operator=(other);
    return *this;
}

RectanglePrivate::operator string() const
{
    return toString();
}

RectanglePrivate& RectanglePrivate::operator++()
{
    Pair::operator++();
    return *this;
}

RectanglePrivate RectanglePrivate::operator++(int)
{
    RectanglePrivate temp(*this);
    Pair::operator++(0);
    return temp;
}

RectanglePrivate& RectanglePrivate::operator--()
{
    Pair::operator--();
    return *this;
}

RectanglePrivate RectanglePrivate::operator--(int)
{
    RectanglePrivate temp(*this);
    Pair::operator--(0);
    return temp;
}

ostream& operator<<(ostream& out, const RectanglePrivate& r)
{
    out << r.toString();
    return out;
}

istream& operator>>(istream& in, RectanglePrivate& r)
{
    double w, h;
    cout << "Enter width: ";
    in >> w;
    cout << "Enter height: ";
    in >> h;
    r.Init(w, h);
    return in;
}