#include "RectanglePrivate.h"
#include <sstream>
#include <stdexcept>

RectanglePrivate::RectanglePrivate() : Pair() {}

RectanglePrivate::RectanglePrivate(double width, double height)
{
    Init(width, height);
}

RectanglePrivate::RectanglePrivate(const string& str) : Pair()
{
    size_t comma = str.find(',');
    if (comma == string::npos)
        throw invalid_argument("Invalid string format. Expected: width,height");

    string left = str.substr(0, comma);
    string right = str.substr(comma + 1);

    double w = ParseNumber(left);
    double h = ParseNumber(right);

    Init(w, h);
}

RectanglePrivate::RectanglePrivate(const RectanglePrivate& other) : Pair(other) {}

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
    Pair::SetFirst(value);
}

void RectanglePrivate::SetHeight(double value)
{
    if (value < 0)
        throw invalid_argument("Height must be non-negative");
    Pair::SetSecond(value);
}

void RectanglePrivate::Init(double width, double height)
{
    SetWidth(width);
    SetHeight(height);
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
    SetWidth(GetWidth() + 1);
    SetHeight(GetHeight() + 1);
    return *this;
}

RectanglePrivate RectanglePrivate::operator++(int)
{
    RectanglePrivate temp(*this);
    ++(*this);
    return temp;
}

RectanglePrivate& RectanglePrivate::operator--()
{
    SetWidth(GetWidth() - 1);
    SetHeight(GetHeight() - 1);
    return *this;
}

RectanglePrivate RectanglePrivate::operator--(int)
{
    RectanglePrivate temp(*this);
    --(*this);
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