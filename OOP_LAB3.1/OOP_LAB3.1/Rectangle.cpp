#include "Rectangle.h"
#include <sstream>
#include <cstdlib>

Rectangle::Rectangle(const int x, const int y) {
    setWidth(x);
    setHeight(y);
}

Rectangle::Rectangle(const Rectangle& r)
    : Pair(r) {}

Rectangle::~Rectangle(void){}

void Rectangle::setWidth(const int value) {
    if (value <= 0) {
        cerr << "Error: width must be greater than 0." << endl;
        exit(1);
    }
    setA(value);
}

void Rectangle::setHeight(const int value) {
    if (value <= 0) {
        cerr << "Error: height must be greater than 0." << endl;
        exit(1);
    }
    setB(value);
}

int Rectangle::perimeter() const {
    return 2 * (getWidth() + getHeight());
}

int Rectangle::area() const {
    return getWidth() * getHeight();
}

Rectangle::operator string() const {
    stringstream ss;
    ss << "Rectangle( " << getWidth() << ", " << getHeight() << " )";
    return ss.str();
}

ostream& operator << (ostream& out, const Rectangle& r) {
    return out << (string)r;
}

istream& operator >> (istream& in, Rectangle& r) {
    int x, y;
    cout << "width = "; in >> x;
    if (!in) {
        cerr << "Error: incorrect value for width." << endl;
        exit(1);
    }

    cout << "height = "; in >> y;
    if (!in) {
        cerr << "Error: incorrect value for height." << endl;
        exit(1);
    }

    r.setWidth(x);
    r.setHeight(y);
    return in;
}