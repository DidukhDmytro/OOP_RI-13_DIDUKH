#include "RectanglePublic.h"
#include <sstream>
#include <stdexcept>

RectanglePublic::RectanglePublic() : Pair() {}

RectanglePublic::RectanglePublic(double width, double height) : Pair(width, height)
{
    if (width < 0 || height < 0)
        throw invalid_argument("Rectangle sides must be non-negative");
}

RectanglePublic::RectanglePublic(const RectanglePublic& other) : Pair(other) {}

void RectanglePublic::Init(double width, double height)
{
    if (width < 0 || height < 0)
        throw invalid_argument("Rectangle sides must be non-negative");

    SetFirst(width);
    SetSecond(height);
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
    sout << "RectanglePublic(width = " << GetFirst()
        << ", height = " << GetSecond()
        << ", perimeter = " << Perimeter()
        << ", area = " << Area() << ")";
    return sout.str();
}

double RectanglePublic::Perimeter() const
{
    return 2 * (GetFirst() + GetSecond());
}

double RectanglePublic::Area() const
{
    return GetFirst() * GetSecond();
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
    Pair::operator++();
    return *this;
}

RectanglePublic RectanglePublic::operator++(int)
{
    RectanglePublic temp(*this);
    Pair::operator++(0);
    return temp;
}

RectanglePublic& RectanglePublic::operator--()
{
    Pair::operator--();
    return *this;
}

RectanglePublic RectanglePublic::operator--(int)
{
    RectanglePublic temp(*this);
    Pair::operator--(0);
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