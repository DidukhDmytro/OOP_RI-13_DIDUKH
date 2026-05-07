#include "Money.h"

void Money::checkNominal(int value) const {
    int valid[] = { 1,2,5,10,20,50,100,200,500 };
    bool ok = false;
    for (int v : valid) {
        if (v == value) ok = true;
    }
    if (!ok) throw bad_exception();
}

void Money::checkCount(int value) const {
    if (value <= 0) throw invalid_argument("Count must be positive");
}

Money::Money() : first(1), second(1) {}

Money::Money(int f, int s) {
    Init(f, s);
}

Money::Money(const Money& other) {
    first = other.first;
    second = other.second;
}

int Money::getFirst() const { return first; }
int Money::getSecond() const { return second; }

void Money::setFirst(int value) {
    checkNominal(value);
    first = value;
}

void Money::setSecond(int value) {
    checkCount(value);
    second = value;
}

void Money::Init(int f, int s) {
    setFirst(f);
    setSecond(s);
}

void Money::Read() {
    cin >> *this;
}

void Money::Display() const {
    cout << *this << endl;
}

int Money::summa() const {
    return first * second;
}

Money::operator string() const {
    return "Nominal: " + to_string(first) +
        ", Count: " + to_string(second);
}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Money& Money::operator++() {
    ++first;
    return *this;
}

Money Money::operator++(int) {
    Money temp(*this);
    second++;
    return temp;
}

Money& Money::operator--() {
    --first;
    return *this;
}

Money Money::operator--(int) {
    Money temp(*this);
    second--;
    return temp;
}

istream& operator>>(istream& in, Money& m) {
    int f, s;
    cout << "Nominal: ";
    in >> f;
    cout << "Count: ";
    in >> s;

    m.Init(f, s);
    return in;
}

ostream& operator<<(ostream& out, const Money& m) {
    out << "Nominal = " << m.first
        << ", Count = " << m.second
        << ", Sum = " << m.summa();
    return out;
}

Money makeMoney(int f, int s) {
    try {
        return Money(f, s);
    }
    catch (...) {
        cout << "Error creating Money object\n";
        exit(1);
    }
}