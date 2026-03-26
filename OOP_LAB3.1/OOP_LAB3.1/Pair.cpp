#include "Pair.h"
#include <sstream>
#include <cstdlib>

Pair::Pair(const int x, const int y) {
    setA(x);
    setB(y);
}

Pair::Pair(const Pair& r) {
    a = r.a;
    b = r.b;
}

Pair::~Pair(void){}

void Pair::setA(const int value) {
    a = value;
}

void Pair::setB(const int value) {
    b = value;
}

int Pair::product() const {
    return a * b;
}

Pair operator + (const Pair& l, const Pair& r) {
    Pair t;
    t.a = l.a + r.a;
    t.b = l.b + r.b;
    return t;
}

Pair operator * (const Pair& l, const int k) {
    Pair t;
    t.a = l.a * k;
    t.b = l.b * k;
    return t;
}

Pair operator * (const int k, const Pair& r) {
    Pair t;
    t.a = r.a * k;
    t.b = r.b * k;
    return t;
}

Pair::operator string() const {
    stringstream ss;
    ss << "( " << getA() << ", " << getB() << " )";
    return ss.str();
}

ostream& operator << (ostream& out, const Pair& r) {
    return out << (string)r;
}

istream& operator >> (istream& in, Pair& r) {
    int a, b;
    cout << "a = "; in >> a;
    if (!in) {
        cerr << "Error: incorrect value for a." << endl;
        exit(1);
    }

    cout << "b = "; in >> b;
    if (!in) {
        cerr << "Error: incorrect value for b." << endl;
        exit(1);
    }

    r.setA(a);
    r.setB(b);
    return in;
}