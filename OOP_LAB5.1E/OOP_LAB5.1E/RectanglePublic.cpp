#include "RectanglePublic.h"
#include <sstream>
#include <stdexcept>

RectanglePublic::RectanglePublic() : Pair() {}

RectanglePublic::RectanglePublic(double width, double height)
{
    Init(width, height);
}

RectanglePublic::RectanglePublic(const string& str) : Pair()
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

RectanglePublic::RectanglePublic(const RectanglePublic& other) : Pair(other) {}

double RectanglePublic::GetWidth() const
{
    return GetFirst();
}

double RectanglePublic::GetHeight() const
{
    return GetSecond();
}

void RectanglePublic::SetWidth(double value)
{
    if (value < 0)
        throw invalid_argument("Width must be non-negative");
    Pair::SetFirst(value);
}

void RectanglePublic::SetHeight(double value)
{
    if (value < 0)
        throw invalid_argument("Height must be non-negative");
    Pair::SetSecond(value);
}

void RectanglePublic::Init(double width, double height)
{
    SetWidth(width);
    SetHeight(height);
}

void RectanglePublic::Read()
{
    double w, h;
    cout << "width = ";
    cin >> w;
    cout << "height = ";
    cin >> h;
    Init(w, h);
}

void RectanglePublic::Display() const
{
    cout << toString() << endl;
}

string RectanglePublic::toString() const
{
    stringstream sout;
    sout << "RectanglePublic(width = " << GetWidth()
        << ", height = " << GetHeight()
        << ", perimeter = " << Perimeter()
        << ", area = " << Area() << ")";
    return sout.str();
}

double RectanglePublic::Perimeter() const
{
    return 2 * (GetWidth() + GetHeight());
}

double RectanglePublic::Area() const
{
    return GetWidth() * GetHeight();
}

RectanglePublic& RectanglePublic::operator=(const RectanglePublic& other)
{
    if (this != &other)
        Pair::operator=(other);
    return *this;
}

RectanglePublic::operator string() const
{
    return toString();
}

RectanglePublic& RectanglePublic::operator++()
{
    SetWidth(GetWidth() + 1);
    SetHeight(GetHeight() + 1);
    return *this;
}

RectanglePublic RectanglePublic::operator++(int)
{
    RectanglePublic temp(*this);
    ++(*this);
    return temp;
}

RectanglePublic& RectanglePublic::operator--()
{
    SetWidth(GetWidth() - 1);
    SetHeight(GetHeight() - 1);
    return *this;
}

RectanglePublic RectanglePublic::operator--(int)
{
    RectanglePublic temp(*this);
    --(*this);
    return temp;
}

ostream& operator<<(ostream& out, const RectanglePublic& r)
{
    out << r.toString();
    return out;
}

istream& operator>>(istream& in, RectanglePublic& r)
{
    double w, h;
    cout << "Enter width: ";
    in >> w;
    cout << "Enter height: ";
    in >> h;
    r.Init(w, h);
    return in;
}